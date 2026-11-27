// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTriShape, NiTriBasedGeom: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiTriBasedGeom: STANDIN EXE_RTTI; only its out-of-line destructor is declared
#pragma once

class NiTriBasedGeom
{
public:
    NiTriBasedGeom();
    virtual ~NiTriBasedGeom();
};

class NiTriShape : public NiTriBasedGeom
{
public:
    NiTriShape();
    ~NiTriShape() override {}

    char unk08[0x130];
};
static_assert(sizeof(NiTriShape) == 0x138, "NiTriShape size from the deleting destructor");
