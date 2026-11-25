// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function616e00: GUESS(low); provisional member name
// 0x616e00 BGSSaveLoadGame::Function616e00
// CI hash: 0x616e00 ?Function616e00@BGSSaveLoadGame@@QEAAPEAXPEAXPEBUForm616e00@@@Z
#include "BGSSaveLoadGame_616e00.h"

// Guess: Write the saved entry for a form identity to caller storage.
void* BGSSaveLoadGame::Function616e00(void* output, const Form616e00* form)
{
    table->Find(output, form->formID);
    return output;
}
