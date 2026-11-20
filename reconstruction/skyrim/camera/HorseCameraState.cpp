// Source exposure: mixed
// Code origin: HorseCameraState::End was adapted from the anonymous fo4-private sibling as labelled (author permission); ~HorseCameraState and SetCameraHandle were written from the pinned image listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash) with no adapted body; declarations from the pinned community headers.
// HorseCameraState::End: SIBLING(fo4-private@1b765c70, author-permission); adapted to target call sequence.
// Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/HorseCameraState.cpp:36
// names: GUESS(low); call identities and method names remain unverified.
// 0x8f6ce0 HorseCameraState::End
// 0x8f7650 HorseCameraState::~HorseCameraState
// 0x8f7100 HorseCameraState::SetCameraHandle
#include "HorseCameraState.h"
void HorseCameraState::End() { ThirdPersonState::End(); atMaxHorseAngle = false; }

// The body is empty. The two vftable stores and the base destructor call follow from the declared
// class layout; the delete-flag test and the sized deallocation are the deleting form
// (cookbook rule 14).
HorseCameraState::~HorseCameraState() {}

void HorseCameraState::SetCameraHandle(unsigned& a_handle) { horseRefHandle = a_handle; }
