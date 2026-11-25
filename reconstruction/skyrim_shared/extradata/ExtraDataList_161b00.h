// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function161b00: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload161b00: GUESS(low) STANDIN; extra-data scalar payload
struct Payload161b00 { std::uint8_t unknown00[28]; std::uint16_t value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned type);

    void Function161b00(unsigned value);
};
