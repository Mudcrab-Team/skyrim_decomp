// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// TESObjectCELL, INTERIOR_DATA, BGSLightingTemplate, cellFlags, lightingTemplate, fogPower, lightingTemplateInheritanceFlags: CRASHLOGGER_PDB(59818@2026.10.24)
// interiorData, GetFogPower, unknown00, unknown48, unknown000, unknown042, unknown070: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct INTERIOR_DATA
{
    std::uint8_t  unknown00[0x44];                   // 00
    float         fogPower;                          // 44
    std::uint8_t  unknown48[0x10];                   // 48
    std::uint32_t lightingTemplateInheritanceFlags;  // 58
};
static_assert(offsetof(INTERIOR_DATA, fogPower) == 0x44, "fogPower offset");
static_assert(offsetof(INTERIOR_DATA, lightingTemplateInheritanceFlags) == 0x58, "inheritanceFlags offset");

class BGSLightingTemplate
{
public:
    float GetFogPower() const;
};

class TESObjectCELL
{
public:
    float GetFogPower() const;

    std::uint8_t         unknown000[0x40];  // 000
    std::uint16_t        cellFlags;         // 040
    std::uint8_t         unknown042[0x26];  // 042
    INTERIOR_DATA*       interiorData;      // 068
    std::uint8_t         unknown070[0xC8];  // 070
    BGSLightingTemplate* lightingTemplate;  // 138
};
static_assert(offsetof(TESObjectCELL, cellFlags) == 0x40, "cellFlags offset");
static_assert(offsetof(TESObjectCELL, interiorData) == 0x68, "interiorData offset");
static_assert(offsetof(TESObjectCELL, lightingTemplate) == 0x138, "lightingTemplate offset");
