// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1a8a30 TES::ClearSlots
// Adapted bodies: none
#include "TES_1a8a30.h"

void TES::ClearSlots()
{
    RefCounted* a = unk178;
    if (a) {
        unk178 = nullptr;
        a->Release();
    }
    RefCountedSlot1* b = unk168;
    if (b) {
        unk168 = nullptr;
        b->Release();
    }
}
