// Source exposure: mixed (local target analysis and permitted sibling).
// Code origin: Stamped as a twin of matched 0x637e70 (skyrim_shared/saveload/BGSLoadGameBuffer_637e70): source copied, names replaced by placeholders.
// Origin: independently reconstructed from target and sibling hints.
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSLoadGameBuffer.cpp:200
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function637fd0, Owner637fd0: GUESS(low) STANDIN
#pragma once
#include "BGSLoadGameBuffer_637e70.h"
#include <cstring>

class Owner637fd0 {
public:
    virtual ~Owner637fd0();
    virtual std::uint8_t GetVersion();
    void Function637fd0(void* data, std::uint32_t size, std::uint32_t endian);
    void* buffer;
    std::uint64_t unk10;
    std::uint32_t unk18, unk1C, unk20, bufferPosition;
};

