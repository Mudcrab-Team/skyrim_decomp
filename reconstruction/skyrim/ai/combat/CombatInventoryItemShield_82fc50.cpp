// Source exposure: mixed (authorized target analysis and anonymous permitted sibling source).
// Origin: adapted from the cited game-code body under anonymous author permission.
// Licence: fo4-private reused with author permission conditional on anonymity.
// BSFixedString: STANDIN GUESS(low)
// data: GUESS(low)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Combat/CombatInventoryItem.cpp:359
// CombatInventoryItemShield, GetClassType: SIBLING(fo4-private@1b765c70, author-permission)
// 0x82fc50 CombatInventoryItemShield::GetClassType
#include "CombatInventoryItemShield_82fc50.h"
unsigned int CombatInventoryItemShield::GetClassType()
{
    static unsigned int uiclassType = CombatObjectBase::GenerateClassType("CombatInventoryItemShield");
    return uiclassType;

}
