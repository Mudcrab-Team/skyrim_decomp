// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x4b2950 BSTempEffectSimpleDecal::Get3D
// 0x4b1090 BSTempEffectSimpleDecal::Initialize
// 0x4b4a40 BSTempEffectSimpleDecal::~BSTempEffectSimpleDecal
#include "BSTempEffectSimpleDecal.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSTempEffectSimpleDecal::BSTempEffectSimpleDecal(TESObjectCELL* a_cell, float a_lifetime)
    : BSTempEffect(a_cell, a_lifetime)
{
}

// Body done: RVA 0x4b2950, 5 bytes, BSTempEffectSimpleDecal::Get3D.
NiAVObject* BSTempEffectSimpleDecal::Get3D() const
{
    return effect3D;
}

// Body done: RVA 0x4b1090, 35 bytes, BSTempEffectSimpleDecal::Initialize. The flag is set only
// when the shape setup succeeds.
void BSTempEffectSimpleDecal::Initialize()
{
    if (SetupAVShape(avShape)) {
        initialized = true;
    }
}

// RVA 0x4b4a40 (scalar deleting destructor) has no body here: the compiler emits the deleting form
// and calls the complete destructor, which attempt binds to the listed address.
