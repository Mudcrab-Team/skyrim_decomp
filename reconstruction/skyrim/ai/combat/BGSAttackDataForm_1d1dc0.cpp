// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1d1dc0 AttackDataPtr::Assign
// Adapted bodies: none
#include "BGSAttackDataForm_1d1dc0.h"

AttackDataPtr& AttackDataPtr::Assign(const AttackDataPtr& a_other)
{
    AttackData* old = ptr;
    AttackData* incoming = a_other.ptr;
    if (old != incoming) {
        if (incoming) {
            incoming->IncRef();
        }
        ptr = incoming;
        if (old) {
            old->DecRef();
        }
    }
    return *this;
}
