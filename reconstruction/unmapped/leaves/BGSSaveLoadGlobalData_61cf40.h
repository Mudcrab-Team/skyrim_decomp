// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/BGSSaveLoadGlobalData.cpp:787
// BGSSaveLoadGlobalData, BGSSaveLoadGlobalData::RevertGlobalDataRange, BGSSaveLoadGlobalData::RevertGlobalData, BGSLoadGameBuffer: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// BGSLoadGameBuffer::BGSLoadGameBuffer, BGSLoadGameBuffer::~BGSLoadGameBuffer: SIBLING(fo4-private@1b765c70, author-permission)
// BGSLoadGameBuffer::unknown00: GUESS(low)
#pragma once

class BGSLoadGameBuffer
{
public:
    BGSLoadGameBuffer();
    ~BGSLoadGameBuffer();

    unsigned char unknown00[0x20];  // 00
};

class BGSSaveLoadGlobalData
{
public:
    static void RevertGlobalDataRange(unsigned int a_start, unsigned int a_end, bool a_fullRevert);
    static void RevertGlobalData(unsigned int a_type, BGSLoadGameBuffer* a_buffer, bool a_fullRevert);
};
