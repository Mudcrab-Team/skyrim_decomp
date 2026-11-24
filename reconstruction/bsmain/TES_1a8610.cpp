// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1a8610 TES::ClearSlot160
// Adapted bodies: none
#include "TES_1a8610.h"

void TES::ClearSlot160()
{
    RefCounted* old = unk160;
    if (old) {
        unk160 = nullptr;
        old->Release();
    }
}
