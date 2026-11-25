// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x6adf40 (skyrim_shared/actors/Character_6adf40): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x6af440 Owner6af440::Function6af440
#include "Owner6af440.h"

// guess: same compiled code as matched 0x6adf40 apart from relocated fields; its role here is not established.
void Owner6af440::Function6af440()
{
    if (held) {
        Target6adf40* target = held->unk03(&g_type6adf40);
        if (target) {
            target->unk02();
        }
    }
}
