// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; observed accesses and labelled declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiStream, unk2D8, unk2F0: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Functionee45e0, StreamOperation, unknown00, unknown2DC: GUESS(low) STANDIN
#pragma once
#include <cstddef>
#include <cstdint>

class NiStream
{
public:
    void Functionee45e0();
    std::uint8_t unknown00[0x2D8];
    std::uint32_t unk2D8;
    std::uint8_t unknown2DC[0x14];
    void* unk2F0;
};
static_assert(offsetof(NiStream, unk2D8) == 0x2D8, "stream state offset");
static_assert(offsetof(NiStream, unk2F0) == 0x2F0, "stream operation offset");
void StreamOperation(void* context);
