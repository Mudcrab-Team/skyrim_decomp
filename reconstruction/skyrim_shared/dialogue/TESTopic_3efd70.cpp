// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x3efd70 TESTopic::Function3efd70
// Adapted bodies: none
#include "TESTopic_3efd70.h"

void TESTopic::Function3efd70(BGSDialogueBranch* branch)
{
    pOwnerBranch = branch;
    if (branch && !branch->unk30) {
        branch->Function38cf10(this);
    }
}
