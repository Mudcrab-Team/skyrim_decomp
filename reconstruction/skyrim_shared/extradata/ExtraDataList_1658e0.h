// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1658e0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload1658e0: GUESS(low) STANDIN; extra-data scalar payload
struct Payload1658e0 { std::uint8_t unknown00[16]; std::uint8_t value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned type);

    void Function1658e0(std::uint8_t value);
};
