// Source exposure: mixed (community headers and the pinned image listing).
// Code origin: existing unit plus original reconstruction of Function6379f0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x637580 BGSLoadFormBuffer::GetVersion
// 0x6379f0 BGSLoadFormBuffer::Function6379f0
#include <cstring>
#include "BGSLoadFormBuffer.h"

std::uint8_t BGSLoadFormBuffer::GetVersion()
{
    return version;
}

void BGSLoadFormBuffer::Function6379f0(const LoadBufferHeader* a_header, std::uint32_t a_unk20, std::uint32_t a_position)
{
    std::memcpy(&buffer, a_header, sizeof(LoadBufferHeader));
    unk20 = a_unk20;
    bufferPosition = a_position;
}
