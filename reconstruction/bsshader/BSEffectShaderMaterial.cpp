// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Code origin: original; the listing and community declarations only
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x1556630 BSEffectShaderMaterial::~BSEffectShaderMaterial
// 0x1556500 BSEffectShaderMaterial::GetDefault
#include "BSEffectShaderMaterial.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSEffectShaderMaterial::BSEffectShaderMaterial()
{
}

BSShaderMaterial* BSEffectShaderMaterial::GetDefault()
{
    return g_defaultEffectShaderMaterial;
}
