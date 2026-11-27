// Near miss: 14.5 alignment distance | control-flow
// 0x833510 CombatMagicCaster::GetMagicTarget
// Code origin: original reconstruction from local binary analysis; community declarations only.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// CombatMagicCaster, CombatController, GetMagicTarget, GetDelivery, magicItem, attackerHandle, targetHandle, handleCount, cachedAttacker, cachedTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TargetResult: GUESS(low); explicit handle/pointer result rather than the community void pointer.
#include "include/833510/CombatMagicCaster_833510.h"

TargetResult CombatMagicCaster::GetMagicTarget(const CombatController* controller) const
{
    int delivery = magicItem->vtable->GetDelivery(magicItem);
    unsigned int handle;
    Actor* actor = nullptr;
    if (delivery == 0) {
        if (controller->handleCount) {
            actor = controller->cachedAttacker;
            handle = 0;
        } else {
            handle = controller->attackerHandle;
        }
    } else {
        if (controller->handleCount) {
            actor = controller->cachedTarget;
            handle = 0;
        } else {
            handle = controller->targetHandle;
        }
    }
    return {handle, actor};
}
