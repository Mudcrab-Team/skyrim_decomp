// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatArea.cpp:466
// CombatAreaReference, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x810130 CombatAreaReference::GetClassType
#include "CombatAreaReference.h"
unsigned int CombatAreaReference::GetClassType()
{
    static unsigned int uiclassType = CombatObjectBase::GenerateClassType("CombatAreaReference");
    return uiclassType;

}
