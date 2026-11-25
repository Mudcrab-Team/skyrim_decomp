// Source exposure: mixed (pinned community declarations; private target observations).
// Code origin: original handwritten reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream, NiStream::oStr, NiBinaryStream, NiBinaryStream::_absoluteCurrentPos, NiBinaryStream::_writeFn: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiStream::Functionf5d400, unobservedPrefix, unobserved0C, unobservedReadFn: GUESS(low); method purpose inferred from a one-byte output operation
#pragma once
#include <cstdint>
#include <cstddef>
class NiBinaryStream {
public:
    void* unobservedPrefix;
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t unobserved0C;
    void* unobservedReadFn;
    std::uint32_t (*_writeFn)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};
class NiStream {
public:
    std::uint8_t unobservedPrefix[0x2a0];
    NiBinaryStream* oStr;
    void Functionf5d400(const std::uint8_t& value);
};
static_assert(offsetof(NiStream, oStr) == 0x2a0, "output stream offset");
static_assert(offsetof(NiBinaryStream, _writeFn) == 0x18, "write callback offset");
static_assert(offsetof(NiBinaryStream, _absoluteCurrentPos) == 8, "stream position offset");
