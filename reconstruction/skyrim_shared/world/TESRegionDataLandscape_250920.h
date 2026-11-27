// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionDataLandscape.cpp:40
// TESRegionDataLandscape, TESRegionDataLandscape::LoadIcon, TESRegionDataLandscape::icon, TESTexture, TESFile: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); stand-ins reduced to what the body touches
// TESRegionData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESFile::GetTESChunkID: CRASHLOGGER_PDB(59818@2026.10.24)
// ICON_ID: SIBLING(fo4-private@1b765c70, author-permission)
// TESTexture::Load: GUESS(low); the call that reads the ICON subrecord into the texture
// unk08: GUESS(low)
#pragma once

#include <cstdint>

class TESFile
{
public:
    std::uint32_t GetTESChunkID();
};

class TESTexture
{
public:
    void Load(TESFile* a_file);
};

class TESRegionData
{
public:
    virtual ~TESRegionData();

    std::uint8_t unk08[8];
};

class TESRegionDataLandscape : public TESRegionData
{
public:
    virtual bool LoadIcon(TESFile* a_mod);

    TESTexture* icon;  // 10
};
static_assert(sizeof(TESRegionDataLandscape) == 0x18, "TESRegionDataLandscape size");
