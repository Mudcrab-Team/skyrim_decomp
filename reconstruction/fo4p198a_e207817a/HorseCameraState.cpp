// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// HorseCameraState::GetFreeRotationMode: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/HorseCameraState.cpp:43
// names: GUESS(low); field meaning and singleton identity remain unverified.
// 0x8f76a0 HorseCameraState::GetFreeRotationMode
#include "HorseCameraState.h"
bool HorseCameraState::GetFreeRotationMode() const { return freeRotationEnabled || playerControls->data.fovSlideMode; }
