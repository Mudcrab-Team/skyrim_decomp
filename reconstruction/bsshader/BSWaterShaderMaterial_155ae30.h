// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSWaterShaderMaterial: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function155ae30: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// MaterialManager155ae30, materials155ae30, water155ae30: GUESS(low) STANDIN; shared material creation
class BSWaterShaderMaterial;
struct MaterialManager155ae30 { void* Create(BSWaterShaderMaterial*,unsigned,unsigned); };
extern MaterialManager155ae30* materials155ae30;
extern void* water155ae30;

class BSWaterShaderMaterial
{
public:
    BSWaterShaderMaterial();
    virtual ~BSWaterShaderMaterial();
    std::uint8_t unknown08[0x178];

    static void Function155ae30();
};
