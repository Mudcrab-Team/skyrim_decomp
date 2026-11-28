// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0xab7940 StreamWriterAb7940::WriteByte
// Adapted bodies: none.
#include "StreamWriterAb7940.h"

void StreamWriterAb7940::WriteByte(std::uint8_t a_value)
{
    stream->Write(&a_value, 1);
}
