// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf14df0 NiPSysData::SetSubtextureOffsets
// CI hash: 0xf14df0 ?SetSubtextureOffsets@NiPSysData@@QEAAXPEAXI@Z
#include "NiPSysData_f14df0.h"

// Replace the subtexture offset buffer and store its count clamped to 256.
// The CrashLogger name is sub_140C886C0; the name used here is a guess from what the body does.
void NiPSysData::SetSubtextureOffsets(void* a_offsets, std::uint32_t a_count)
{
    NiFree(subtextureOffsets);
    subtextureOffsets = a_offsets;
    subtextureOffsetCount = a_count < 0x100u ? a_count : 0x100u;
}
