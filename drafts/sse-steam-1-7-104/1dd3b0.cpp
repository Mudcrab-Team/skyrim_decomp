// Near miss: 23.5 alignment distance | control-flow
// Exposure detail: (local target observations; community declarations).
// Source exposure: mixed
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESActorBaseData, TESActorBaseData::GetLevel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Adapted bodies: none.
// Cookbook: 16
// 0x1dd3b0 TESActorBaseData::GetLevel

#include "include/1dd3b0/TESActorBaseData_1dd3b0.h"

std::uint16_t TESActorBaseData::GetLevel() const
{
    if (!TestBit(actorData.actorBaseFlags, 7)) {
        return actorData.level; } else {
    std::int64_t playerLevel = 1;
    if (playerSingleton->objectReference && playerSingleton)
        playerLevel = playerSingleton->objectReference->actorBaseData.actorData.level;
    std::uint16_t result = static_cast<std::uint16_t>(static_cast<float>(actorData.level) * 0.001f * static_cast<float>(playerLevel));
    if (actorData.calcLevelMin > result)
        result = actorData.calcLevelMin;
    auto v0 = actorData.calcLevelMax;
    if (v0) { if (result > v0)
        result = v0; }
    return result;
}
}
