// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock11a6ee0: GUESS(low) STANDIN; original owner is unknown
// Function11a6ee0: GUESS(low); provisional entry name
// 0x11a6ee0 Unlock11a6ee0::Function11a6ee0
#include "Unlock11a6ee0.h"

void Unlock11a6ee0::Function11a6ee0(Context11a6ee0* context, void* memory)
{
    if (context && memory) {
        if (context->release) context->release(context, memory);
        else DefaultRelease(memory);
    }
}
