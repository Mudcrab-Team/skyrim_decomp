// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSShaderAccumulator: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1521360: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Material1521360, MaterialTable1521360: GUESS(low) STANDIN; shader material slots
struct Material1521360 { std::uint8_t unknown00[0x26]; unsigned char flags; void Apply(unsigned); };
struct MaterialTable1521360 { std::uint8_t unknown00[0x70]; Material1521360* materials[32]; };

class BSShaderAccumulator
{
public:
    std::uint8_t unknown00[0x130];
    MaterialTable1521360* table;
    void Bind(unsigned, unsigned, unsigned, int);

    void Function1521360(int slot, unsigned value);
};
