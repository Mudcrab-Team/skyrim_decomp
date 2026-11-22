// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original; the two bodies are written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// NiPSysMeshEmitter, Functionf9f3a0, Functionfb9ae0: GUESS(low)
// Functionfc0300, field78, field7C: GUESS(low); the shared copy helper and the two copied fields.
#pragma once

#include <cstdint>
#include <cstddef>

class NiPSysMeshEmitter;
void Functionfc0300(NiPSysMeshEmitter* a_source, NiPSysMeshEmitter* a_destination);

class NiPSysMeshEmitter
{
public:
    void Functionf9f3a0(NiPSysMeshEmitter* a_other);
    void Functionfb9ae0(NiPSysMeshEmitter* a_other);

    std::uint8_t  pad00[0x78];  // 00
    std::uint32_t field78;      // 78
    std::uint32_t field7C;      // 7C
};
