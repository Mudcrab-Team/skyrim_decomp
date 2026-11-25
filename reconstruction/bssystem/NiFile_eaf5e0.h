// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original reconstruction; compact community declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiFile, NiBinaryStream, ReadFn, WriteFn, _absoluteCurrentPos, _readFn, _writeFn: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functioneaf5e0, ReadNoSwap, ReadSwap, WriteNoSwap, WriteSwap: GUESS(low); callback roles inferred from the two selections
// unk00, unk0C: OBSERVED
#pragma once
#include <cstdint>
#include <cstddef>

class NiBinaryStream;
class NiFile
{
public:
    using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    void Functioneaf5e0(bool enabled);
    static ReadFn ReadNoSwap;
    static ReadFn ReadSwap;
    static WriteFn WriteNoSwap;
    static WriteFn WriteSwap;

    std::uintptr_t unk00;                  // 00
    std::uint32_t _absoluteCurrentPos;      // 08
    std::uint32_t unk0C;                    // 0C
    ReadFn* _readFn;                        // 10
    WriteFn* _writeFn;                      // 18
};
static_assert(offsetof(NiFile, _readFn) == 0x10, "read callback offset");
static_assert(offsetof(NiFile, _writeFn) == 0x18, "write callback offset");
