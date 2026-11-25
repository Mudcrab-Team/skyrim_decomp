// Source exposure: mixed (local binary analysis, community declarations and permitted symbol names).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1639a0 ExtraDataList::HasAlias
#include "ExtraDataList_1639a0.h"

bool ExtraDataList::HasAlias()
{
    BSReadLockGuard guard(_lock);
    bool found = false;
    if (_extraData.presence) {
        found = ((_extraData.presence->bits[18] >> 5) & 1) != 0;
    }
    return found;
}
