// Source exposure: mixed (community names/layouts; pinned-image observations).
// Code origin: original; declarations narrowed to accessed fields
// SPDX-License-Identifier: CC0-1.0
// TESWaterSystem, TESWaterObject, BSTriShape, Enable: CRASHLOGGER_PDB(59818@2026.10.24)
// BSTriShape::flags, WaterEnableRequested, WaterEnabledSetting: STANDIN OBSERVED
#pragma once
#include <cstdint>
#include <cstddef>

struct BSTriShape {
    std::uint8_t reserved000[0xF4];
    std::uint32_t flags;
};
struct TESWaterObject {
    std::uint8_t reserved000[0x20];
    BSTriShape* shape;
};
class TESWaterSystem {
public:
    bool Enable();
    std::uint8_t reserved000[0x20];
    TESWaterObject** waterObjects;
    std::uint8_t reserved028[8];
    std::uint32_t waterObjectCount;
    std::uint8_t reserved034[0x7C];
    bool enabled;
    std::uint8_t reserved0B1[9];
    bool waterVisible;
};
static_assert(offsetof(TESWaterSystem, enabled) == 0xB0, "enabled offset");
static_assert(offsetof(TESWaterSystem, waterVisible) == 0xBA, "visibility offset");
extern bool WaterEnableRequested;
extern bool WaterEnabledSetting;
