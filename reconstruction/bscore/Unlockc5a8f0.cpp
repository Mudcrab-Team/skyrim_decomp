// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockc5a8f0: GUESS(low) STANDIN; original owner is unknown
// 0xc5a8f0 Unlockc5a8f0::Unlockc5a8f0
#include "Unlockc5a8f0.h"

Unlockc5a8f0::Unlockc5a8f0(Refc5a8f0* value) : pointer(value)
{
    if (value) { ++value->references; ++value->owners; }
}
