// Source exposure: mixed (local binary analysis, community declarations and permitted symbol names).
// Code origin: original reconstruction; no adapted external body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetCanNotWear: SYMBOLS(tesv-2013-map); candidate identity inferred from the queried extra-data type.
// 0x1647c0 ExtraDataList::GetCanNotWear
#include "ExtraDataList_1647c0.h"

bool ExtraDataList::GetCanNotWear()
{
    BSReadLockGuard guard(_lock);
    bool found = false;
    if (_extraData.presence) {
        found = ((_extraData.presence->bits[7] >> 5) & 1) != 0;
    }
    return found;
}
