// Source exposure: mixed (community-headers, binary-analysis).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3a95d0 BGSScene::ActivateAction
// Adapted bodies: none
#include "BGSScene_3a95d0.h"

int BGSScene::ActivateAction(BGSSceneAction* action)
{
    if (action) {
        if (action->unk14 && !action->unk14b && action->GetType()) {
            action->Unk_10(scene);
        }
    }
    return 1;
}
