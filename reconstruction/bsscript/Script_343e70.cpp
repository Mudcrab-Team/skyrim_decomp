// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Script: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function343e70: GUESS(low); provisional member name
// 0x343e70 Script::Function343e70
// CI hash: 0x343e70 ?Function343e70@Script@@QEAA_NIPEAX0@Z
#include "Script_343e70.h"

// Guess: Execute the script with its thread-local mode set as requested.
bool Script::Function343e70(unsigned mode, void* first, void* second)
{
    if (mode == 1) { scriptMode343e70 = true; }
    Execute(first, second, 0, true);
    scriptMode343e70 = false;
    return true;
}
