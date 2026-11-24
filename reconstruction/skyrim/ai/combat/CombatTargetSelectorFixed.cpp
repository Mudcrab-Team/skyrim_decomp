// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: written for this reconstruction from the listing; names from the header.
// Adapted bodies: none
// 0x862b50 CombatTargetSelectorFixed::Function862b50
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatTargetSelector.cpp:134
// CombatTargetSelectorFixed, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8632b0 CombatTargetSelectorFixed::GetClassType
// Drafted by v-macrev, assisted by claude-haiku-5-5.
#include "CombatTargetSelectorFixed.h"
unsigned int CombatTargetSelectorFixed::GetClassType()
{
    static unsigned int uiclassType = CombatObjectBase::GenerateClassType("CombatTargetSelectorFixed");
    return uiclassType;

}

unsigned int* CombatTargetSelectorFixed::Function862b50(unsigned int* a_out)
{
    *a_out = m_unk18;
    return a_out;
}
