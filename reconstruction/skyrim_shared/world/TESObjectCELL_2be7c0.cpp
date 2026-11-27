// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original reconstruction from observed query and type checks.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none.
// 0x2be7c0 TESObjectCELL::Function2be7c0
#include "TESObjectCELL_2be7c0.h"

// Guess: test whether the cell's lock list contains at least one form.
bool TESObjectCELL::Function2be7c0()
{
    TESForm* list = extraList.QueryLockList();
    if (list) {
        if (list->formType == 0x5B) {
            return static_cast<BGSListForm*>(list)->GetCount() != 0;
        }
        return true;
    }
    return false;
}
