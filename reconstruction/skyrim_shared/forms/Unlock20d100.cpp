// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock20d100: GUESS(low) STANDIN; original owner is unknown
// Function20d100: GUESS(low); provisional entry name
// 0x20d100 Unlock20d100::Function20d100
#include "Unlock20d100.h"

const char* Unlock20d100::Function20d100()
{
    auto* text = value;
    bool prefixed = false;
    if (text) prefixed = ComparePrefix(text, prefix, 4) == 0;
    return prefixed ? text + 13 : text;
}
