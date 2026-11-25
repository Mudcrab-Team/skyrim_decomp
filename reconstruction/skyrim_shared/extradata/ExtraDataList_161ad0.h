// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function161ad0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload161ad0: GUESS(low) STANDIN; extra-data scalar payload
struct Payload161ad0 { std::uint8_t unknown00[0x18]; std::uint32_t value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned type);

    void Function161ad0(const std::uint32_t* value);
};
