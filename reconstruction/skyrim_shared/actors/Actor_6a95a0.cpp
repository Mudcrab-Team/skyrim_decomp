// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// Actor: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function6a95a0: GUESS(low); provisional member name
// 0x6a95a0 Actor::Function6a95a0
// CI hash: 0x6a95a0 ?Function6a95a0@Actor@@QEAAHPEBUChange6a95a0@@@Z
#include "Actor_6a95a0.h"

// Guess: Notify the movement controller when the state predicate changes.
int Actor::Function6a95a0(const Change6a95a0* change)
{
    bool first = change->first.Check();
    bool second = change->second.Check();
    if (controller && first != second) { controller->Update(second); }
    return 1;
}
