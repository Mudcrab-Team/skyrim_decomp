// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original; partial layouts preserve the observed fields
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream, NiBinaryStream, oStr, _absoluteCurrentPos, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream, NiBinaryStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); partial layouts preserving observed fields.
// Functionf09010: GUESS(low); byte-oriented output dispatch inferred from accesses.
#pragma once

#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    void* unknown00;
    std::uint32_t _absoluteCurrentPos;  // 0x08
    std::uint32_t unknown0c;
    void* unknown10;
    std::uint32_t (*_writeFn)(NiBinaryStream*, const void*, std::uint32_t,
        std::uint32_t*, std::uint32_t);  // 0x18
};

class NiStream
{
public:
    std::uint32_t Functionf09010(const void* buffer, std::uint32_t bytes);

    std::uint8_t unknown00[0x2a0];
    NiBinaryStream* oStr;  // 0x2a0
};
static_assert(offsetof(NiStream, oStr) == 0x2a0, "output stream offset");
static_assert(offsetof(NiBinaryStream, _absoluteCurrentPos) == 8, "stream position offset");
static_assert(offsetof(NiBinaryStream, _writeFn) == 0x18, "write callback offset");
