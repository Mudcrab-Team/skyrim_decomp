// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0x184980 Obj184980::IsNotEqual
// Adapted bodies: none.
#include "Obj184980.h"

// Returns true if the two linked lists differ in non-null element count or membership.
bool Obj184980::IsNotEqual(const Obj184980* a_rhs) const
{
    std::uint32_t lhsCount = 0;
    for (const Node184980* n = &list10; n; n = n->next) {
        if (n->item) {
            ++lhsCount;
        }
    }
    std::uint32_t rhsCount = 0;
    for (const Node184980* n = &a_rhs->list10; n; n = n->next) {
        if (n->item) {
            ++rhsCount;
        }
    }
    if (lhsCount != rhsCount) {
        return true;
    }
    for (const Node184980* rn = &a_rhs->list10; rn; rn = rn->next) {
        if (!rn->next && !rn->item) {
            break;
        }
        bool found = false;
        for (const Node184980* ln = &list10; ln; ln = ln->next) {
            if (ln->item == rn->item) {
                found = true;
                break;
            }
        }
        if (!found) {
            return true;
        }
    }
    return false;
}
