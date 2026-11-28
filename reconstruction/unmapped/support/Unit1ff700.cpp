// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x1ff700 Unit1ff700::FindChild1ff700
// Adapted bodies: none
#include "Unit1ff700.h"

// Scans a_node's children for the first entry matching g_rtti1ff700 whose flag matches a_flag.
// guess: a member that reads no member, so the owning class and its role are unknown.
Child1ff700* Unit1ff700::FindChild1ff700(const Node1ff700* a_node, bool a_flag) const
{
    Child1ff700* result = nullptr;
    if (a_node) {
        for (std::uint32_t i = 0; i < a_node->childCount && !result; ++i) {
            Child1ff700* child = a_node->children[i];
            if (child && child->GetRtti() == &g_rtti1ff700) {
                result = child;
                if ((a_flag && !child->flag) || (!a_flag && child->flag)) {
                    result = nullptr;
                }
            }
        }
    }
    return result;
}
