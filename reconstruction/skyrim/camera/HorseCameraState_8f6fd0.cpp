// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// HorseCameraState::Revert: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/HorseCameraState.cpp:113
// names: GUESS(low); call identities and method names remain unverified.
// 0x8f6fd0 HorseCameraState::Revert
#include "HorseCameraState_8f6fd0.h"
void HorseCameraState::Revert(BGSLoadFormBuffer* buffer) { ThirdPersonState::Revert(buffer); atMaxHorseAngle = false; horseRefHandle = nullHandle; horseCurrentDirection = 0.0f; }
