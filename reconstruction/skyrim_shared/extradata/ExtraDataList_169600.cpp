// Source exposure: mixed (local binary analysis, community declarations and permitted symbol names).
// Code origin: original reconstruction; no adapted external body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// HasLevCreaCalced: SYMBOLS(tesv-2013-map); candidate identity inferred from the queried extra-data type.
// 0x169600 ExtraDataList::HasLevCreaCalced
#include "ExtraDataList_169600.h"

bool ExtraDataList::HasLevCreaCalced()
{
    BSReadLockGuard guard(_lock);
    bool found = false;
    if (_extraData.presence) {
        found = ((_extraData.presence->bits[5] >> 5) & 1) != 0;
    }
    return found;
}
