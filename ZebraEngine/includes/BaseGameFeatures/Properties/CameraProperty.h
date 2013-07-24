/**
* Camera Property - Entities that should be able to be follow
*					by the camera needs this property.
* @file CameraProperty.h
* @author Sebastian Salonen
* @date 20111203 - Initial Release
*/
#ifndef CAMERAPROPERTY_H
#define CAMERAPROPERTY_H

#include "../Property.h"

namespace BaseGameFeatures
{

//==============================================================================

class CameraProperty : public BaseGameFeatures::Property
{
    __DeclareProperty
    private:

    public:
	CameraProperty();
	~CameraProperty();

	void							OnActivate();
	void							OnFrame();
	void							OnDeactivate();
};

//==============================================================================

}

#endif