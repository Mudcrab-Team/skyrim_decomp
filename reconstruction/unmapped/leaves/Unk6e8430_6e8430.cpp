// CI hash: 0x6e8430 ?Function6e8430@Unk6e8430@@QEAAIXZ
// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk6e8430: GUESS(low)
// Unk6e8430::Function6e8430: GUESS(low)
// Unk6e8430::unk4c, Unk6e8430::kShift0, Unk6e8430::kFieldMask1: GUESS(low)
// 0x6e8430 Unk6e8430::Function6e8430
#include "Unk6e8430_6e8430.h"

// Read the selected bits of the stored scalar.
std::uint32_t Unk6e8430::Function6e8430()
{
    return ((unk4c >> kShift0) & kFieldMask1);
}
