// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1d1dc0 (skyrim/ai/combat/BGSAttackDataForm_1d1dc0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// 0x2a5410 Owner2a5410::Function2a5410
#include "Owner2a5410.h"

// guess: same compiled code as matched 0x1d1dc0 apart from relocated fields; its role here is not established.
Owner2a5410& Owner2a5410::Function2a5410(const Owner2a5410& a_other)
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
