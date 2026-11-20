// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0xfd8f90 BSWindModifier::GetRTTI
// 0xfd8f50 BSWindModifier::~BSWindModifier
#include "BSWindModifier.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSWindModifier::BSWindModifier()
{
}

// NiRTTI_BSWindModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
extern const NiRTTI NiRTTI_BSWindModifier;

const NiRTTI* BSWindModifier::GetRTTI() const
{
    return &NiRTTI_BSWindModifier;
}
