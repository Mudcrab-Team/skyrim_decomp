// Near miss: 1.0 alignment distance | register-schedule
// Source exposure: mixed
// Code origin: adapted from the cited permitted sibling body, with target-specific reconstruction.
// 0x639a20 BGSSaveGameBuffer::Save
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSSaveGameBuffer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// bSimulatedMode: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0); name only.
// Save: SIBLING(fo4-private@1b765c70, author-permission)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveGameBuffer.cpp:53
// Body adapted to the observed file callback and byte-count interface.
#include "BGSSaveGameBuffer_639a20.h"

void BGSSaveGameBuffer::Save(BGSSaveLoadFile* file, std::uint32_t size)
{
    const void* data;
    if (pSaveLoadManager->bSimulatedMode) {
        if (!size)
            return;
        data = nullptr;
    } else {
        data = buffer;
        if (!data || !size)
            return;
    }
    std::uint32_t elementSize = 1;
    file->position += file->write(file, data, size, &elementSize, 1);
}
