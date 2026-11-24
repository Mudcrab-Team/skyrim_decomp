// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSPSysStripUpdateModifier: EXE_RTTI
// NiPSysModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiPSysModifier: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class NiPSysModifier
{
public:
    NiPSysModifier();
    virtual ~NiPSysModifier();
};

class BSPSysStripUpdateModifier : public NiPSysModifier
{
public:
    BSPSysStripUpdateModifier();
    ~BSPSysStripUpdateModifier() override {}

    char unk08[0x30];
};
static_assert(sizeof(BSPSysStripUpdateModifier) == 0x38, "BSPSysStripUpdateModifier size from the deleting destructor");
