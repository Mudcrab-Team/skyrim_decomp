// Source exposure: mixed (community declarations and the pinned image listing).
// Code origin: original reconstruction; community names and declarations as labelled below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSLoadGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once
#include <cstdint>

// gVersion6Byte: GUESS(low); observed one-byte load destination.
extern std::uint8_t gVersion6Byte;
// BGSLoadGameBuffer, GetVersion, LoadDataEndian: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Ownership inferred from the GetVersion slot and observed LoadDataEndian call; name is not byte-match evidence.
class BGSLoadGameBuffer
{
public:
    virtual ~BGSLoadGameBuffer();
    virtual std::uint8_t GetVersion();
    void LoadDataEndian(void* data, std::uint32_t size, std::uint32_t count);
    // 0x9a2980 BGSLoadGameBuffer::ReadVersion6Byte
    // ReadVersion6Byte: GUESS(low); conditional byte read at save version six.
    void ReadVersion6Byte();
};
