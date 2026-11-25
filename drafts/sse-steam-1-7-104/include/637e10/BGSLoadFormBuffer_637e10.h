// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadFormBuffer, BGSLoadFormBuffer::~BGSLoadFormBuffer, buffer, bufferPosition, unk10, unk18, unk1C, unk20: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadEncodedValue: GUESS(low); width-tagged read

#pragma once
#include <cstddef>
#include <cstdint>

class BGSLoadFormBuffer
{
public:
    std::uint32_t ReadEncodedValue();
    virtual ~BGSLoadFormBuffer();
    void* buffer; // 08
    std::uint64_t unk10; // 10
    std::uint32_t unk18; // 18
    std::uint32_t unk1C; // 1C
    std::uint32_t unk20; // 20
    std::uint32_t bufferPosition; // 24
};
static_assert(offsetof(BGSLoadFormBuffer, buffer) == 0x08, "buffer offset");
static_assert(offsetof(BGSLoadFormBuffer, bufferPosition) == 0x24, "position offset");
