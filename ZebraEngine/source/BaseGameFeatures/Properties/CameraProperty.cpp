/**
* Camera Property - Entities that should be able to be follow
*					by the camera needs this property.
* @file CameraProperty.h
* @author Sebastian Salonen
* @date 20111203 - Initial Release
*/
#include "../../../includes/BaseGameFeatures/Properties/CameraProperty.h"

using namespace std;
using namespace boost;


namespace BaseGameFeatures
{

//==============================================================================

__ImplementProperty(BaseGameFeatures::CameraProperty, 'CAPR')
	
//==============================================================================

CameraProperty::CameraProperty()
{
	//Empty
}

//==============================================================================

CameraProperty::~CameraProperty()
{
	//Empty
}
	
//==============================================================================

void CameraProperty::OnActivate()
{
	//Empty
}

//==============================================================================

void CameraProperty::OnFrame()
{
	//Empty
}
	
//==============================================================================

void CameraProperty::OnDeactivate()
{
	//Empty
}

//==============================================================================

}