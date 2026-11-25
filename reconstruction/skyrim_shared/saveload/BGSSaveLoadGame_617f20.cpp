// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function617f20: GUESS(low); provisional member name
// 0x617f20 BGSSaveLoadGame::Function617f20
// CI hash: 0x617f20 ?Function617f20@BGSSaveLoadGame@@QEAAHI@Z
#include "BGSSaveLoadGame_617f20.h"

// Guess: Resolve a form identity and pass it to the save-load operation.
int BGSSaveLoadGame::Function617f20(unsigned id)
{
    return Process(ResolveForm(id));
}
