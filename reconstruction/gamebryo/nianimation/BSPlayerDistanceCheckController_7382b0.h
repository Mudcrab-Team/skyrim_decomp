// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPlayerDistanceCheckController: EXE_RTTI
// NiTimeController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiTimeController: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class NiTimeController
{
public:
    NiTimeController();
    virtual ~NiTimeController();
};

class BSPlayerDistanceCheckController : public NiTimeController
{
public:
    BSPlayerDistanceCheckController();
    ~BSPlayerDistanceCheckController() override {}

    char unk08[0x58];
};
static_assert(sizeof(BSPlayerDistanceCheckController) == 0x60, "BSPlayerDistanceCheckController size from the deleting destructor");
