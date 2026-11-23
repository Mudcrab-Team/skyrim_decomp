// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x875510 CombatBehaviorTreeNode::Function875510
// Adapted bodies: none
#include "CombatBehaviorTreeNode_875510.h"

std::uint32_t CombatBehaviorTreeNode::Function875510(const std::uint64_t* a_key)
{
    for (std::uint32_t i = 0; i < unk20; ++i) {
        if (unk18[i]->unk08 == *a_key) {
            return i;
        }
    }
    return 0xFFFFFFFF;
}
