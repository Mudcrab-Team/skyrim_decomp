// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSUnloadedFormBuffer.cpp:85
// 0x63b2a0 BGSUnloadedFormBuffer::GetUncompressedSize
// Adapted bodies: BGSUnloadedFormBuffer::GetUncompressedSize from the sibling source named above
#include "BGSUnloadedFormBuffer_63b2a0.h"

unsigned int BGSUnloadedFormBuffer::GetUncompressedSize() const
{
    if (!buffer)
        return 0;
    SIZE_TYPE sizeType = static_cast<SIZE_TYPE>(static_cast<unsigned char>(*buffer) >> 6);
    char* data = buffer + 2;
    unsigned int dataSize = 0;
    unsigned int sizeOffset = LoadGameSizeFromBuffer(data, dataSize, sizeType);
    unsigned int uncompressedSize = 0;
    LoadGameSizeFromBuffer(data + sizeOffset, uncompressedSize, sizeType);
    if (uncompressedSize)
        return uncompressedSize;
    return dataSize;
}
