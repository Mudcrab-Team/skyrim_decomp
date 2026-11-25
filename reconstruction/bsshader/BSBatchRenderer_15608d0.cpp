// Source exposure: mixed (pinned-image observations and public declarations).
// Code origin: original hand-written reconstruction; no adapted body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBatchRenderer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ClearBSShaders: CRASHLOGGER_PDB(59818@2026.10.24)
// BSShader: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// currentShader, currentTechnique, currentPass, EndTechnique, Unk00, Unk01, Unk02: GUESS(low); minimal shader state contract.
// 0x15608d0 BSBatchRenderer::ClearBSShaders
#include "BSBatchRenderer_15608d0.h"
void BSBatchRenderer::ClearBSShaders()
{
    if (currentShader)
        currentShader->EndTechnique(currentTechnique);
    currentShader = nullptr;
    currentTechnique = 0;
    currentPass = nullptr;
}
