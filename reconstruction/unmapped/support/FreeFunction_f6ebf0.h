// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Functionf6ebf0, treated as adapted: shaped like NiBinaryStream::binary_write (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp:32, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BinaryStreamf6ebf0, WriteFn, StreamHolderf6ebf0, Payloadf6ebf0, SaveHeaderf6ebf0, Functionf6ebf0: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct BinaryStreamf6ebf0
{
    using WriteFn = std::uint32_t (*)(BinaryStreamf6ebf0*, const void*, std::uint32_t, const std::uint32_t*, std::uint32_t);

    std::uint64_t unk00;       // 0x00
    std::uint32_t currentPos;  // 0x08
    std::uint32_t unk0C;       // 0x0C
    std::uint64_t unk10;       // 0x10
    WriteFn writeFn;           // 0x18
};

struct StreamHolderf6ebf0
{
    std::uint64_t unk00[84];          // 0x000
    BinaryStreamf6ebf0* writeStream;  // 0x2A0
};

struct Payloadf6ebf0
{
    std::uint32_t unk00;  // 0x00
    std::uint32_t value;  // 0x04
};

void SaveHeaderf6ebf0(StreamHolderf6ebf0* a_stream, const Payloadf6ebf0* a_payload);
void Functionf6ebf0(StreamHolderf6ebf0* a_stream, const Payloadf6ebf0* a_payload);  // compared: 0xf6ebf0
