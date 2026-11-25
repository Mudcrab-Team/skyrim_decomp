// Source exposure: mixed (pinned image listings, existing project units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the cited CommonLibSSE-NG layout. Stamped as a twin of matched 0x30ea50 (skyrim_shared/world/TESWorldSpace_30db60): source copied, names replaced by placeholders.
// Function120f00, Owner120f00: GUESS(low) STANDIN
// HasMaxHeightData, IsSmallWorld, DisallowsFastTravel, Function30dc30, HasNoLODWater, HasNoLandscape, HasNoGrass, DisallowsWaiting, Function30dc50, GetParentForData, GetParentWorld, GetMusicType, GetPortalGraph, Function310800, GetPersistentCell, Function310d70, cellMap, persistentCell, flags, parentUseFlags, portalGraph, parentWorld, musicType, maxHeightData: GUESS(low) STANDIN
#pragma once
#include "TESWorldSpace_30db60.h"

class Owner120f00
{
public:
    bool IsSmallWorld() const;
    bool DisallowsFastTravel() const;
    bool DisallowsWaiting() const;
    bool Function30dc30() const;
    void Function30dc50(bool enabled);
    bool HasNoLODWater() const;
    bool HasNoLandscape() const;
    bool HasNoGrass() const;
    Owner120f00* GetParentForData(std::uint32_t dataIndex) const;
    Owner120f00* GetParentWorld() const;
    BGSMusicType* GetMusicType() const;
    std::uint32_t Function120f00() const;
    BSPortalGraph* GetPortalGraph() const;
    void Function310800(void* argument);
    TESObjectCELL* GetPersistentCell() const;
    void Function310d70();
    bool HasMaxHeightData() const;

private:
    // kSkyCellIndex: STANDIN GUESS(low)
    static constexpr std::uint32_t kSkyCellIndex = 6;

// TESForm::formFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t padding00[0x10];
    std::uint32_t formFlags;

    CellMap cellMap;
    TESObjectCELL* persistentCell;
    std::uint8_t padding90[0x10];
    std::uint8_t flags;
    std::uint8_t paddingA1;
    std::uint16_t parentUseFlags;
    std::uint8_t paddingA4[0x8C];
    BSPortalGraph* portalGraph;
    std::uint8_t padding138[0x20];
    Owner120f00* parentWorld;
    std::uint8_t padding160[0x58];
    BGSMusicType* musicType;
    std::uint8_t padding1C0[0x190];
    std::int8_t* maxHeightData;
};
