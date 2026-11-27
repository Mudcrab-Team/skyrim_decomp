// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// TESFaction: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function3b49f0: GUESS(low); provisional member name
// 0x3b49f0 TESFaction::Function3b49f0
// CI hash: 0x3b49f0 ?Function3b49f0@TESFaction@@QEAAXIPEBD@Z
#include "TESFaction_3b49f0.h"

// Guess: Assign the interned rank name at a selected faction-list position.
void TESFaction::Function3b49f0(unsigned index, const char* name)
{
    unsigned i = 0;
    Entry3b49f0* found = nullptr;
    for (auto* node = &head; node; node = node->next) {
        if (!node->next && !node->value) { break; }
        if (found) { break; }
        if (i == index) { found = node->value; }
        ++i;
    }
    if (found) { Scope3b49f0 scope(0x65); found->name.Assign(name); }
}
