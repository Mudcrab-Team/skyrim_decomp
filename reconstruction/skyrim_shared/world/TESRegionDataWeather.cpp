// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x253ea0 TESRegionDataWeather::IsLoaded
#include "TESRegionDataWeather.h"

bool TESRegionDataWeather::IsLoaded() const
{
    if (field18 != nullptr) {
        return true;
    }
    if (field10 != nullptr) {
        return true;
    }
    return false;
}
