// Source exposure: mixed (local binary analysis, community declarations and permitted symbol names).
// Code origin: original reconstruction; no adapted external body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HasLeveledItem: SYMBOLS(tesv-2013-map); candidate identity inferred from the queried extra-data type.
// 0x164840 ExtraDataList::HasLeveledItem
#include "ExtraDataList_164840.h"

bool ExtraDataList::HasLeveledItem()
{
    BSReadLockGuard guard(_lock);
    bool found = false;
    if (_extraData.presence) {
        found = ((_extraData.presence->bits[5] >> 6) & 1) != 0;
    }
    return found;
}
