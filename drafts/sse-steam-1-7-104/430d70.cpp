// Near miss: 2.0 alignment distance | control-flow
// Code origin: original reconstruction from authorized local binary analysis.
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/o2-fpfast.json
// BSFaceGenKeyframeExclusive: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Reset: GUESS(low); inferred reset operation
// Cookbook: 48
// 0x430d70 BSFaceGenKeyframeExclusive::Reset
#include "BSFaceGenKeyframeExclusive_430d70.h"

void BSFaceGenKeyframeExclusive::Reset()
{
    if (0.0f != unk0C) {
        unk0C = 0.0f;
        Invalidate(-1);
    }
    SetWeight(0.0f);
}
