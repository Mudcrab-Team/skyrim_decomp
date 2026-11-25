// Exposure detail: (community layouts and local pinned-image observations).
// Source exposure: mixed
// Code origin: original; no sibling body reused
// SPDX-License-Identifier: CC0-1.0
// MagicItem, MagicItem::GetCostliestEffectItem, Effect: CRASHLOGGER_PDB(59818@2026.10.24)
// CostliestEffectVisitor, its members, effects, effectCapacity, effectCount: STANDIN GUESS(low)

#pragma once
#include <cstdint>
#include <cstddef>
struct Effect;
class CostliestEffectVisitor {
public:
    virtual ~CostliestEffectVisitor() = default;
    virtual std::int32_t Visit(Effect* effect);
    std::uint64_t index = 0;
    Effect* result = nullptr;
    std::uint32_t selectedIndex = UINT32_MAX;
    std::uint32_t delivery;
    bool includeInactive;
    CostliestEffectVisitor(std::uint32_t delivery, bool includeInactive) :
        delivery(delivery), includeInactive(includeInactive) {}
};
class MagicItem {
public:
    Effect* GetCostliestEffectItem(std::uint32_t delivery, bool includeInactive);
    std::uint8_t pad00[0x58];
    Effect** effects;
    std::uint32_t effectCapacity;
    std::uint32_t pad64;
    std::uint32_t effectCount;
};
