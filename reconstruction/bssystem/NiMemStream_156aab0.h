// Source exposure: mixed (local pinned-image observations and community declarations).
// Code origin: original reconstruction; callback prototypes follow the labelled stream declaration.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiMemStream, NiMemStream::Function156aab0: GUESS(low)
// NiMemStream, readFn, writeFn, ReadNoSwap, ReadSwap, WriteNoSwap, WriteSwap: GUESS(low) STANDIN; observed callback selections.
// ReadFn, WriteFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiBinaryStream callback declarations, adapted pointee type.
#pragma once
#include <cstdint>
#include <cstddef>
class NiMemStream
{
public:
    using ReadFn = std::uint32_t(NiMemStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(NiMemStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    void Function156aab0(bool doSwap);
    std::uint8_t unknown00[0x10];
    ReadFn* readFn;
    WriteFn* writeFn;
};
static_assert(offsetof(NiMemStream, readFn) == 0x10, "read callback offset");
static_assert(offsetof(NiMemStream, writeFn) == 0x18, "write callback offset");
NiMemStream::ReadFn ReadNoSwap;
NiMemStream::ReadFn ReadSwap;
NiMemStream::WriteFn WriteNoSwap;
NiMemStream::WriteFn WriteSwap;
