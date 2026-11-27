// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1a8ca0 TES::ClearSlot170
// Adapted bodies: none
#include "TES_1a8ca0.h"

void TES::ClearSlot170()
{
    RefCounted* old = unk170;
    if (old) {
        unk170 = nullptr;
        old->Release();
    }
}
