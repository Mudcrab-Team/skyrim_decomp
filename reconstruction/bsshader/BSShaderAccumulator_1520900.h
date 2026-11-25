// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSShaderAccumulator: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1520900: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Material1520900, MaterialTable1520900: GUESS(low) STANDIN; shader material slots
struct Material1520900 { std::uint8_t unknown00[0x26]; unsigned char flags; void Apply(unsigned); };
struct MaterialTable1520900 { std::uint8_t unknown00[0x70]; Material1520900* materials[32]; };

class BSShaderAccumulator
{
public:
    std::uint8_t unknown00[0x10];
    void* state;
    std::uint8_t unknown18[0x118];
    MaterialTable1520900* table;
    void Bind(unsigned, unsigned, unsigned, int);

    void Function1520900(unsigned value);
};
