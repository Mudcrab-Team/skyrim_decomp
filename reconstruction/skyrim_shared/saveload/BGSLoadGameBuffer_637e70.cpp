// Source exposure: mixed (local target analysis and permitted sibling).
// Origin: independently reconstructed from target and sibling hints.
// names: GUESS(low); signatures and type names are hypotheses.
// BGSLoadGameBuffer::LoadDataEndian: SIBLING(fo4-private@1b765c70, author-permission); adapted data loading.
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSLoadGameBuffer.cpp:200
// BGSLoadGameBuffer and members: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x637e70 BGSLoadGameBuffer::LoadDataEndian
#include "BGSLoadGameBuffer_637e70.h"
#include <cstring>
void BGSLoadGameBuffer::LoadDataEndian(void* data, std::uint32_t size, std::uint32_t) {
    std::memcpy(data, static_cast<const char*>(buffer) + bufferPosition, size);
    bufferPosition += size;
}
