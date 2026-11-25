// Source exposure: mixed (pinned-image observations; community-generated names).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// 0x5c3130 RefAttachTechniqueInput::SetAttachRoot
// Adapted bodies: none
// Cookbook: 0x5c3130 29
#include "RefAttachTechniqueInput_5c3130.h"

void RefAttachTechniqueInput::SetAttachRoot(NiAVObject* value)
{
    AttachRootPointer root(value);
    attachRoot = root;
}
