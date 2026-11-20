// 0x1526e70 BSLightingShaderMaterialFacegenTint::Function1526e70
// Function1526e70: GUESS(low); the plain destructor, emitted out of line
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1526fc0 BSLightingShaderMaterialFacegenTint::GetFeature
// 0x1526e30 BSLightingShaderMaterialFacegenTint::Ctor
// 0x1526f20 BSLightingShaderMaterialFacegenTint::CopyMembers
// 0x1528ec0 BSLightingShaderMaterialFacegenTint::~BSLightingShaderMaterialFacegenTint
// Code origin: existing unit text, declarations after CommonLibSSE-NG names; this change only adds the origin line.
#include <new>
#include "BSLightingShaderMaterialFacegenTint.h"

// Not compared on its own: Ctor below runs it in place, and the compiler emits the vftable here.
BSLightingShaderMaterialFacegenTint::BSLightingShaderMaterialFacegenTint() :
    fieldA0{}, fieldA8(0)
{}

BSLightingShaderMaterialFacegenTint::Feature BSLightingShaderMaterialFacegenTint::GetFeature() const
{
    return static_cast<Feature>(5);
}

BSLightingShaderMaterialFacegenTint* BSLightingShaderMaterialFacegenTint::Ctor()
{
    return new (this) BSLightingShaderMaterialFacegenTint();
}

void BSLightingShaderMaterialFacegenTint::CopyMembers(BSShaderMaterial* a_other)
{
    BSLightingShaderMaterial::CopyMembers(a_other);
    const auto* other = static_cast<const BSLightingShaderMaterialFacegenTint*>(a_other);
    fieldA0 = other->fieldA0;
    fieldA8 = other->fieldA8;
}

BSLightingShaderMaterialFacegenTint::~BSLightingShaderMaterialFacegenTint()
{
}
