// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock6c8000: GUESS(low) STANDIN; original owner is unknown
// Function6c8000: GUESS(low); provisional entry name
// 0x6c8000 Unlock6c8000::Function6c8000
#include "Unlock6c8000.h"

void* Unlock6c8000::Function6c8000()
{
    auto* value = GetExtraStyle(&extra);
    if (value) return value;
    if (process && process->middle && process->middle->style) return process->middle->style;
    return base->GetStyle();
}
