// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// PlayerCharacter: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function755860: GUESS(low); provisional member name
// 0x755860 PlayerCharacter::Function755860
// CI hash: 0x755860 ?Function755860@PlayerCharacter@@QEAAXPEBUForm755860@@E@Z
#include "PlayerCharacter_755860.h"

// Guess: Update or insert the byte value for a player form identity.
void PlayerCharacter::Function755860(const Form755860* form, std::uint8_t value)
{
    if (!form) { return; }
    unsigned id=form->formID;
    unsigned index=table.Hash(id);
    auto* entry=table.buckets[index];
    while(entry) {
        if(table.Equal(id,entry->key)) { entry->value=value; return; }
        entry=entry->next;
    }
    entry=table.Allocate();
    table.Initialize(entry,id,value);
    entry->next=table.buckets[index];
    table.buckets[index]=entry;
    ++table.count;
}
