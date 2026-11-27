// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSExtraData, ExtraCellWaterEnvMap, ExtraCellWaterEnvMap::waterEnvMap, BSExtraData::next: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESTexture: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI STANDIN; only the destructor the function needs
#pragma once

class TESTexture
{
public:
    virtual ~TESTexture();

    void* textureName;
};

class BSExtraData
{
public:
    BSExtraData();
    virtual ~BSExtraData() {}

    BSExtraData* next;
};

class ExtraCellWaterEnvMap : public BSExtraData
{
public:
    ExtraCellWaterEnvMap();

    TESTexture waterEnvMap;
};
static_assert(sizeof(ExtraCellWaterEnvMap) == 0x20, "ExtraCellWaterEnvMap size from the deleting destructor");
