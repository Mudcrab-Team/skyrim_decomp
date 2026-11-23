// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1d1d50 BGSAttackDataForm::SetAttackData
// Adapted bodies: none
#include "BGSAttackDataForm_1d1d50.h"

void BGSAttackDataForm::SetAttackData(AttackData* a_data)
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
