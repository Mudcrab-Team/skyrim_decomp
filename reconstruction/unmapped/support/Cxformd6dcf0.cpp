// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Cxformd6dcf0::Cxformd6dcf0, treated as adapted: shaped like GRenderer::Cxform::SetIdentity (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/G/GRenderer.cpp:98, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xd6dcf0 Cxformd6dcf0::Cxformd6dcf0
// CI hash: 0xd6dcf0 ??0Cxformd6dcf0@@QEAA@XZ
#include "Cxformd6dcf0.h"

// Initializes the 4x2 color transform matrix to identity (scale 1, offset 0 per channel).
Cxformd6dcf0::Cxformd6dcf0()
{
    matrix[0][0] = 1.0f;
    matrix[0][1] = 0.0f;
    matrix[1][0] = 1.0f;
    matrix[1][1] = 0.0f;
    matrix[2][0] = 1.0f;
    matrix[2][1] = 0.0f;
    matrix[3][0] = 1.0f;
    matrix[3][1] = 0.0f;
}
