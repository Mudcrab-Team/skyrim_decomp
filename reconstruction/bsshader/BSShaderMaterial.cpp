// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1575700 BSShaderMaterial::CopyMembers
// 0x15758f0 BSShaderMaterial::~BSShaderMaterial
#include "BSShaderMaterial.h"

// Not compared on its own: the compiler emits the vftable here, and with it the deleting
// destructor that is compared.
BSShaderMaterial::BSShaderMaterial()
{
}

BSShaderMaterial::Feature BSShaderMaterial::GetFeature() const
{
    return Feature::kDefault;
}

BSShaderMaterial::Type BSShaderMaterial::GetType() const
{
    return static_cast<Type>(0);
}

BSShaderMaterial* BSShaderMaterial::GetDefault()
{
    return gDefaultShaderMaterial;
}

void BSShaderMaterial::CopyMembers(BSShaderMaterial* a_other)
{
    RawAt<BSShaderPair>(this, 0x0c) = RawAt<BSShaderPair>(a_other, 0x0c);
    RawAt<BSShaderPair>(this, 0x14) = RawAt<BSShaderPair>(a_other, 0x14);
    RawAt<BSShaderPair>(this, 0x1c) = RawAt<BSShaderPair>(a_other, 0x1c);
    RawAt<BSShaderPair>(this, 0x24) = RawAt<BSShaderPair>(a_other, 0x24);
}
