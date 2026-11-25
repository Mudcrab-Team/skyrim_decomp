// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PathingSpace: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function4e3940: GUESS(low); provisional member name
// 0x4e3940 PathingSpace::Function4e3940
// CI hash: 0x4e3940 ?Function4e3940@PathingSpace@@SAIXZ
#include "PathingSpace_4e3940.h"

// Guess: Compute the path-space key from the shared hash seed.
unsigned PathingSpace::Function4e3940()
{
    unsigned result = 0;
    ComputePathHash(&result, &pathKey4e3940, 0);
    return result;
}
