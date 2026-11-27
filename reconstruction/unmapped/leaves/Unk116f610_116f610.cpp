// CI hash: 0x116f610 ?Function116f610@Unk116f610@@QEAAPEAXXZ
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Unk116f610: STANDIN GUESS(low)
// Unk116f610::Function116f610: GUESS(low)
// Unk116f610::linked, Unk116f610::local, LinkedState116f610: GUESS(low)
// 0x116f610 Unk116f610::Function116f610
#include "Unk116f610_116f610.h"

// Read or update the stored values.
void* Unk116f610::Function116f610()
{
    void* const* location = linked ? &linked->value : &local;
    return *location;
}
