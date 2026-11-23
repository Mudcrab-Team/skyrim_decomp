// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction written for this project from the pinned image listing; no body copied or adapted.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none declared; TESEyes::InitializeData is reported close to the sibling body named below.
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Character/TESEyes.cpp:27 (TESEyes::InitializeData is close to it, similarity 0.75 by tools/check_origin.py)
// TESEyes::InitializeData: SIBLING(fo4-private@1b765c70, author-permission)
// 0x3b32b0 TESEyes::~TESEyes
// 0x3b2fb0 TESEyes::InitializeData
#include "TESEyes.h"

// TESEyes::~TESEyes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
TESEyes::~TESEyes() {}

// TESEyes::InitializeData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void TESEyes::InitializeData()
{
    flags = 0;
}
