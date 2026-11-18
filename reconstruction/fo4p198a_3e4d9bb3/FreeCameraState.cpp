// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// FreeCameraState::GetRotation: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/FreeCameraState.cpp:81
// names: GUESS(low); call identities and method names remain unverified.
// 0x8f6060 FreeCameraState::GetRotation
#include "FreeCameraState.h"
void FreeCameraState::GetRotation(NiQuaternion& result) const { NiMatrix3 matrix; matrix.FromEulerAnglesZXY(rotation.y, rotation.x, 0.0f); result.FromRotation(matrix); }
