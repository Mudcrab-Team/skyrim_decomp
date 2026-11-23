// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x7273d0 ActorProcess::SetDamageRootNode
// Adapted bodies: none
#include "ActorProcess_7273d0.h"

void ActorProcess::SetDamageRootNode(std::int32_t a_index, NiNode* a_node)
{
    if (middleHigh) {
        middleHigh->damageRootNode[a_index] = a_node;
        if (a_index == 1) {
            middleHigh->headNode = nullptr;
        } else if (a_index == 0) {
            middleHigh->torsoNode = nullptr;
        }
    }
}
