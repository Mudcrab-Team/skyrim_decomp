// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x6d9f20 Actor::Function6d9f20
// Adapted bodies: none
#include "Actor_6d9f20.h"

void Actor::Function6d9f20()
{
    ThreadStateScope6d9f20 scope(0x5F);
    while (unk188) {
        ListNode6d9f20* node = unk188;
        unk188 = node->next;
        delete node;
    }
}
