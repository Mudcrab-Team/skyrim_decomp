// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESSoulGem: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function28ee70: GUESS(low); provisional member name
// 0x28ee70 TESSoulGem::Function28ee70
// CI hash: 0x28ee70 ?Function28ee70@TESSoulGem@@SAPEAXXZ
#include "TESSoulGem_28ee70.h"

// Guess: Retrieve an enabled singleton default after thread-safe static initialization.
void* TESSoulGem::Function28ee70()
{
    static Defaults28ee70 defaults;
    return defaults.enabled ? defaults.value : nullptr;
}
