// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled below
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// UpdateVolumetricLightingRenderData: CRASHLOGGER_PDB(59818@2026.10.24)
// VolumetricLightingRenderData, g_vlParam0..g_vlParam8, unk00..unk2C: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct VolumetricLightingRenderData
{
    float unk00;  // 00
    float unk04;  // 04
    float unk08;  // 08
    float unk0C;  // 0C
    float unk10;  // 10
    float unk14;  // 14
    float unk18;  // 18
    float unk1C;  // 1C
    float unk20;  // 20
    float unk24;  // 24
    float unk28;  // 28
    float unk2C;  // 2C
};
static_assert(sizeof(VolumetricLightingRenderData) == 0x30, "VolumetricLightingRenderData size");

extern float g_vlParam0;
extern float g_vlParam1;
extern float g_vlParam2;
extern float g_vlParam3;
extern float g_vlParam4;
extern float g_vlParam5;
extern float g_vlParam6;
extern float g_vlParam7;
extern float g_vlParam8;

VolumetricLightingRenderData* UpdateVolumetricLightingRenderData(VolumetricLightingRenderData* a_out);  // compared: 0x15308a0
