// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ExtraDataList: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function165910: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Payload165910, PayloadValue165910: GUESS(low) STANDIN; extra-data value subobject
struct PayloadValue165910 { std::uint64_t unknown00; };
struct Payload165910 { std::uint8_t unknown00[0x10]; PayloadValue165910 value; };

class ExtraDataList
{
public:
    void* GetByType(unsigned type);

    PayloadValue165910* Function165910();
};
