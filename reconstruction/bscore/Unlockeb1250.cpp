// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlockeb1250: GUESS(low) STANDIN; original owner is unknown
// Functioneb1250: GUESS(low); provisional entry name
// 0xeb1250 Unlockeb1250::Functioneb1250
#include "Unlockeb1250.h"

Unlockeb1250& Unlockeb1250::Functioneb1250(Unlockeb1250& other)
{
    auto* value = other.data;
    auto* old = data;
    if (value != old) { data = value; other.data = old; }
    return *this;
}
