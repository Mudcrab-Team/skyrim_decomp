// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function616de0: GUESS(low); provisional member name
// 0x616de0 BGSSaveLoadGame::Function616de0
// CI hash: 0x616de0 ?Function616de0@BGSSaveLoadGame@@QEAA_NPEBUForm616de0@@@Z
#include "BGSSaveLoadGame_616de0.h"

// Guess: Check the save-state table for a form identity.
bool BGSSaveLoadGame::Function616de0(const Form616de0* form)
{
    return table ? table->Contains(form->formID) : false;
}
