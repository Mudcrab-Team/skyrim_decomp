// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSUnloadedFormBuffer.cpp:73
// 0x63b260 BGSUnloadedFormBuffer::GetDataSize
// Adapted bodies: BGSUnloadedFormBuffer::GetDataSize from the sibling source named above
#include "BGSUnloadedFormBuffer_63b260.h"

unsigned int BGSUnloadedFormBuffer::GetDataSize() const
{
    char* data = buffer;
    if (!data)
        return 0;
    unsigned int flags = static_cast<unsigned char>(*data);
    unsigned int dataSize = 0;
    LoadGameSizeFromBuffer(data + 2, dataSize, static_cast<SIZE_TYPE>(flags >> 6));
    return dataSize;
}
