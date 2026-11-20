// Source exposure: mixed (pinned image listings, existing project units, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies from the pinned listings using the cited declarations.
// Adapted bodies: HasMaxHeightData follows CommonLibSSE-NG@b93280e src/RE/T/TESWorldSpace.cpp:5 (MIT).
// 0x30db60 TESWorldSpace::IsSmallWorld
// 0x30dba0 TESWorldSpace::DisallowsFastTravel
// 0x30dbf0 TESWorldSpace::DisallowsWaiting
// 0x30dc30 TESWorldSpace::Function30dc30
// 0x30dc50 TESWorldSpace::Function30dc50
// 0x30dcf0 TESWorldSpace::HasNoLODWater
// 0x30dd40 TESWorldSpace::HasNoLandscape
// 0x30dde0 TESWorldSpace::HasNoGrass
// 0x30e050 TESWorldSpace::GetParentForData
// 0x30e090 TESWorldSpace::GetParentWorld
// 0x30e4f0 TESWorldSpace::GetMusicType
// 0x30ea50 TESWorldSpace::GetCellCount
// 0x30f610 TESWorldSpace::GetPortalGraph
// 0x310800 TESWorldSpace::Function310800
// 0x310820 TESWorldSpace::GetPersistentCell
// 0x310d70 TESWorldSpace::Function310d70
// 0x3121b0 TESWorldSpace::HasMaxHeightData
#include "TESWorldSpace_30db60.h"

// Function2bfe20, Function2c3060: STANDIN GUESS(low)
class TESObjectCELL
{
public:
    void Function2bfe20(void* argument);
    void Function2c3060();
};

bool TESWorldSpace::IsSmallWorld() const
{
    return (flags >> 0) & 1;
}

bool TESWorldSpace::DisallowsFastTravel() const
{
    return (flags >> 1) & 1;
}

bool TESWorldSpace::DisallowsWaiting() const
{
    return (formFlags >> 19) & 1;
}

bool TESWorldSpace::Function30dc30() const
{
    return (flags >> 2) & 1;
}

void TESWorldSpace::Function30dc50(bool enabled)
{
    if (enabled) {
        flags |= 1u << 2;
    } else {
        flags &= ~(1u << 2);
    }
}

bool TESWorldSpace::HasNoLODWater() const
{
    return (flags >> 3) & 1;
}

bool TESWorldSpace::HasNoLandscape() const
{
    return (flags >> 4) & 1;
}

bool TESWorldSpace::HasNoGrass() const
{
    return (flags >> 7) & 1;
}

TESWorldSpace* TESWorldSpace::GetParentForData(std::uint32_t dataIndex) const
{
    auto* parent = parentWorld;
    if (!parent || dataIndex > kSkyCellIndex) {
        return parent;
    }
    if (!(parentUseFlags & static_cast<std::uint8_t>(1u << dataIndex))) {
        return nullptr;
    }
    return parent;
}

TESWorldSpace* TESWorldSpace::GetParentWorld() const
{
    return parentWorld;
}

BGSMusicType* TESWorldSpace::GetMusicType() const
{
    return musicType;
}

std::uint32_t TESWorldSpace::GetCellCount() const
{
    return cellMap.capacity - cellMap.freeSlots;
}

BSPortalGraph* TESWorldSpace::GetPortalGraph() const
{
    return portalGraph;
}

void TESWorldSpace::Function310800(void* argument)
{
    if (argument && persistentCell) {
        persistentCell->Function2bfe20(argument);
    }
}

TESObjectCELL* TESWorldSpace::GetPersistentCell() const
{
    return persistentCell;
}

void TESWorldSpace::Function310d70()
{
    if (persistentCell) {
        persistentCell->Function2c3060();
    }
}

bool TESWorldSpace::HasMaxHeightData() const
{
    return maxHeightData != nullptr;
}
