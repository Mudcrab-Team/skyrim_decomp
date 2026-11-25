// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6a9240: GUESS(low); provisional member name
// 0x6a9240 Actor::Function6a9240
// CI hash: 0x6a9240 ?Function6a9240@Actor@@QEAAHPEAURequest6a9240@@@Z
#include "Actor_6a9240.h"

// Guess: Read the actor request through its provider and release the input handle.
int Actor::Function6a9240(Request6a9240* request)
{
    auto* reader=provider->Find(&readKey6a9240);
    if(reader) { reader->Read(&request->input,&request->output); }
    manager6a9240->Release(request->input,0);
    return 1;
}
