// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock8db820: GUESS(low) STANDIN; original owner is unknown
// Function8db820: GUESS(low); provisional entry name
// 0x8db820 Unlock8db820::Function8db820
#include "Unlock8db820.h"

void Unlock8db820::Function8db820(void*, Context8db820* context)
{
    auto* value = context->Get();
    if (!(value->flags104 & 1)) value->flags82 |= 2;
}
