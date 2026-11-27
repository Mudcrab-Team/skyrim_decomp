// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSDoorHavokController: EXE_RTTI
// NiTimeController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiTimeController: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class NiTimeController
{
public:
    NiTimeController();
    virtual ~NiTimeController();
};

class BSDoorHavokController : public NiTimeController
{
public:
    BSDoorHavokController();
    ~BSDoorHavokController() override {}

    char unk08[0x48];
};
static_assert(sizeof(BSDoorHavokController) == 0x50, "BSDoorHavokController size from the deleting destructor");
