// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1528fb0 BSLightingShaderMaterialHairTint::~BSLightingShaderMaterialHairTint
// 0x1527050 BSLightingShaderMaterialHairTint::Ctor
// Code origin: existing unit text, declarations after CommonLibSSE-NG names; this change only adds the origin line.
#include <new>
#include "BSLightingShaderMaterialHairTint.h"

// Not compared on its own: Ctor below runs it in place, and the compiler emits the vftable here.
BSLightingShaderMaterialHairTint::BSLightingShaderMaterialHairTint()
{
    fieldA0 = g_hairTintDefaultA;
    fieldA8 = g_hairTintDefaultB;
}

BSLightingShaderMaterialHairTint* BSLightingShaderMaterialHairTint::Ctor()
{
    return new (this) BSLightingShaderMaterialHairTint();
}
