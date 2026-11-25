// Source exposure: mixed (pinned-image observations and labelled naming/declaration sources).
// Code origin: original handwritten implementation from pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream, NiBinaryStream, iStr, _absoluteCurrentPos, _readFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream, NiBinaryStream: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN; partial layouts preserving observed fields.
// Functionf08fd0: GUESS(low); byte-oriented input helper inferred from accesses.
#pragma once
#include <cstdint>
#include <cstddef>

class NiBinaryStream
{
public:
    void* unknown00;
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t unknown0C;
    std::uint32_t (*_readFn)(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};

class NiStream
{
public:
    std::uint32_t Functionf08fd0(void* buffer, std::uint32_t bytes);
    std::uint8_t unknown00[0x298];
    NiBinaryStream* iStr;
};
static_assert(offsetof(NiStream, iStr) == 0x298, "input stream offset");
static_assert(offsetof(NiBinaryStream, _absoluteCurrentPos) == 8, "stream position offset");
static_assert(offsetof(NiBinaryStream, _readFn) == 0x10, "read callback offset");
