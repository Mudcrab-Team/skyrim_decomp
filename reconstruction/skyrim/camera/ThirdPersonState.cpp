// Source exposure: mixed (pinned image listing and authorized sibling hints).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: ThirdPersonState::GetRotation and ::GetTranslation were adapted from the anonymous fo4-private sibling as labelled (author permission); ThirdPersonState::GetFreeRotationMode was written from the pinned image listing by Taylor Turner with Claude Sonnet 5.5 (first drafts by DeepSeek V4.1 Flash) with no adapted body; declarations from the pinned community headers.
// GetRotation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:106
// GetTranslation: Sibling source: fo4-private@1b765c70 src/Game/AI/Camera/ThirdPersonState.cpp:112
// ThirdPersonState, ThirdPersonState::GetRotation, ThirdPersonState::GetTranslation: SIBLING(fo4-private@1b765c70, author-permission)
// 0x8fd870 ThirdPersonState::GetRotation
// 0x8fd880 ThirdPersonState::GetTranslation
// 0x55d590 ThirdPersonState::GetFreeRotationMode
// Adapted bodies: GetRotation and GetTranslation (fo4-private, see the Sibling source lines)
#include "ThirdPersonState.h"

void ThirdPersonState::GetRotation(NiQuaternion& value) const { value = rotation; }
void ThirdPersonState::GetTranslation(NiPoint3& value) const { value.x = translation.x; value.y = translation.y; value.z = translation.z; }
bool ThirdPersonState::GetFreeRotationMode() const { return toggleAnimCam || freeRotationEnabled || playerControls->data.fovSlideMode; }
