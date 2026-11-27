// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSRelationship: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function3a4a80: GUESS(low); provisional member name
// 0x3a4a80 BGSRelationship::Function3a4a80
// CI hash: 0x3a4a80 ?Function3a4a80@BGSRelationship@@QEAAIXZ
#include "BGSRelationship_3a4a80.h"

// Guess: Read the packed relationship value with the high flag cleared.
std::uint32_t BGSRelationship::Function3a4a80()
{
    return packedLevel & 0x7fffffff;
}
