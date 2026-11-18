// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// HorseCameraState::End: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/HorseCameraState.cpp:36
// names: GUESS(low); call identities and method names remain unverified.
// 0x8f6ce0 HorseCameraState::End
#include "HorseCameraState.h"
void HorseCameraState::End() { ThirdPersonState::End(); atMaxHorseAngle = false; }
