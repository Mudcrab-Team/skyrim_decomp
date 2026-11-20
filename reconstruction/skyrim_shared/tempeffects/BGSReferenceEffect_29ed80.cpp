// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x29ed80 BGSReferenceEffect::~BGSReferenceEffect
// 0x29edc0 BGSReferenceEffect::ClearData
// Adapted bodies: none
#include "BGSReferenceEffect_29ed80.h"

// Emit the virtual deleting destructor with the class constructor.
BGSReferenceEffect::BGSReferenceEffect() = default;

BGSReferenceEffect::~BGSReferenceEffect()
{

}

void BGSReferenceEffect::ClearData()
{
    artObject = nullptr;
    effectShader = nullptr;
    flags = 0;
}
