// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6ffeb0 ActorProcess::Function6ffeb0
// Adapted bodies: none
#include "ActorProcess_6ffeb0.h"

void ActorProcess::Function6ffeb0(std::uint32_t slot, std::uint16_t value)
{
    if (unk10) {
        if (slot == 0) {
            if (unk10->word3F8 == -1) {
                unk10->word3F8 = value;
            }
        } else if (slot == 1) {
            if (unk10->word3FA == -1) {
                unk10->word3FA = value;
            }
        }
    }
}
