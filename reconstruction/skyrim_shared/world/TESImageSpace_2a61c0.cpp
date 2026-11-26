// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a61c0 TESImageSpace::ctor
#include "TESImageSpace_2a61c0.h"

TESImageSpace::TESImageSpace()
    : TESForm()
{
    formType = 0x59;
    InitializeData();
}

void TESImageSpace::InitializeData()
{
    data.hdr.eyeAdaptSpeed = 3.0f;
    data.hdr.bloomBlurRadius = 7.0f;
    data.hdr.bloomThreshold = 0.6f;
    data.hdr.bloomScale = 0.5f;
    data.hdr.receiveBloomThreshold = 0.15f;
    data.hdr.white = 0.15f;
    data.hdr.skyScale = 1.5f;
    data.hdr.sunlightScale = 1.8f;
    data.hdr.eyeAdaptStrength = 3.0f;
    data.cinematic.saturation = 0.9f;
    data.cinematic.brightness = 1.5f;
    data.cinematic.contrast = 1.1f;
    data.tint.amount = 0.0f;
    data.tint.color.red = 0.0f;
    data.tint.color.green = 0.0f;
    data.tint.color.blue = 0.0f;
    data.depthOfField.strength = 0.0f;
    data.depthOfField.distance = 0.0f;
    data.depthOfField.range = 0.0f;
}
