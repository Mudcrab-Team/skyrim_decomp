// CI hash: 0x8d8fd0 ?Function8d8fd0@Unk8d8fd0@@QEAAXXZ
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk8d8fd0: STANDIN GUESS(low)
// Unk8d8fd0::Function8d8fd0: GUESS(low)
// Unk8d8fd0::state: GUESS(low)
// 0x8d8fd0 Unk8d8fd0::Function8d8fd0
#include "Unk8d8fd0_8d8fd0.h"

// Set the state from the virtual status query.
void Unk8d8fd0::Function8d8fd0()
{
    state = (Query() != 0) + 5;
}
