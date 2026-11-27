// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function16efc0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload16efc0: GUESS(low) STANDIN; extra-data pointer payload
struct Payload16efc0 { std::uint8_t unknown00[0x10]; void* value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned type);

    void* Function16efc0();
};
