//-----------------------------------------------------------------------------
#include "PrecompiledHeader.h"
#include "sm.h"
//-----------------------------------------------------------------------------
#include <stdlib.h>
#include <math.h>

#ifdef S3DX_DLL
	smAPI sm ;
#endif

    char buf[512];
    int res = 0;

//-----------------------------------------------------------------------------
//  Callbacks
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------

int Callback_sm_calculateDouble ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "sm.calculateDouble" ) ;

    // Input Parameters
    int iInputCount = 0 ;
    S3DX::AIVariable sNum1 = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;
    S3DX::AIVariable sNum2 = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;
    S3DX::AIVariable kOperation = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable sResult ;


    const char* ca = sNum1.GetStringValue();
    const char* cb = sNum2.GetStringValue();
    int op = kOperation.GetNumberValue();

    auto na = strtod(ca, nullptr);
    auto nb = strtod(cb, nullptr);

    switch (op)
    {
    case 0:
        sprintf(buf, "%f", na + nb);
        break;
    case 1:
        sprintf(buf, "%f", na - nb);
        break;
    case 2:
        sprintf(buf, "%f", na * nb);
        break;
    case 3:
        sprintf(buf, "%f", na / nb);
        break;
    case 4:
        sprintf(buf, "%f",pow(na, nb));
        break;
    default:
        sprintf(buf, "%f", 0.f);
        break;
    }

    sResult.SetStringValue(buf);


    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = sResult ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_sm_calculateSignedLong ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "sm.calculateSignedLong" ) ;

    // Input Parameters
    int iInputCount = 0 ;
    S3DX::AIVariable sNum1 = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;
    S3DX::AIVariable sNum2 = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;
    S3DX::AIVariable kOperation = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable sResult ;


    const char* ca = sNum1.GetStringValue();
    const char* cb = sNum2.GetStringValue();
    int op = kOperation.GetNumberValue();

    auto na = strtoll(ca, nullptr, 10);
    auto nb = strtoll(cb, nullptr, 10);

    switch (op)
    {
    case 0:
        sprintf(buf, "%lld", na + nb);
        break;
    case 1:
        sprintf(buf, "%lld", na - nb);
        break;
    case 2:
        sprintf(buf, "%lld", na * nb);
        break;
    case 3:
        sprintf(buf, "%lld", na / nb);
        break;
    case 4:
        if (nb == 0) {
            sprintf(buf, "%lld", 1LL);
            break;
        }
        else if (nb > 0) {
            auto result = na;
            for (long long i = 1; i < nb; ++i) {
                result *= na;
            }
            sprintf(buf, "%lld", result);
            break;
        }
        else if (nb < 0) {
            // error: would require double return type
            sprintf(buf, "%lld", 0LL);
            break;
        }
    default:
        sprintf(buf, "%lld", 0LL);
        break;
    }

    sResult.SetStringValue(buf);


    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = sResult ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------

int Callback_sm_calculateUnsignedLong ( int _iInCount, const S3DX::AIVariable *_pIn, S3DX::AIVariable *_pOut )
{
    S3DX_API_PROFILING_START( "sm.calculateUnsignedLong" ) ;

    // Input Parameters
    int iInputCount = 0 ;
    S3DX::AIVariable sNum1 = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;
    S3DX::AIVariable sNum2 = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;
    S3DX::AIVariable kOperation = ( iInputCount < _iInCount ) ? _pIn[iInputCount++] : S3DX::AIVariable ( ) ;

    // Output Parameters 
    S3DX::AIVariable sResult ;


    const char* ca = sNum1.GetStringValue();
    const char* cb = sNum2.GetStringValue();
    int op = kOperation.GetNumberValue();

    auto na = strtoull(ca, nullptr, 10);
    auto nb = strtoull(cb, nullptr, 10);

    switch (op)
    {
    case 0:
        sprintf(buf, "%llu", na + nb);
        break;
    case 1:
        sprintf(buf, "%llu", na - nb);
        break;
    case 2:
        sprintf(buf, "%llu", na * nb);
        break;
    case 3:
        sprintf(buf, "%llu", na / nb);
        break;
    case 4:
        if (nb == 0) {
            sprintf(buf, "%llu", 1ULL);
            break;
        }
        else if (nb > 0) {
            auto result = na;
            for (unsigned long long i = 1; i < nb; ++i) {
                result *= na;
            }
            sprintf(buf, "%llu", result);
            break;
        }
    default:
        sprintf(buf, "%llu", 0ULL);
        break;
    }

    sResult.SetStringValue(buf);


    // Return output Parameters 
    int iReturnCount = 0 ;
    _pOut[iReturnCount++] = sResult ;

    S3DX_API_PROFILING_STOP( ) ;
    return iReturnCount;
}

