// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSWaterShaderMaterial: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function155ae30: GUESS(low); provisional member name
// 0x155ae30 BSWaterShaderMaterial::Function155ae30
// CI hash: 0x155ae30 ?Function155ae30@BSWaterShaderMaterial@@SAXXZ
#include "BSWaterShaderMaterial_155ae30.h"

// Guess: Lazily create the shared water material from a temporary default material.
void BSWaterShaderMaterial::Function155ae30()
{
    if(!water155ae30) { BSWaterShaderMaterial material; water155ae30=materials155ae30->Create(&material,0,0); }
}
