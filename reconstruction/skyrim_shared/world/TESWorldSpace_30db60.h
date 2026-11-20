// Source exposure: mixed (pinned image listings, existing project units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial declarations adapted from the cited CommonLibSSE-NG layout.
// HasMaxHeightData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESWorldSpace: EXE_RTTI
// IsSmallWorld, DisallowsFastTravel, Function30dc30, HasNoLODWater, HasNoLandscape: GUESS(low)
// HasNoGrass, DisallowsWaiting, Function30dc50: GUESS(low)
// GetParentForData, GetParentWorld: GUESS(low)
// GetMusicType, GetCellCount, GetPortalGraph, Function310800, GetPersistentCell: GUESS(low)
// Function310d70: GUESS(low)
#pragma once

#include <cstdint>

// CellMap, capacity, freeSlots: STANDIN GUESS(low)
struct CellMap
{
    std::uint8_t padding00[0xC];
    std::uint32_t capacity;
    std::uint32_t freeSlots;
    std::uint8_t padding14[0x1C];
};

class BGSMusicType;
class BSPortalGraph;
class TESObjectCELL;

class TESWorldSpace
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
    TESWorldSpace* GetParentForData(std::uint32_t dataIndex) const;
    TESWorldSpace* GetParentWorld() const;
    BGSMusicType* GetMusicType() const;
    std::uint32_t GetCellCount() const;
    BSPortalGraph* GetPortalGraph() const;
    void Function310800(void* argument);
    TESObjectCELL* GetPersistentCell() const;
    void Function310d70();
    bool HasMaxHeightData() const;

private:
    // kSkyCellIndex: STANDIN GUESS(low)
    static constexpr std::uint32_t kSkyCellIndex = 6;

    // TESForm::formFlags, cellMap, persistentCell, flags, parentUseFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // portalGraph, parentWorld, musicType, maxHeightData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    std::uint8_t padding00[0x10];
    std::uint32_t formFlags;
    std::uint8_t padding14[0x44];
    CellMap cellMap;
    TESObjectCELL* persistentCell;
    std::uint8_t padding90[0x10];
    std::uint8_t flags;
    std::uint8_t paddingA1;
    std::uint16_t parentUseFlags;
    std::uint8_t paddingA4[0x8C];
    BSPortalGraph* portalGraph;
    std::uint8_t padding138[0x20];
    TESWorldSpace* parentWorld;
    std::uint8_t padding160[0x58];
    BGSMusicType* musicType;
    std::uint8_t padding1C0[0x190];
    std::int8_t* maxHeightData;
};
