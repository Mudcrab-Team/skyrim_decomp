// Source exposure: mixed (pinned-image observations and labelled naming/declaration sources).
// Code origin: original handwritten implementation from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// 0xf08fd0 NiStream::Functionf08fd0
// Adapted bodies: none
// Cookbook: 49; reuse the consumed byte-count parameter as the one-byte component size.
#include "NiStream_f08fd0.h"

std::uint32_t NiStream::Functionf08fd0(void* buffer, std::uint32_t bytes)
{
    const std::uint32_t totalBytes = bytes;
    bytes = 1;
    NiBinaryStream* stream = iStr;
    const std::uint32_t read = stream->_readFn(stream, buffer, totalBytes, &bytes, 1);
    stream->_absoluteCurrentPos += read;
    return read;
}
