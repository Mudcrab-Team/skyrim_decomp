// Source exposure: mixed (community headers; the pinned image listing; a permitted sibling body).
// Code origin: statement shape adapted from a sibling body, offsets and names checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2249c0 BSFadeNode::SetControllerFloatFieldRecursive
// Adapted bodies: BSFadeNode::SetControllerFloatFieldRecursive from the Fallout 3 decompilation (controller list walk, then recursion into children of the matching runtime type); names are not taken
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:7254
#include "BSFadeNode_2249c0.h"

// Sets the phase of every controller on the node, then does the same for each child that is a fade node.
void BSFadeNode::SetControllerFloatFieldRecursive(NiNode* a_node, float a_value)
{
    if (a_node == nullptr) {
        return;
    }

    NiTimeController* controller = a_node->controllers;
    while (controller != nullptr) {
        controller->phase = a_value;
        controller = controller->next;
    }

    for (std::uint32_t i = 0; i < a_node->children._freeIdx; ++i) {
        NiNode* child = a_node->children._data[i];
        if (child != nullptr) {
            const NiRTTI* rtti = child->GetRTTI();
            while (rtti != nullptr) {
                if (rtti == &NiRTTI_BSFadeNode) {
                    SetControllerFloatFieldRecursive(child, a_value);
                    break;
                }
                rtti = rtti->baseRTTI;
            }
        }
    }
}
