// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf04400 NiDirectionalLight::CopyMembers
// Adapted bodies: none
#include "NiDirectionalLight_f04400.h"

void NiDirectionalLight::CopyMembers(NiDirectionalLight* dest)
{
    NiLight::CopyMembers(dest);
    dest->directionX = directionX;
    dest->directionY = directionY;
    dest->directionZ = directionZ;
}
