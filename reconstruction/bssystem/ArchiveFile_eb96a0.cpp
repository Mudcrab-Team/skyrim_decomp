// Source exposure: mixed (local binary analysis and community declarations).
// Code origin: original; declarations reduced from pinned community headers.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ArchiveFile: EXE_RTTI
// InitializeBuffer: GUESS(low); initializes buffer storage when absent.
// Adapted bodies: none.
// 0xeb96a0 ArchiveFile::InitializeBuffer
#include "ArchiveFile_eb96a0.h"

bool ArchiveFile::InitializeBuffer()
{
    if (!buffer) {
        bufferReadSize = 0;
        pos = 0;
        buffer = nullptr;
        if (bufferAllocSize) {
            buffer = AllocateBuffer(bufferAllocSize);
        }
        isGood = true;
    }
    return true;
}
