// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkString: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionaa5a90: GUESS(low); provisional member name
// Recipe: reconstruction/recipes/o2-os.json
// 0xaa5a90 hkString::Functionaa5a90
// CI hash: 0xaa5a90 ?Functionaa5a90@hkString@@SA_KPEBD@Z
#include "hkString_aa5a90.h"

// Guess: Return the length of a null-terminated string.
std::size_t hkString::Functionaa5a90(const char* text)
{
    return std::strlen(text);
}
