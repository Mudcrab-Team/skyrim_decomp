// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x417370 Sky::UnloadAllTextures
// Adapted bodies: Sky::UnloadAllTextures follows fo4-private@1b765c70 src/Shared/Sky/Sky.cpp:308
#include "Sky_417370.h"

void Sky::UnloadAllTextures()
{
    if (clouds)
    {
        clouds->RemoveTextures();
        clouds->ClearTransTextures();
    }
    if (masser)
        masser->RemoveTextures();
    if (secunda)
        secunda->RemoveTextures();
    if (sun)
        sun->RemoveTextures();
    if (stars)
        stars->UnloadGeometry();
}
