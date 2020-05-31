//-----------------------------------------------------------------------------
#include "PrecompiledHeader.h"
//-----------------------------------------------------------------------------
#include <string.h>
//-----------------------------------------------------------------------------
S3DX_IMPLEMENT_AIVARIABLE_STRING_POOL   ( 524288 ) ;
S3DX_IMPLEMENT_AIENGINEAPI              ( StringMath ) ;
S3DX_IMPLEMENT_PLUGIN                   ( StringMath ) ;

//-----------------------------------------------------------------------------
//  AI Packages
//-----------------------------------------------------------------------------
//@@Begin of AI Package include@@
#include "sm.h"
//@@End of AI Package include@@
//-----------------------------------------------------------------------------
//  Constructor / Destructor
//-----------------------------------------------------------------------------

StringMath::StringMath ( )
{
    S3DX_REGISTER_PLUGIN  ( "com.shivatech.stringmath" ) ;
    aContentsDirectory[0] = '\0' ;
	
	//Instanciate AI Packages
    S3DX::uint32 iAIPackageIndex = 0 ;
    
    //@@Begin of AI Package declaration@@
	if ( iAIPackageIndex < PLUGIN_AIPACKAGES_COUNT ) aAIPackages [iAIPackageIndex++] = new smPackage ( ) ;
    //@@End of AI Package declaration@@

	for ( ; iAIPackageIndex < PLUGIN_AIPACKAGES_COUNT; iAIPackageIndex ++ )
	{
        aAIPackages[iAIPackageIndex] = NULL  ;		
	}

}

//-----------------------------------------------------------------------------

StringMath::~StringMath ( )
{
	for ( S3DX::uint32 iAIPackageIndex = 0 ; iAIPackageIndex < PLUGIN_AIPACKAGES_COUNT; iAIPackageIndex ++ )
	{
		if ( aAIPackages [iAIPackageIndex] )
		{
			delete aAIPackages [iAIPackageIndex] ; 
			aAIPackages[iAIPackageIndex] = NULL  ;
		}
	}
}


//-----------------------------------------------------------------------------
//  Plugin content directory
//-----------------------------------------------------------------------------

        void                    StringMath::SetContentsDirectory  ( const char *_pDirectory ) { strcpy ( aContentsDirectory, _pDirectory ) ; }

//-----------------------------------------------------------------------------
//  AI packages
//-----------------------------------------------------------------------------

        S3DX::uint32            StringMath::GetAIPackageCount     ( )                      const { return PLUGIN_AIPACKAGES_COUNT ; }
const   S3DX::AIPackage        *StringMath::GetAIPackageAt        ( S3DX::uint32 _iIndex ) const { return (_iIndex < PLUGIN_AIPACKAGES_COUNT) ? aAIPackages[_iIndex] : NULL ; }


//-----------------------------------------------------------------------------
//  Engine Events
//-----------------------------------------------------------------------------


void StringMath::OnEngineEvent ( S3DX::uint32 _iEventCode, S3DX::uint32 _iArgumentCount, S3DX::AIVariable *_pArguments )
{
    switch ( _iEventCode )
    {
    case eEngineEventApplicationStart  : break ;
    case eEngineEventApplicationPause  : break ;
    case eEngineEventApplicationResume : break ;
    case eEngineEventApplicationStop   : break ;
    case eEngineEventFrameUpdateBegin  : break ;
    case eEngineEventFrameUpdateEnd    : break ;
    case eEngineEventFrameRenderBegin  : break ;
    case eEngineEventFrameRenderEnd    : break ;
    }
}
