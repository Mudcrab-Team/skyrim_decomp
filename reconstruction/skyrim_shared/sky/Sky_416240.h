// Source exposure: mixed (binary-analysis of the pinned image, CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sky, Sky::UpdateLightLODFadeDistances, Sky::GetCurrentRoomLightingTemplate, Sky::GetPreviousRoomLightingTemplate, Sky::lightingTransition, BGSLightingTemplate, TESObjectCELL, TES: CRASHLOGGER_PDB(59818@2026.10.24)
// Function295920, Function295940, Function2bc540, Function2bc5b0, GetSingleton, GetInteriorCell, g_tes, g_defaultLightLODStart, g_defaultLightLODRange, g_lightLODFadeStartSq, g_lightLODFadeEndSq, unk00, unk28, unk30, interiorCell: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BGSLightingTemplate
{
public:
    float Function295920();
    float Function295940();
};

class TESObjectCELL
{
public:
    float Function2bc540();
    float Function2bc5b0();
};

class TES
{
public:
    static TES* GetSingleton();
    TESObjectCELL* GetInteriorCell() const { return interiorCell; }

    std::uint8_t unk00[0xC0];
    TESObjectCELL* interiorCell;  // C0
};
static_assert(offsetof(TES, interiorCell) == 0xC0, "TES interiorCell offset");

extern TES* g_tes;
inline TES* TES::GetSingleton() { return g_tes; }
extern const float g_defaultLightLODStart;
extern const float g_defaultLightLODRange;
extern float g_lightLODFadeStartSq;
extern float g_lightLODFadeEndSq;

class Sky
{
public:
    void UpdateLightLODFadeDistances();  // compared: 0x416240
    BGSLightingTemplate* GetCurrentRoomLightingTemplate();
    BGSLightingTemplate* GetPreviousRoomLightingTemplate();

    std::uint8_t unk00[0x28];
    BGSLightingTemplate* unk28;  // 28
    std::uint8_t unk30[0x38 - 0x30];
    float lightingTransition;    // 38
};
static_assert(offsetof(Sky, unk28) == 0x28, "Sky unk28 offset");
static_assert(offsetof(Sky, lightingTransition) == 0x38, "Sky lightingTransition offset");
