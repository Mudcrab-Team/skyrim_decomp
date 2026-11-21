// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xefe1a0 NiPointLight::CopyMembers
// Adapted bodies: none
#include "NiPointLight_efe1a0.h"

void NiPointLight::CopyMembers(NiPointLight* dest)
{
    NiLight::CopyMembers(dest);
    dest->constAttenuation = constAttenuation;
    dest->linearAttenuation = linearAttenuation;
    dest->quadraticAttenuation = quadraticAttenuation;
}
