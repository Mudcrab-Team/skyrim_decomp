// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock8732d0: GUESS(low) STANDIN; original owner is unknown
// Function8732d0: GUESS(low); provisional entry name
// 0x8732d0 Unlock8732d0::Function8732d0
#include "Unlock8732d0.h"

void Unlock8732d0::Function8732d0(bool failed)
{
    if (status <= 1) status = failed;
}
