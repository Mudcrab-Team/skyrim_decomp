// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// hkSolverAllocator: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// ~hkSolverAllocator: GUESS(low); provisional member name
// 0x10e08b0 hkSolverAllocator::~hkSolverAllocator
// CI hash: 0x10e08b0 ??1hkSolverAllocator@@UEAA@XZ
#include "hkSolverAllocator_10e08b0.h"

// Guess: Destroy the solver allocator critical section before its base.
 hkSolverAllocator::~hkSolverAllocator()
{
    // The lock is destroyed before the allocator base.
}
