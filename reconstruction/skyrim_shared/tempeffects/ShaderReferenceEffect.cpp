// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing; bit test on a flags member.
// Adapted bodies: none.
// 0x5e2320 ShaderReferenceEffect::Function5e2320
// 0x5dfed0 ShaderReferenceEffect::GetStackable
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
#include "ShaderReferenceEffect.h"
// GetStackable: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
std::uint8_t ShaderReferenceEffect::GetStackable() const
{
    return 0x1;
}

bool ShaderReferenceEffect::Function5e2320() const
{
    return (flags >> 1) & 1;
}
