// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatAimController.cpp:41
// CombatAimController, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x80da00 CombatAimController::GetClassType
#include "CombatAimController_80da00.h"
unsigned int CombatAimController::GetClassType()
{
    static unsigned int uiclassType = CombatObjectBase::GenerateClassType("CombatAimController");
    return uiclassType;

}
