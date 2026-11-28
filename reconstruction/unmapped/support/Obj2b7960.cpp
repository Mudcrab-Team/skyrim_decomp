// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj2b7960::Function2b7960, treated as adapted: shaped like BSTArray::release (CharmedBaryon/CommonLibSSE-NG@b93280e include/RE/B/BSTArray.h:641, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2b7960 Obj2b7960::Function2b7960
#include "Obj2b7960.h"

// Clears the global array and optionally deallocates its storage.
void Obj2b7960::Function2b7960(bool a_deallocate)
{
    if (g_array2b7960.data) {
        if (a_deallocate) {
            g_array2b7960.Deallocate();
        }
        g_array2b7960.size = 0;
    }
}
