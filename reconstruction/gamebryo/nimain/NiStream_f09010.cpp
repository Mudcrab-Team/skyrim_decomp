// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original; handwritten callback dispatch and position accounting
// SPDX-License-Identifier: CC0-1.0
// 0xf09010 NiStream::Functionf09010
// Adapted bodies: none
// Cookbook: 49
#include "NiStream_f09010.h"

// Writes byte-sized components and records the number written.
std::uint32_t NiStream::Functionf09010(const void* buffer, std::uint32_t bytes)
{
    const std::uint32_t totalBytes = bytes;
    bytes = 1;
    NiBinaryStream* stream = oStr;
    const std::uint32_t written = stream->_writeFn(stream, buffer, totalBytes, &bytes, 1);
    stream->_absoluteCurrentPos += written;
    return written;
}
