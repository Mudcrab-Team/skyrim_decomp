// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; declarations from the cited sibling.
// SPDX-License-Identifier: CC0-1.0
// 0x862b50 CombatTargetSelectorFixed::Function862b50
// Adapted bodies: none
// Function862b50: GUESS(low)
// data: GUESS(low)
// BSFixedString: STANDIN GUESS(low)
// CombatTargetSelectorFixed, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatTargetSelector.cpp:134
// 0x8632b0 CombatTargetSelectorFixed::GetClassType
#include "CombatTargetSelectorFixed.h"
unsigned int* CombatTargetSelectorFixed::Function862b50(unsigned int* out) const
{
    *out = data;
    return out;
}
unsigned int CombatTargetSelectorFixed::GetClassType()
{
    static unsigned int uiclassType = CombatObjectBase::GenerateClassType("CombatTargetSelectorFixed");
    return uiclassType;

}
