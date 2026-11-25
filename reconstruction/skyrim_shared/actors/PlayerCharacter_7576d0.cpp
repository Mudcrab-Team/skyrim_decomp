// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7576d0 PlayerCharacter::Function7576d0
// Adapted bodies: none
#include "PlayerCharacter_7576d0.h"

bool PlayerCharacter::Function7576d0(void* item)
{
    if (item) {
        for (Node* node = &unk4B0; node; node = node->next) {
            if (node->item == item) {
                return true;
            }
        }
    }
    return false;
}
