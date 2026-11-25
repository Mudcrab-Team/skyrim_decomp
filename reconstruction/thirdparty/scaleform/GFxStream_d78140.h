// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxStream: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond78140: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Inputd78140: GUESS(low) STANDIN; byte input buffer
struct Inputd78140 { std::uint8_t unknown00[0x29]; unsigned char bitPosition; std::uint8_t unknown2a[0x22]; unsigned position; int size; std::uint8_t unknown54[12]; const unsigned char* data; void Refill(unsigned); };

class GFxStream
{
public:
    std::uint64_t unknown00;
    Inputd78140* input;

    void Functiond78140(unsigned char* output, std::size_t count);
};
