// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESDataHandler: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function1badf0: GUESS(low); provisional member name
// 0x1badf0 TESDataHandler::Function1badf0
// CI hash: 0x1badf0 ?Function1badf0@TESDataHandler@@QEAAPEAXI@Z
#include "TESDataHandler_1badf0.h"

// Guess: Prepare the data-handler table before retrieving an entry.
void* TESDataHandler::Function1badf0(unsigned index)
{
    data.Prepare();
    return data.items[index];
}
