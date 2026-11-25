// Source exposure: binary-analysis
// Unlock725300: GUESS(low) STANDIN; original owner is unknown
// Function725300: GUESS(low); provisional entry name
// 0x725300 Unlock725300::Function725300
#include "Unlock725300.h"

std::uint32_t* Unlock725300::Function725300(std::uint32_t* out)
{
    const std::uint32_t* source = middleHigh ? &middleHigh->value : &defaultValue;
    *out = *source;
    return out;
}
