// Source exposure: binary-analysis
// Unlock18eb20: GUESS(low) STANDIN; original owner is unknown
// Function18eb20: GUESS(low); provisional entry name
// 0x18eb20 Unlock18eb20::~Unlock18eb20
#include "Unlock18eb20.h"

Unlock18eb20::~Unlock18eb20()
{
    if (pointer)
        pointer->Release();
}
