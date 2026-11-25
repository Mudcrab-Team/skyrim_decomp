// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ArchiveFile: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functioneb97c0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>


class ArchiveFile
{
public:
    std::uint8_t unknown00[0x170];
    unsigned position;
    unsigned length;
    unsigned Read(void*, unsigned);

    unsigned Functioneb97c0(void* output, unsigned count);
};
