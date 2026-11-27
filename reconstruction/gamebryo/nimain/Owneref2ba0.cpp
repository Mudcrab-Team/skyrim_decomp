// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image. Stamped as a twin of matched 0xf0efc0 (gamebryo/nimain/NiShadeProperty_f0efc0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xef2ba0 Owneref2ba0::Functionef2ba0
#include "Owneref2ba0.h"

extern Owneref2ba0* gDefaultShadeProperty_ef2ba0;

// guess: same compiled code as matched 0xf0efc0 apart from relocated fields; its role here is not established.
void Owneref2ba0::Functionef2ba0()
{
    if (auto* old = gDefaultShadeProperty_ef2ba0) {
        gDefaultShadeProperty_ef2ba0 = nullptr;
        // Delete the property when the atomic decrement releases its final reference.
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&old->_refCount), -1) == 1) {
            return old->DeleteThis();
        }
    }
}
