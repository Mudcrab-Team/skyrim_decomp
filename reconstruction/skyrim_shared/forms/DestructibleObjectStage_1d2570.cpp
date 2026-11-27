// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0x1d2570 DestructibleObjectStage::CheckReplacementModel
// Adapted bodies: DestructibleObjectStage::CheckReplacementModel from fo4-private@1b765c70 src/Shared/FormComponents/BGSDestructibleObjectForm.cpp:45 (see the header)
#include "DestructibleObjectStage_1d2570.h"

void DestructibleObjectStage::CheckReplacementModel()
{
    if (replacementModel && !replacementModel->model.QLength())
    {
        delete replacementModel;
        replacementModel = nullptr;
    }
}
