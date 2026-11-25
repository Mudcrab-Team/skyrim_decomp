// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSShaderAccumulator: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function15205c0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// ShaderState15205c0, shaderState15205c0: GUESS(low) STANDIN; shared shader state
struct ShaderState15205c0 { unsigned flags; std::uint8_t unknown04[0xa4]; unsigned pending; };
extern ShaderState15205c0 shaderState15205c0;

class BSShaderAccumulator
{
public:
    std::uint8_t unknown00[0x10];
    void* state;
    void Update();

    void Function15205c0();
};
