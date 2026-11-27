// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x157320 ExtraDataList::GetPreviousExtraDataToTypeUnsafe
// Adapted bodies: none
#include "ExtraDataList_157320.h"

// Return the node preceding the first entry matching the given extra-data type without locking.
BSExtraData* ExtraDataList::GetPreviousExtraDataToTypeUnsafe(std::uint32_t type) const
{
    if (!_extraData.presence) {
        return nullptr;
    }

    const std::uint32_t byteIndex = type >> 3;
    if (byteIndex >= 0x17u) {
        return nullptr;
    }

    if ((_extraData.presence->bits[byteIndex] & (1u << (type & 7u))) == 0) {
        return nullptr;
    }

    BSExtraData* prev = nullptr;
    for (BSExtraData* cur = _extraData.data; cur != nullptr; cur = cur->next) {
        if (cur->GetType() == type) {
            break;
        }
        prev = cur;
    }
    return prev;
}
