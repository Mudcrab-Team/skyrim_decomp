// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function165790: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload165790: GUESS(low) STANDIN; extra-data flags
struct Payload165790 { std::uint8_t unknown00[0x10]; std::uint8_t flags; };

class ExtraDataList
{
public:
    void* GetByType(unsigned type);

    std::uint8_t Function165790();
};
