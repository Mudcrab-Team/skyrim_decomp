// Source exposure: binary-analysis
// Unlock1082fb0: GUESS(low) STANDIN; original owner is unknown
// Function1082fb0: GUESS(low); provisional entry name
// 0x1082fb0 Unlock1082fb0::Function1082fb0
#include "Unlock1082fb0.h"

void Unlock1082fb0::Function1082fb0(std::uint32_t* out)
{
    if (shape) *out = shape->value;
    else *out = 0;
}
