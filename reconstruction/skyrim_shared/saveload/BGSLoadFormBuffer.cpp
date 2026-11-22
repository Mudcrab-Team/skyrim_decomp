// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; decoded from the pinned image listing and community declarations
// SPDX-License-Identifier: CC0-1.0
// 0x6379f0 BGSLoadFormBuffer::Function6379f0
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
#include "BGSLoadFormBuffer.h"
#include <cstring>

// TODO body: RVA 0x637580, 5 bytes, BGSLoadFormBuffer::GetVersion.
std::uint8_t BGSLoadFormBuffer::GetVersion()
{
    return version;
}

// Guess: copy the incoming buffer state into this load buffer.
void BGSLoadFormBuffer::Function6379f0(const void* a_data, std::uint32_t a, std::uint32_t b)
{
    std::memcpy(&buffer, a_data, 24);
    unk20 = a;
    bufferPosition = b;
}
