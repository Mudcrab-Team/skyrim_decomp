// BSFile, sub: GUESS(low)
// _absoluteCurrentPos, _pad0C, _readFn, _writeFn, bufferAllocSize, bufferReadSize, pos, pad2C, buffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Inferred names: GUESS(low)
// Origin: original body; declarations adapted from CommonLibSSE-NG, MIT.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)

#pragma once
#include <cstdint>
// BSFile, sub: GUESS(low)
// _absoluteCurrentPos, _pad0C, _readFn, _writeFn, bufferAllocSize, bufferReadSize, pos, pad2C, buffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class BSFile {
public:
    virtual ~BSFile();
    void sub();
    using ReadFn = std::uint32_t (*)(void*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t (*)(void*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    std::uint32_t _absoluteCurrentPos;
    std::uint32_t _pad0C;
    ReadFn _readFn;
    WriteFn _writeFn;
    std::uint32_t bufferAllocSize;
    std::uint32_t bufferReadSize;
    std::uint32_t pos;
    std::uint32_t pad2C;
    char* buffer;
};
