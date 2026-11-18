// Source exposure: mixed (community headers and pinned-image analysis).
// Drafted by gpt-6.1-sol, Engineer p105 box3. Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x158a180 BSComputeShader::~BSComputeShader
// 0x1589cf0 BSComputeShader::Dispatch
#include "BSComputeShader.h"
BSComputeShader::BSComputeShader() {}
BSComputeShader::~BSComputeShader() { if(name) ReleaseShaderName(name); }

