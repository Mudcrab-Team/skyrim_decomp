// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// CombatBehaviorContextMagic: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function8b49e0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// State8b49e0: GUESS(low) STANDIN; combat behaviour state
struct State8b49e0 { bool Check(); };

class CombatBehaviorContextMagic
{
public:
    std::uint8_t unknown00[0x18];
    State8b49e0* state;

    bool Function8b49e0();
};
