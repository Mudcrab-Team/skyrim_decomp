// CI hash: 0x6e8420 ?Function6e8420@Unk6e8420@@QEAAIXZ
// Source exposure: binary-analysis.
// Code origin: original bounded scalar accessor reconstruction.
// SPDX-License-Identifier: CC0-1.0
// Unk6e8420: GUESS(low)
// Unk6e8420::Function6e8420: GUESS(low)
// Unk6e8420::unk4c, Unk6e8420::kFieldMask0: GUESS(low)
// 0x6e8420 Unk6e8420::Function6e8420
#include "Unk6e8420_6e8420.h"

// Read the selected bits of the stored scalar.
std::uint32_t Unk6e8420::Function6e8420()
{
    return (unk4c & kFieldMask0);
}
