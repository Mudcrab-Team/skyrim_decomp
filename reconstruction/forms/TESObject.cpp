// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x275ee0 TESObject::IsOcclusionMarker
#include "TESObject.h"

std::uint32_t TESObject::DecRef()
{
    return 0;
}

std::uint32_t TESObject::GetRefCount() const
{
    return 0;
}

TESWaterForm* TESObject::GetWaterType() const
{
    return nullptr;
}

bool TESObject::IsOcclusionMarker()
{
    if (formType != static_cast<FormType>(0x22)) {
        return false;
    }
    if (g_occlusionMarkerA == this || g_occlusionMarkerB == this) {
        return true;
    }
    if (g_occlusionMarkerC != this) {
        return false;
    }
    return true;
}
