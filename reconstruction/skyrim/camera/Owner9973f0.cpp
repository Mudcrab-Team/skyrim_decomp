// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: Stamped as a twin of matched 0x8f60a0 (skyrim/camera/FreeCameraState): source copied, names replaced by placeholders. Loose twin: member offsets differ from the exemplar and follow this function's code.
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/FreeCameraState.cpp:25
// 0x9973f0 Owner9973f0::Function9973f0
#include "Owner9973f0.h"

// guess: same compiled code as matched 0x8f60a0 apart from relocated fields; its role here is not established.
void Owner9973f0::Function9973f0(NiPoint3& value) const { value.x = translation.x; value.y = translation.y; value.z = translation.z; }
