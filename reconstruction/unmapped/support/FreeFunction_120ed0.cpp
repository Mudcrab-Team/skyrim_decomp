// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x120ed0 Function120ed0
// Adapted bodies: none
#include "FreeFunction_120ed0.h"

// Advances the stream position by up to the requested number of bytes, clamped to size.
std::int32_t Function120ed0(Stream120ed0* a_stream, std::int32_t a_bytes)
{
    if (a_stream->position + a_bytes > a_stream->size)
    {
        a_bytes = a_stream->size - a_stream->position;
    }

    a_stream->position += a_bytes;
    return a_bytes;
}
