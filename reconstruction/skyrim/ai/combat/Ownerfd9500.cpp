// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1d1d50 (skyrim/ai/combat/BGSAttackDataForm_1d1d50): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// SPDX-License-Identifier: CC0-1.0
// 0xfd9500 Ownerfd9500::Functionfd9500
#include "Ownerfd9500.h"

// guess: same compiled code as matched 0x1d1d50 apart from relocated fields; its role here is not established.
void Ownerfd9500::Functionfd9500(AttackData* a_data)
{
    AttackData* old = attackData;
    if (old != a_data) {
        if (a_data) {
            a_data->IncRef();
        }
        attackData = a_data;
        if (old) {
            old->DecRef();
        }
    }
}
