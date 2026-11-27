// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// 0x69d0d0 Character::sub_1405F7730
// Adapted bodies: none
#include "Character_69d0d0.h"

// Reset the process subobject state and timer, then invoke the process follow-up routine.
void Character::sub_1405F7730()
{
    if (currentProcess) {
        if (ProcessSub69d0d0* sub = currentProcess->GetSub6ff530()) {
            sub->unk1c = kDefaultTimer69d0d0;
            sub->unk18 = 4;
            currentProcess->Finish6f6f80();
        }
    }
}
