// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; fresh draft from the authorized target pack and community declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFloatController: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFloatController::Functionf983f0: GUESS(low); address-based placeholder
// 0xf983f0 NiFloatController::Functionf983f0
// Adapted bodies: none
#include "NiFloatController_f983f0.h"

NiFloatKey* NiFloatController::Functionf983f0(std::uint32_t& count, std::uint32_t& keyType, std::uint8_t& stride)
{
    NiFloatData* animation = data;
    if (animation) {
        count = animation->numKeys;
        keyType = animation->type;
        stride = animation->keySize;
        return animation->keys;
    }
    count = 0;
    keyType = 0;
    stride = 0;
    return nullptr;
}
