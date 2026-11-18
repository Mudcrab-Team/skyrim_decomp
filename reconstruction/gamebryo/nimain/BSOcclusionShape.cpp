// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xfdc610 BSOcclusionShape::~BSOcclusionShape
#include "BSOcclusionShape.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSOcclusionShape::BSOcclusionShape()
{
}

// CreateClone, GetRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
NiObject* BSOcclusionShape::CreateClone(NiCloningProcess& a_cloning)
{
    return nullptr;
}

const NiRTTI* BSOcclusionShape::GetRTTI() const
{
    return &NiRTTI_BSOcclusionShape;
}

// Body done: RVA 0xfdc610, 50 bytes, BSOcclusionShape::~BSOcclusionShape; compared as the scalar
// deleting destructor. The target does the NiRefObject cleanup itself, so keep this empty
// definition and the constructor: the inline base destructors in the header make the compiler
// produce the same body.
BSOcclusionShape::~BSOcclusionShape()
{
}
