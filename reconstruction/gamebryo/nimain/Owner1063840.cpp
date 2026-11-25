// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image. Stamped as a twin of matched 0xf0efc0 (gamebryo/nimain/NiShadeProperty_f0efc0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x1063840 Owner1063840::Function1063840
#include "Owner1063840.h"

extern Owner1063840* gDefaultShadeProperty_1063840;

// guess: same compiled code as matched 0xf0efc0 apart from relocated fields; its role here is not established.
void Owner1063840::Function1063840()
{
    if (auto* old = gDefaultShadeProperty_1063840) {
        gDefaultShadeProperty_1063840 = nullptr;
        // Delete the property when the atomic decrement releases its final reference.
        if (_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(&old->_refCount), -1) == 1) {
            return old->DeleteThis();
        }
    }
}
