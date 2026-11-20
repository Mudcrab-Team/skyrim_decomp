// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatBehaviorMisc.cpp:11
// CombatDisableActionController, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8c21b0 CombatDisableActionController::GetClassType
#include "CombatDisableActionController.h"
unsigned int CombatDisableActionController::GetClassType()
{
    static unsigned int uiclassType = CombatObjectBase::GenerateClassType("CombatDisableActionController");
    return uiclassType;

}
