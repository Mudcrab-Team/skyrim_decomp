// Source exposure: mixed (pinned image listing; community source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj199b40::WriteDwords, treated as adapted: shaped like NiBinaryStream::binary_write (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiBinaryStream.cpp:32, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x199b40 Obj199b40::WriteDwords
#include "Obj199b40.h"

// Writes a_count 4-byte elements through the stream write callback and advances pos.
void Obj199b40::WriteDwords(const void* a_data, std::uint32_t a_count)
{
    std::uint32_t elemSize = 4;
    pos += writeFn(this, a_data, a_count * 4, &elemSize, 1);
}
