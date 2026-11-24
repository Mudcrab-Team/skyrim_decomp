// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// RaceSexCamera, TESCamera: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESCamera: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class TESCamera
{
public:
    TESCamera();
    virtual ~TESCamera();
};

class RaceSexCamera : public TESCamera
{
public:
    RaceSexCamera();
    ~RaceSexCamera() override {}

    char unk08[0x50];
};
static_assert(sizeof(RaceSexCamera) == 0x58, "RaceSexCamera size from the deleting destructor");
