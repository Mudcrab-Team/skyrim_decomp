// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function16ee20: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload16ee20: GUESS(low) STANDIN; extra-data pointer payload
struct Payload16ee20 { std::uint8_t unknown00[0x10]; void* value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned);

    void Function16ee20(void* value);
};
