// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSUnloadedFormBuffer.cpp:85
// BGSUnloadedFormBuffer::GetUncompressedSize: SIBLING(fo4-private@1b765c70, author-permission)
// BGSUnloadedFormBuffer, BGSUnloadedFormBuffer::buffer, SIZE_TYPE, LoadGameSizeFromBuffer: GUESS(low); the names are the ones the sibling body uses, the layouts come from the listing
#pragma once

enum SIZE_TYPE : int
{
    kSizeTypeByte = 0
};

unsigned int LoadGameSizeFromBuffer(char* a_buffer, unsigned int& a_size, SIZE_TYPE a_sizeType);

class BGSUnloadedFormBuffer
{
public:
    unsigned int GetUncompressedSize() const;

    char* buffer;  // 00
};
