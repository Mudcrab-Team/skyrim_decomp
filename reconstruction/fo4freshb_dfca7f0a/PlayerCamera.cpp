// Source exposure: mixed (pinned target listing and sibling hints).
// Origin: adapted sibling source and target listing.
// PlayerCamera::SetSittingRotation: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/PlayerCamera.cpp:80
// PlayerCamera, PlayerCamera::SetSittingRotation: GUESS(low)
// PlayerCamera fields: STANDIN GUESS(low)
// 0x8f8eb0 PlayerCamera::SetSittingRotation
#include "PlayerCamera.h"
void PlayerCamera::SetSittingRotation(float value) { if (state) state->rotation = value; }
