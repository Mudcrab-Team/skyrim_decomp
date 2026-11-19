// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1528e80 BSLightingShaderMaterialFacegen::~BSLightingShaderMaterialFacegen
// 0x1526760 BSLightingShaderMaterialFacegen::Ctor
#include <new>
#include "BSLightingShaderMaterialFacegen.h"

// Not compared on its own: Ctor below runs it in place, and the compiler emits the vftable here.
BSLightingShaderMaterialFacegen::BSLightingShaderMaterialFacegen()
{
    fieldA0 = 0;
    fieldA8 = 0;
    fieldB0 = 0;
}

BSLightingShaderMaterialFacegen* BSLightingShaderMaterialFacegen::Ctor()
{
    return new (this) BSLightingShaderMaterialFacegen();
}
