// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// ImageSpaceEffectHDR: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function153d830: GUESS(low); provisional member name
// 0x153d830 ImageSpaceEffectHDR::Function153d830
// CI hash: 0x153d830 ?Function153d830@ImageSpaceEffectHDR@@SAXXZ
#include "ImageSpaceEffectHDR_153d830.h"

// Guess: Clear the image-space state and its enabled flag.
void ImageSpaceEffectHDR::Function153d830()
{
    if (state153d830.count >= 0) { state153d830.Reset(); }
    enabled153d830 = false;
}
