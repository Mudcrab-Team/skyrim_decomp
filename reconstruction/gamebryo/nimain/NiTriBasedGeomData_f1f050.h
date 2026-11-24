// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiTriBasedGeomData: EXE_RTTI
// NiGeometryData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiGeometryData: STANDIN EXE_RTTI; only the members and destructors the function needs
#pragma once

class NiGeometryData
{
public:
    NiGeometryData();
    virtual ~NiGeometryData();
};

class NiTriBasedGeomData : public NiGeometryData
{
public:
    NiTriBasedGeomData();
    ~NiTriBasedGeomData() override {}

    char unk08[0x68];
};
static_assert(sizeof(NiTriBasedGeomData) == 0x70, "NiTriBasedGeomData size from the deleting destructor");
