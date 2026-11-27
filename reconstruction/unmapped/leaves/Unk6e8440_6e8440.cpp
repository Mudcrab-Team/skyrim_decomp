// CI hash: 0x6e8440 ?Function6e8440@Unk6e8440@@QEAAIXZ
// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk6e8440: GUESS(low)
// Unk6e8440::Function6e8440: GUESS(low)
// Unk6e8440::unk4c, Unk6e8440::kShift0, Unk6e8440::kFieldMask1: GUESS(low)
// 0x6e8440 Unk6e8440::Function6e8440
#include "Unk6e8440_6e8440.h"

// Read the selected bits of the stored scalar.
std::uint32_t Unk6e8440::Function6e8440()
{
    return ((unk4c >> kShift0) & kFieldMask1);
}
