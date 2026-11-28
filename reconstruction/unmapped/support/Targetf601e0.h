// Source exposure: binary-analysis (the pinned image listing).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: BinaryStreamf601e0::Load, treated as adapted: shaped like NiBinaryStream::binary_read (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp:23, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BinaryStreamf601e0, ReadFn, StreamHolderf601e0, Targetf601e0: GUESS(low) STANDIN
#pragma once

#include <cstdint>

struct BinaryStreamf601e0
{
    using ReadFn = std::uint32_t (*)(BinaryStreamf601e0*, void*, std::uint32_t, const std::uint32_t*, std::uint32_t);

    void Load(void* a_out, std::uint32_t a_bytes, std::uint32_t a_componentSize)
    {
        currentPos += readFn(this, a_out, a_bytes, &a_componentSize, 1);
    }

    std::uint64_t unk00;       // 0x00
    std::uint32_t currentPos;  // 0x08
    std::uint32_t unk0C;       // 0x0C
    ReadFn readFn;             // 0x10
};

struct StreamHolderf601e0
{
    std::uint64_t unk00[83];           // 0x000
    BinaryStreamf601e0* binaryStream;  // 0x298
};

struct Targetf601e0
{
    void LoadBinary(StreamHolderf601e0& a_stream);  // compared: 0xf601e0

    std::uint32_t value;  // 0x00
};
