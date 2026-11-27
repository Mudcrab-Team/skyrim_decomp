// Source exposure: mixed (binary-analysis of the pinned image listing, CrashLogger PDB names, community headers).
// Code origin: original reconstruction from the pinned image listing; names as labelled in the header
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x15308a0 UpdateVolumetricLightingRenderData
#include "FreeFunction_15308a0.h"

VolumetricLightingRenderData* UpdateVolumetricLightingRenderData(VolumetricLightingRenderData* a_out)
{
    a_out->unk00 = g_vlParam0;
    a_out->unk04 = g_vlParam1;
    a_out->unk08 = 1.0f;
    a_out->unk0C = 1.0f;
    a_out->unk10 = 1.0f;
    a_out->unk14 = g_vlParam2;
    a_out->unk18 = g_vlParam3;
    a_out->unk1C = g_vlParam4;
    a_out->unk20 = g_vlParam5;
    a_out->unk24 = g_vlParam6;
    a_out->unk28 = g_vlParam7;
    a_out->unk2C = g_vlParam8;
    return a_out;
}
