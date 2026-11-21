// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatTargetSelector.cpp:134
// CombatTargetSelectorFixed, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8632b0 CombatTargetSelectorFixed::GetClassType
#include "CombatTargetSelectorFixed.h"
unsigned int CombatTargetSelectorFixed::GetClassType()
{
    static unsigned int uiclassType = CombatObjectBase::GenerateClassType("CombatTargetSelectorFixed");
    return uiclassType;

}
