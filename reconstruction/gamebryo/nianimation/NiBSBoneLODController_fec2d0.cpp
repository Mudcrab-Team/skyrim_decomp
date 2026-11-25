// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// NiBSBoneLODController: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functionfec2d0: GUESS(low); provisional member name
// 0xfec2d0 NiBSBoneLODController::Functionfec2d0
// CI hash: 0xfec2d0 ?Functionfec2d0@NiBSBoneLODController@@QEAAXXZ
#include "NiBSBoneLODController_fec2d0.h"

// Guess: Destroy each bone-level entry and clear the pointer array.
void NiBSBoneLODController::Functionfec2d0()
{
    for (unsigned i = 0; i < count; ++i) { delete entries[i]; }
    for (unsigned short i = 0; i < count; ++i) { entries[i] = nullptr; }
    count = 0;
    used = 0;
}
