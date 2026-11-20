// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// PlayerCameraTransitionState::Begin: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/PlayerCameraTransitionState.cpp:25
// PlayerCameraTransitionState, PlayerCameraTransitionState::Begin: GUESS(low)
// PlayerCameraTransitionState fields: STANDIN GUESS(low)
// 0x8fd200 PlayerCameraTransitionState::Begin
#include "PlayerCameraTransitionState.h"
void PlayerCameraTransitionState::Begin() { startTime = lastTime; }
