// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSTextureSet: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function32d700: GUESS(low); provisional member name
// 0x32d700 BGSTextureSet::Function32d700
// CI hash: 0x32d700 ?Function32d700@BGSTextureSet@@QEAAPEAUTexture32d700@@XZ
#include "BGSTextureSet_32d700.h"

// Guess: Return the texture subobject with a null-preserving adjustment.
Texture32d700* BGSTextureSet::Function32d700()
{
    return this ? &texture : nullptr;
}
