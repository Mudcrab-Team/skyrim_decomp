// CI hash: 0x4a6610 ?Function4a6610@Unk4a6610@@QEAAPEAIPEAI@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk4a6610: STANDIN GUESS(low)
// Unk4a6610::Function4a6610: GUESS(low)
// Unk4a6610::tag, Unk4a6610::value, gFallback4a6610: GUESS(low)
// 0x4a6610 Unk4a6610::Function4a6610
#include "Unk4a6610_4a6610.h"

// Read or update the stored values.
std::uint32_t* Unk4a6610::Function4a6610(std::uint32_t* output)
{
    *output = tag == 0 ? value : gFallback4a6610;
    return output;
}
