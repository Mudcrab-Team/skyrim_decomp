// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xbb85a0 BSIsActiveModifier::UpdateFlagsCopied
// Adapted bodies: none
#include "BSIsActiveModifier_bb85a0.h"

void BSIsActiveModifier::UpdateFlagsCopied()
{
    flags[0] = flags[1];
    flags[2] = flags[3];
    flags[4] = flags[5];
    flags[6] = flags[7];
    flags[8] = flags[9];
}
