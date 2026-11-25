// Source exposure: mixed (local target analysis and permitted sibling).
// Code origin: Stamped as a twin of matched 0x637e70 (skyrim_shared/saveload/BGSLoadGameBuffer_637e70): source copied, names replaced by placeholders.
// Origin: independently reconstructed from target and sibling hints.
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSLoadGameBuffer.cpp:200
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x637fd0 Owner637fd0::Function637fd0
#include "Owner637fd0.h"
#include <cstring>

// guess: same compiled code as matched 0x637e70 apart from relocated fields; its role here is not established.
void Owner637fd0::Function637fd0(void* data, std::uint32_t size, std::uint32_t) {
    std::memcpy(data, static_cast<const char*>(buffer) + bufferPosition, size);
    bufferPosition += size;
}
