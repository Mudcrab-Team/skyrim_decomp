// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x251870 TESRegionDataManager::AsRegionDataObjects
// 0x2518b0 TESRegionDataManager::AsRegionDataWeather
// 0x2518f0 TESRegionDataManager::AsRegionDataMap
// 0x251930 TESRegionDataManager::AsRegionDataLandscape
// 0x251970 TESRegionDataManager::AsRegionDataGrass
// 0x2519b0 TESRegionDataManager::AsRegionDataSound
#include "TESRegionDataManager.h"

TESRegionDataObjects* TESRegionDataManager::AsRegionDataObjects(TESRegionData* a_data) const
{
    if (a_data != nullptr && a_data->GetRegionType() == 2) {
        return reinterpret_cast<TESRegionDataObjects*>(a_data);
    }
    return nullptr;
}

TESRegionDataWeather* TESRegionDataManager::AsRegionDataWeather(TESRegionData* a_data) const
{
    if (a_data != nullptr && a_data->GetRegionType() == 3) {
        return reinterpret_cast<TESRegionDataWeather*>(a_data);
    }
    return nullptr;
}

TESRegionDataMap* TESRegionDataManager::AsRegionDataMap(TESRegionData* a_data) const
{
    if (a_data != nullptr && a_data->GetRegionType() == 4) {
        return reinterpret_cast<TESRegionDataMap*>(a_data);
    }
    return nullptr;
}

TESRegionDataLandscape* TESRegionDataManager::AsRegionDataLandscape(TESRegionData* a_data) const
{
    if (a_data != nullptr && a_data->GetRegionType() == 5) {
        return reinterpret_cast<TESRegionDataLandscape*>(a_data);
    }
    return nullptr;
}

TESRegionDataGrass* TESRegionDataManager::AsRegionDataGrass(TESRegionData* a_data) const
{
    if (a_data != nullptr && a_data->GetRegionType() == 6) {
        return reinterpret_cast<TESRegionDataGrass*>(a_data);
    }
    return nullptr;
}

TESRegionDataSound* TESRegionDataManager::AsRegionDataSound(TESRegionData* a_data) const
{
    if (a_data != nullptr && a_data->GetRegionType() == 7) {
        return reinterpret_cast<TESRegionDataSound*>(a_data);
    }
    return nullptr;
}
