// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x120f10 Function120f10
// Adapted bodies: none
#include "FreeFunction_120f10.h"

// Updates the stream position from start, current position, or end and returns it.
std::int32_t Function120f10(Stream120f10* a_stream, std::int32_t a_offset, std::int32_t a_origin)
{
    switch (a_origin)
    {
    case 0:
        a_stream->position = a_offset;
        break;
    case 1:
        a_stream->position += a_offset;
        break;
    case 2:
        a_stream->position = a_stream->size - a_offset;
        break;
    default:
        break;
    }

    return a_stream->position;
}
