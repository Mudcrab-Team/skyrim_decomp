// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction using cited declarations and stand-in layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// Adapted bodies: none
// 0xfbfd50 BSPSysInheritVelocityModifier::IsEqual
#include "BSPSysInheritVelocityModifier_fbfd50.h"

// Compares the base modifier state and the velocity vectors and scalar fields.
bool BSPSysInheritVelocityModifier::IsEqual(NiObject* object)
{
    bool equal = NiPSysModifier::IsEqual(object);
    if (equal)
    {
        BSPSysInheritVelocityModifier* other = static_cast<BSPSysInheritVelocityModifier*>(object);
        equal &= (unk38 == other->unk38);
        equal &= (unk44 == other->unk44);
        equal &= (unk50 == other->unk50);
        equal &= (unk54 == other->unk54);
        equal &= (unk58 == other->unk58);
        equal &= (unk5C == other->unk5C);
    }
    return equal;
}
