// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1527a80 BSLightingShaderMaterialLandscape::GetFeature
// 0x1529030 BSLightingShaderMaterialLandscape::~BSLightingShaderMaterialLandscape
#include "BSLightingShaderMaterialLandscape.h"

// Not compared on its own: the compiler emits the vftable here, and with it the deleting
// destructor that is compared. The destructor itself stays undefined here so that the compiler
// calls the separate complete destructor, as the listing does.
BSLightingShaderMaterialLandscape::BSLightingShaderMaterialLandscape()
{
}

BSLightingShaderMaterialLandscape::Feature BSLightingShaderMaterialLandscape::GetFeature() const
{
    return static_cast<Feature>(0x13);
}
