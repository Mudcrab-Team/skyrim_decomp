// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// NiBinaryStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiBinaryStream::get_info: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BufferInfo: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream::ctor: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// unknown08: GUESS(low)
#pragma once

#include <cstdint>

// BufferInfo: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class BufferInfo
{
public:
    std::uint64_t data;
    std::uint64_t size;
    std::uint64_t capacity;
    std::uint32_t flags;
};

class NiBinaryStream
{
public:
    virtual void get_info(BufferInfo& a_buf);  // compared: 0xeae190
    NiBinaryStream();  // compared: 0xeae130

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    std::uint32_t unknown08;  // 08
    std::uint32_t unknown0C;  // 0C
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
};
static_assert(sizeof(NiBinaryStream) == 0x20, "NiBinaryStream size");
