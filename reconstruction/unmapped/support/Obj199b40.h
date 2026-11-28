// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj199b40::WriteDwords, treated as adapted: shaped like NiBinaryStream::binary_write (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp:32, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Obj199b40, WriteDwords: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Obj199b40
{
    using WriteFn = std::uint32_t (*)(Obj199b40*, const void*, std::uint32_t, const std::uint32_t*, std::uint32_t);

    void WriteDwords(const void* a_data, std::uint32_t a_count);  // compared: 0x199b40

    std::uint64_t unk00;  // 00
    std::uint32_t pos;    // 08
    std::uint32_t unk0C;  // 0C
    std::uint64_t unk10;  // 10
    WriteFn writeFn;      // 18
};
