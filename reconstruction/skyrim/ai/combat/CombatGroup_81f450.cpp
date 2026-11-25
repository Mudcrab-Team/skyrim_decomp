// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// CombatGroup: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function81f450: GUESS(low); provisional member name
// 0x81f450 CombatGroup::Function81f450
// CI hash: 0x81f450 ?Function81f450@CombatGroup@@QEAAXI@Z
#include "CombatGroup_81f450.h"

// Guess: Mark the selected combat-group entry.
void CombatGroup::Function81f450(unsigned id)
{
    auto* entry = Find(id);
    if (entry) { entry->flag = 1; }
}
