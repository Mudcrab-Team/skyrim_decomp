// Near miss: 13.5 alignment distance | control-flow
// Exposure detail: (community naming and local pinned-image observations).
// Source exposure: mixed
// Code origin: original; no sibling body reused
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf9bc50 NiPSysEmitterCtlr::TargetIsRequiredType

#include "include/f9bc50/NiPSysEmitterCtlr_f9bc50.h"

bool NiPSysEmitterCtlr::TargetIsRequiredType()
{
    if (!NiSingleInterpController::TargetIsRequiredType())
        return false;
    ModifierNode* node = target->modifiers;
    if (!node)
        return false;
    NiPSysModifier** found = nullptr;
    do {
        if (node->modifier && node->modifier->name == modifierName) {
            found = &node->modifier;
            break;
        }
        node = node->next;
    } while (node);
    NiPSysModifier* modifier = found ? *found : nullptr;
    if (!modifier)
        return false;
    const NiRTTI* type = modifier->GetRTTI();
    while (type) {
        if (type == &NiPSysEmitterType)
            return true;
        type = type->base;
    }
    return false;
}
