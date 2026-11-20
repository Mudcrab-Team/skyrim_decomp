// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none.
// 0xfe9bd0 BSOcclusionPlane::~BSOcclusionPlane
#include "BSOcclusionPlane.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSOcclusionPlane::BSOcclusionPlane()
{
}

// Body done: RVA 0xfe9bd0, 50 bytes, BSOcclusionPlane::~BSOcclusionPlane; compared as the scalar
// deleting destructor. The target does the NiRefObject cleanup itself, so keep this empty
// definition and the constructor: the inline base destructors in the header make the compiler
// produce the same body.
BSOcclusionPlane::~BSOcclusionPlane()
{
}

// BSOcclusionPlane::IsOcclusionPlane: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
bool BSOcclusionPlane::IsOcclusionPlane() const
{
    return true;
}

// BSOcclusionPlane::GetRTTI: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
const NiRTTI* BSOcclusionPlane::GetRTTI() const
{
    return &NiRTTI_BSOcclusionPlane;
}