//-----------------------------------------------------------------------------
//  Constructor / Destructor
//-----------------------------------------------------------------------------

smPackage::smPackage ( )
{
#ifdef S3DX_DLL
	
    sm.kAdd = 0 ;
    sm.kSubtract = 1 ;
    sm.kMultiply = 2 ;
    sm.kDivide = 3 ;
    sm.pfn_sm_calculateDouble = Callback_sm_calculateDouble ;
    sm.pfn_sm_calculateSignedLong = Callback_sm_calculateSignedLong ;
    sm.pfn_sm_calculateUnsignedLong = Callback_sm_calculateUnsignedLong ;

    sm.kPow = 4 ;

#endif
}

//-----------------------------------------------------------------------------

smPackage::~smPackage ( )
{

}

//-----------------------------------------------------------------------------
//  Functions table
//-----------------------------------------------------------------------------

static S3DX::AIFunction aMyFunctions [ ] =
{
    { "calculateDouble", Callback_sm_calculateDouble, "sResult", "sNum1, sNum2, kOperation", "does math with 2 float strings", 0 },
    { "calculateSignedLong", Callback_sm_calculateSignedLong, "sResult", "sNum1, sNum2, kOperation", "does math with 2 signed long int strings", 0 },
    { "calculateUnsignedLong", Callback_sm_calculateUnsignedLong, "sResult", "sNum1, sNum2, kOperation", "does math with 2 unsigned long int strings", 0 }
    //{ NULL, NULL, NULL, NULL, NULL, 0}
} ;

//-----------------------------------------------------------------------------
//  Constants table
//-----------------------------------------------------------------------------

static S3DX::AIConstant aMyConstants [ ] =
{
	{ "kAdd", 0, "basic addition", 0 },
    { "kSubtract", 1, "basic subtraction", 0 },
    { "kMultiply", 2, "basic multiplication", 0 },
    { "kDivide", 3, "basic division", 0 },
    { "kPow", 4, "raises num1 to the power of num2", 0 }
    //{ NULL, 0, NULL, 0}
} ;

//-----------------------------------------------------------------------------
//  Accessors
//-----------------------------------------------------------------------------

const char *smPackage::GetName ( ) const
{
    return "sm" ;
}

//-----------------------------------------------------------------------------

S3DX::uint32 smPackage::GetFunctionCount ( ) const
{
	if ( aMyFunctions[0].pName == NULL )
	{
		return 0 ;
	}
	else
	{
		return sizeof( aMyFunctions ) / sizeof( S3DX::AIFunction ) ;
	}
}

//-----------------------------------------------------------------------------

S3DX::uint32 smPackage::GetConstantCount ( ) const
{
	if ( aMyConstants[0].pName == NULL )
	{
		return 0 ;
	}
	else
	{
		return sizeof( aMyConstants ) / sizeof( S3DX::AIConstant ) ;
	}
}

//-----------------------------------------------------------------------------

const S3DX::AIFunction *smPackage::GetFunctionAt ( S3DX::uint32 _iIndex ) const
{
    return &aMyFunctions[ _iIndex ] ;
}

//-----------------------------------------------------------------------------

const S3DX::AIConstant *smPackage::GetConstantAt ( S3DX::uint32 _iIndex ) const
{
    return &aMyConstants[ _iIndex ] ;
}
