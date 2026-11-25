// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function617f50: GUESS(low); provisional member name
// 0x617f50 BGSSaveLoadGame::Function617f50
// CI hash: 0x617f50 ?Function617f50@BGSSaveLoadGame@@QEAAXPEAUInput617f50@@@Z
#include "BGSSaveLoadGame_617f50.h"

// Guess: Register the loaded reference or destroy the empty load item.
void BGSSaveLoadGame::Function617f50(Input617f50* input)
{
    manager617f50->Prepare();
    auto* reference=input->GetReference();
    if(reference) {
        if(reference->First() && (reference->Second() || reference->Third())) { reference->Set(false); }
        if(reference->cell) { reference->cell->Remove(reference); }
        state617f50->Register(reference,true);
    } else { delete input; }
}
