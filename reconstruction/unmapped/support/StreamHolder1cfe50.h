// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: StreamHolder1cfe50::WriteBlock1cfe50, treated as adapted: shaped like NiBinaryStream::binary_write (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp:32, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// StreamHolder1cfe50, BinaryStream1cfe50, WriteBlock1cfe50, errorCode, stream, unk04, unk00, position, unk0C, unk10, writeFn: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int* __cdecl _errno();

struct BinaryStream1cfe50
{
    using WriteFn = std::uint32_t (*)(BinaryStream1cfe50*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);

    std::uint64_t unk00;     // 00
    std::uint32_t position;  // 08
    std::uint32_t unk0C;     // 0C
    std::uint64_t unk10;     // 10
    WriteFn writeFn;         // 18
};
static_assert(offsetof(BinaryStream1cfe50, position) == 0x08, "BinaryStream1cfe50::position offset");
static_assert(offsetof(BinaryStream1cfe50, writeFn) == 0x18, "BinaryStream1cfe50::writeFn offset");

struct StreamHolder1cfe50
{
    std::uint32_t errorCode;     // 00
    std::uint32_t unk04[13];     // 04
    BinaryStream1cfe50* stream;  // 38

    std::uint32_t WriteBlock1cfe50(const void* a_data, std::uint32_t a_size);  // compared: 0x1cfe50
};
static_assert(offsetof(StreamHolder1cfe50, stream) == 0x38, "StreamHolder1cfe50::stream offset");
