// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Origin: SIBLING(fo4-private@1b765c70, author-permission)
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/FreeCameraState.cpp:25
// FreeCameraState, FreeCameraState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8f60a0 FreeCameraState::GetTranslation
#include "FreeCameraState.h"

void FreeCameraState::GetTranslation(NiPoint3& value) const { value.x = translation.x; value.y = translation.y; value.z = translation.z; }
