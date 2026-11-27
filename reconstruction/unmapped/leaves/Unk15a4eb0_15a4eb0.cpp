// CI hash: 0x15a4eb0 ?Function15a4eb0@Unk15a4eb0@@QEAA_KPEAXI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk15a4eb0: STANDIN GUESS(low)
// Unk15a4eb0::Function15a4eb0: GUESS(low)
// Unk15a4eb0::data, Unk15a4eb0::hasData, DiffMorph15a4eb0: GUESS(low)
// 0x15a4eb0 Unk15a4eb0::Function15a4eb0
#include "Unk15a4eb0_15a4eb0.h"

// Compute the address of the indexed morph record.
std::uintptr_t Unk15a4eb0::Function15a4eb0(void* context, std::uint32_t index)
{
    std::uintptr_t base = hasData ? reinterpret_cast<std::uintptr_t>(data) : 0;
    return base + static_cast<std::uintptr_t>(index) * sizeof(DiffMorph15a4eb0);
}
