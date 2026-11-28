// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: InnerArray1805a0 and OuterArray1805a0 destructors, treated as adapted: shaped like BSTArray::~BSTArray and BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:427, include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1805a0 OuterObj1805a0::~OuterObj1805a0
#include "OuterObj1805a0.h"

// Deletes every non-null inner array element before tearing down the outer array and base object.
OuterObj1805a0::~OuterObj1805a0()
{
    for (std::uint32_t i = 0; i < items.base.size; ++i) {
        InnerArray1805a0** data = items.Data();
        if (data[i]) {
            delete data[i];
        }
    }
}
