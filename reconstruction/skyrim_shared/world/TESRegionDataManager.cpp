// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; reconstructed from the pinned listing, with the community name and PDB layout
// GetLastLoadedRegion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// lastLoadedRegion: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x251ca0 TESRegionDataManager::GetLastLoadedRegion
// Adapted bodies: none
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

TESRegion* TESRegionDataManager::GetLastLoadedRegion() const
{
    return lastLoadedRegion;
}
