// Source exposure: mixed (community-headers, binary-analysis).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x3a99a0 BGSScene::PrepareAction
// Adapted bodies: none
#include "BGSScene_3a99a0.h"

int BGSScene::PrepareAction(BGSSceneAction* action)
{
    if (action->unk14 & 1) {
        if (!action->Loops()) {
            action->unk14 |= 2;
        }
        action->Unk_11(scene);
    }
    action->Unk_0D(scene);
    return 1;
}
