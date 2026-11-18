// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted permitted anonymous sibling body with a target-specific predicate.
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:2032
// PlayerCharacter, PlayerCharacter::HasBeenAttacked, PlayerCharacter::IsPowerAttackCoolingDown, PlayerCharacter::SetBeenAttacked: GUESS(low)
// PlayerCharacter fields: STANDIN GUESS(low)
// PlayerCharacter::GetCannibal, PlayerCharacter::GetVampireFeed: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/PlayerCharacter.cpp:1222,1238
// 0x75d430 PlayerCharacter::IsPowerAttackCoolingDown
#include "PlayerCharacter.h"
bool PlayerCharacter::IsPowerAttackCoolingDown() const { return !(timer <= 0.0f); }
