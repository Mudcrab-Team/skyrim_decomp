// CI hash: 0x45c380 ?Function45c380@Unk45c380@@QEAA_KIPEAX@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk45c380: STANDIN GUESS(low)
// Unk45c380::Function45c380: GUESS(low)
// Unk45c380::values, Unk45c380::direct: GUESS(low)
// 0x45c380 Unk45c380::Function45c380
#include "Unk45c380_45c380.h"

// Read or update the stored values.
std::uint64_t Unk45c380::Function45c380(std::uint32_t index, void* context)
{
    const Value45c380& entry = values[index];
    return direct ? entry.value : Resolve45c380(context, entry.kind);
}
