// Source exposure: mixed (community headers and the pinned image).
// Code origin: existing unit plus original reconstruction of Function6379f0.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadFormBuffer, BGSLoadFormBuffer::GetVersion, version: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// Function6379f0, LoadBufferHeader, unknown28, unknown4c: GUESS(low)
#pragma once

#include <cstdint>
#include "BGSLoadGameBuffer.h"

struct LoadBufferHeader
{
    void* buffer;
    std::uint64_t unk08;
    std::uint32_t unk10;
    std::uint32_t unk14;
};
static_assert(sizeof(LoadBufferHeader) == 0x18, "LoadBufferHeader size");

class BGSLoadFormBuffer : public BGSLoadGameBuffer
{
public:
    virtual std::uint8_t GetVersion();  // compared: 0x637580
    void Function6379f0(const LoadBufferHeader* a_header, std::uint32_t a_unk20, std::uint32_t a_position);

    std::uint8_t unknown28[0x23];  // 28
    std::uint8_t version;  // 4b
    std::uint8_t unknown4c[0x4];  // 4c
};
static_assert(sizeof(BGSLoadFormBuffer) == 0x50, "BGSLoadFormBuffer size");
