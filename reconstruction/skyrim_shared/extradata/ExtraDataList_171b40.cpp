// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original reconstruction; reduced declarations from CommonLibSSE-NG.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none.
// 0x171b40 ExtraDataList::GetTalkToPlayer
#include "ExtraDataList_171b40.h"
bool ExtraDataList::GetTalkToPlayer()
{
    BSReadLockGuard guard(_lock);
    bool found = false;
    if (_extraData.presence) {
        found = ((_extraData.presence->bits[15] >> 4) & 1) != 0;
    }
    return found;
}
