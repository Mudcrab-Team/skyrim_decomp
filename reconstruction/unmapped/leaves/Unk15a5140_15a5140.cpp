// CI hash: 0x15a5140 ?Function15a5140@Unk15a5140@@QEAA_KPEAXI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk15a5140: STANDIN GUESS(low)
// Unk15a5140::Function15a5140: GUESS(low)
// Unk15a5140::data, Unk15a5140::hasData, StatMorph15a5140: GUESS(low)
// 0x15a5140 Unk15a5140::Function15a5140
#include "Unk15a5140_15a5140.h"

// Compute the address of the indexed morph record.
std::uintptr_t Unk15a5140::Function15a5140(void* context, std::uint32_t index)
{
    std::uintptr_t base = hasData ? reinterpret_cast<std::uintptr_t>(data) : 0;
    return base + static_cast<std::uintptr_t>(index) * sizeof(StatMorph15a5140);
}
