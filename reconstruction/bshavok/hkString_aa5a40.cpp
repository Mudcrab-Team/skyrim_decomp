// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkString: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionaa5a40: GUESS(low); provisional member name
// 0xaa5a40 hkString::Functionaa5a40
// CI hash: 0xaa5a40 ?Functionaa5a40@hkString@@SAXPEADPEBD@Z
#include "hkString_aa5a40.h"

// Guess: Copy a string including its terminator.
void hkString::Functionaa5a40(char* dest, const char* source)
{
    while ((*dest++ = *source++) != 0) {
    }
}
