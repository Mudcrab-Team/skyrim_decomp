// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0x156a9e0 NiMemStream::dtor
// 0x156aa40 NiMemStream::get_info
// 0x156aa70 NiMemStream::seek
// 0x156aa90 NiMemStream::ReleaseBuffer
// 0x156aaf0 NiMemStream::ReadBytes
#include "NiMemStream_156a9e0.h"

#include <cstring>

// FreeStreamBuffer: GUESS(low); deallocates the stream buffer.
void FreeStreamBuffer(void* buffer);

NiMemStream::~NiMemStream()
{
    if (!externalBuffer && !released) {
        FreeStreamBuffer(buffer);
    }
}

void NiMemStream::get_info(BufferInfo& info)
{
    info.buffer = buffer;
    info.totalSize = length;
    info.bufferAllocSize = length;
    info.bufferReadSize = length;
    info.bufferPos = position;
    info.streamPos = position;
}

void NiMemStream::seek(std::int32_t delta)
{
    const auto next = static_cast<std::int32_t>(position + static_cast<std::uint32_t>(delta));
    if (next >= 0 && static_cast<std::uint32_t>(next) < capacity) {
        position = next;
        absoluteCurrentPos = next;
    }
}

void* NiMemStream::ReleaseBuffer()
{
    auto* result = buffer;
    released = true;
    return result;
}

std::uint32_t NiMemStream::ReadBytes(void* destination, std::uint32_t count)
{
    const auto available = length - position;
    if (count > available) {
        count = available;
    }
    std::memcpy(destination, buffer + position, count);
    position += count;
    return count;
}
