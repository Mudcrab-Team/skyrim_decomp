// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetRotation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:106
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:112
// ThirdPersonState, ThirdPersonState::GetRotation, ThirdPersonState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8fd870 ThirdPersonState::GetRotation
// 0x8fd880 ThirdPersonState::GetTranslation
#include "ThirdPersonState.h"

void ThirdPersonState::GetRotation(NiQuaternion& value) const { value = rotation; }
void ThirdPersonState::GetTranslation(NiPoint3& value) const { value.x = translation.x; value.y = translation.y; value.z = translation.z; }
