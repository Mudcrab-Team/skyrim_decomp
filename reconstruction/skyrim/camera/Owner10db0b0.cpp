// Source exposure: mixed
// Code origin: The handle assignment follows the matched HorseCameraState::SetCameraHandle exemplar and writes to the relocated horseRefHandle field.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/HorseCameraState.cpp:36
// 0x10db0b0 Owner10db0b0::Function10db0b0
#include "Owner10db0b0.h"

// guess: same compiled code as matched 0x8f7100 apart from relocated fields; its role here is not established.
void Owner10db0b0::Function10db0b0(unsigned& a_handle) { horseRefHandle = a_handle; }
