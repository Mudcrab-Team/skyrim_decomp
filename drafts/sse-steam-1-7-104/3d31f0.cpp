// Near miss: 39.0% | register-schedule
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementation based on the pinned game build; names as labelled in the header.
// Adapted bodies: none
// 0x3d31f0 TESQuest::GetAlias
#include "include/3d31f0/TESQuest_3d31f0.h"

// The quest's alias with the given alias ID, or null when it has none.
BGSBaseAlias* TESQuest::GetAlias(std::uint32_t a_aliasID)
{
    for (std::uint32_t i = 0; i < aliases.size(); ++i) {
        BGSBaseAlias* alias = aliases[i];
        if (alias && alias->aliasID == a_aliasID) {
            return alias;
        }
    }
    return nullptr;
}
