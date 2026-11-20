// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: declarations written by hand from the community headers and the local listings; a minimal stand-in layout.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0xeae180 NiBinaryStream::tell
// 0xeae4a0 NiBinaryStream::~NiBinaryStream
// NiBinaryStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiBinaryStream::tell, NiBinaryStream::~NiBinaryStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiBinaryStream::_absoluteCurrentPos: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk_01, Unk_02: GUESS(low); placeholder virtual slots that keep tell at slot 0x03
// pad0C, pad10, pad18: GUESS(low); unexamined members that bring the object to the 0x20 bytes the image frees
#pragma once

#include <cstdint>

class NiBinaryStream
{
public:
    NiBinaryStream();
    virtual ~NiBinaryStream();  // 00
    virtual void Unk_01();
    virtual void Unk_02();
    virtual std::uint32_t tell() const;  // 03

    std::uint32_t _absoluteCurrentPos;  // 08
    std::uint32_t pad0C;  // 0C
    std::uint64_t pad10;  // 10
    std::uint64_t pad18;  // 18
};
