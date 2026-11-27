// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// QueuedHelmet: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function192880: GUESS(low); provisional member name
// 0x192880 QueuedHelmet::Function192880
// CI hash: 0x192880 ?Function192880@QueuedHelmet@@QEAAXXZ
#include "QueuedHelmet_192880.h"

// Guess: Attach each prepared helmet slot and remove the queued identity.
void QueuedHelmet::Function192880()
{
    for(int i=0;i<42;++i) {
        if(sources[i]) { target->Attach(types[i],sources[i],i); }
    }
    unsigned value=id;
    queue192880->Remove(&value);
}
