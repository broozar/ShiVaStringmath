//-----------------------------------------------------------------------------
#ifndef __sm_h__
#define __sm_h__
//-----------------------------------------------------------------------------
#include "S3DXAIPackage.h"
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Package declaration
//-----------------------------------------------------------------------------
class smPackage : public S3DX::AIPackage
{
public :

    //-------------------------------------------------------------------------
    //  Constructor / Destructor
	//-------------------------------------------------------------------------

                                smPackage         ( ) ;
                               ~smPackage         ( ) ;

	//-------------------------------------------------------------------------
    //  Accessors
	//-------------------------------------------------------------------------

    const   char               *GetName             ( ) const ;
            S3DX::uint32        GetFunctionCount    ( ) const ;
            S3DX::uint32        GetConstantCount    ( ) const ;
    const   S3DX::AIFunction   *GetFunctionAt       ( S3DX::uint32 _iIndex ) const ;
    const   S3DX::AIConstant   *GetConstantAt       ( S3DX::uint32 _iIndex ) const ;

} ;

//-----------------------------------------------------------------------------
// Package API declaration
//-----------------------------------------------------------------------------
class smAPI
{
public :

    //-------------------------------------------------------------------------
    //  API Constructor
	//-------------------------------------------------------------------------
                                smAPI       ( ) 
                                {
                                    pfn_sm_calculateUnsignedLong = NULL ;
                                    pfn_sm_calculateSignedLong = NULL ;
                                    pfn_sm_calculateDouble = NULL ;

                                }

	//-------------------------------------------------------------------------
	//  API Callbacks 
	//-------------------------------------------------------------------------

    S3DX::AICallback    pfn_sm_calculateUnsignedLong ;
    S3DX::AICallback    pfn_sm_calculateSignedLong ;
    S3DX::AICallback    pfn_sm_calculateDouble ;

	//-------------------------------------------------------------------------
	//  API Functions 
	//-------------------------------------------------------------------------

    inline S3DX::AIVariable     calculateUnsignedLong ( const S3DX::AIVariable& sNum1, const S3DX::AIVariable& sNum2, const S3DX::AIVariable& kOperation ) { S3DX_DECLARE_VIN_03( sNum1, sNum2, kOperation ) ; S3DX::AIVariable vOut ; if ( pfn_sm_calculateUnsignedLong ) pfn_sm_calculateUnsignedLong ( 3, vIn, &vOut ); return vOut ; }
    inline S3DX::AIVariable     calculateSignedLong ( const S3DX::AIVariable& sNum1, const S3DX::AIVariable& sNum2, const S3DX::AIVariable& kOperation ) { S3DX_DECLARE_VIN_03( sNum1, sNum2, kOperation ) ; S3DX::AIVariable vOut ; if ( pfn_sm_calculateSignedLong ) pfn_sm_calculateSignedLong ( 3, vIn, &vOut ); return vOut ; }
    inline S3DX::AIVariable     calculateDouble ( const S3DX::AIVariable& sNum1, const S3DX::AIVariable& sNum2, const S3DX::AIVariable& kOperation ) { S3DX_DECLARE_VIN_03( sNum1, sNum2, kOperation ) ; S3DX::AIVariable vOut ; if ( pfn_sm_calculateDouble ) pfn_sm_calculateDouble ( 3, vIn, &vOut ); return vOut ; }

 	//-------------------------------------------------------------------------
	//  API Constants 
	//-------------------------------------------------------------------------

    S3DX::AIVariable kPow ; 
    S3DX::AIVariable kDivide ; 
    S3DX::AIVariable kMultiply ; 
    S3DX::AIVariable kSubtract ; 
    S3DX::AIVariable kAdd ; 

} ;

extern smAPI sm;

//-----------------------------------------------------------------------------
#endif
//-----------------------------------------------------------------------------
