// CI hash: 0x1010600 ?Function1010600@Unk1010600@@QEAAX_N@Z
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk1010600: STANDIN GUESS(low)
// Unk1010600::Function1010600: GUESS(low)
// gDisabled1010600: GUESS(low)
// 0x1010600 Unk1010600::Function1010600
#include "Unk1010600_1010600.h"

// Store the inverse of the enabled flag.
void Unk1010600::Function1010600(bool enabled)
{
    gDisabled1010600 = !enabled;
}
