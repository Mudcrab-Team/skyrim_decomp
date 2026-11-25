// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BSPathingRequest: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function11cbe20: GUESS(low); provisional member name
// 0x11cbe20 BSPathingRequest::Function11cbe20
// CI hash: 0x11cbe20 ?Function11cbe20@BSPathingRequest@@QEAAXAEBQEAURef11cbe20@@@Z
#include "BSPathingRequest_11cbe20.h"

// Guess: Update the pathing reference and its availability flags.
void BSPathingRequest::Function11cbe20(Ref11cbe20* const& value)
{
    if (value) {
        flags |= 0xc;
        Ref11cbe20* next = value;
        Ref11cbe20* old = reference;
        if (next != old) {
    // Balance the shared reference atomically.
            if (next) { _InterlockedIncrement(&next->references); }
            reference = next;
    // Balance the shared reference atomically.
            if (old && _InterlockedExchangeAdd(&old->references, -1) == 1) { delete old; }
        }
    } else { flags = (flags & ~4u) | 8; }
}
