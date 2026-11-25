// Source exposure: mixed (pinned-image observations and public declarations).
// Code origin: original hand-written reconstruction; no adapted body.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSBatchRenderer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// ClearBSShaders: CRASHLOGGER_PDB(59818@2026.10.24)
// BSShader: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// currentShader, currentTechnique, currentPass, EndTechnique, Unk00, Unk01, Unk02: GUESS(low); minimal shader state contract.
// 0x15608d0 BSBatchRenderer::ClearBSShaders
#pragma once
#include <cstdint>
class BSShader {
public:
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void EndTechnique(std::uint32_t technique);
};
class BSBatchRenderer {
public:
    static void ClearBSShaders();
    static BSShader* currentShader;
    static std::uint32_t currentTechnique;
    static void* currentPass;
};
