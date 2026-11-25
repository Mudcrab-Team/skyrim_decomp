// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSLocation: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function29b070: GUESS(low); provisional member name
// 0x29b070 BGSLocation::Function29b070
// CI hash: 0x29b070 ?Function29b070@BGSLocation@@QEAAEXZ
#include "BGSLocation_29b070.h"

// Guess: Read the location flag through the flag-fetch helper.
std::uint8_t BGSLocation::Function29b070()
{
    unsigned flags = 0;
    if (ReadFlags(&flags)) { return (flags >> 2) & 1; }
    return 0;
}
