// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original; declarations reduced from pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Archive, set_endian_swap, _readFn, _writeFn: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ReadNative, ReadSwapped, WriteNative, WriteSwapped, reserved: GUESS(low); callback roles inferred from selection.
// 0xebf7a0 Archive::set_endian_swap
#pragma once
#include <cstddef>
#include <cstdint>

class Archive
{
public:
    using ReadFn = std::uint32_t(Archive*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    using WriteFn = std::uint32_t(Archive*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    void set_endian_swap(bool a_doSwap);
    std::uint8_t reserved[0x10];
    ReadFn* _readFn;
    WriteFn* _writeFn;
};
static_assert(offsetof(Archive, _readFn) == 0x10, "read callback offset");
static_assert(offsetof(Archive, _writeFn) == 0x18, "write callback offset");
Archive::ReadFn ReadNative;
Archive::ReadFn ReadSwapped;
Archive::WriteFn WriteNative;
Archive::WriteFn WriteSwapped;
