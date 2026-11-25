// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x1586f50 BSParabolicCullingProcess::ProcessVisibleObject
#include "BSParabolicCullingProcess_1586f50.h"

void BSParabolicCullingProcess::ProcessVisibleObject(NiAVObject* object, unsigned int argument)
{
    alphaGroupStopIndex = GetHemisphereMask(object->worldBound);
    if (alphaGroupStopIndex) {
        object->methods->OnVisible(object, this, argument);
        if (updateAccumulateFlag)
            object->flags |= NiAVObject::accumulated;
    }
}
