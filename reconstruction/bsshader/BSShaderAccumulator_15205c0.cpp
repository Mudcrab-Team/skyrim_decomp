// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSShaderAccumulator: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function15205c0: GUESS(low); provisional member name
// 0x15205c0 BSShaderAccumulator::Function15205c0
// CI hash: 0x15205c0 ?Function15205c0@BSShaderAccumulator@@QEAAXXZ
#include "BSShaderAccumulator_15205c0.h"

// Guess: Flush the accumulator and invalidate pending shader state.
void BSShaderAccumulator::Function15205c0()
{
    if (state) {
        Update();
        if (shaderState15205c0.pending) {
            shaderState15205c0.flags |= 0x80;
            shaderState15205c0.pending = 0;
        }
    }
}
