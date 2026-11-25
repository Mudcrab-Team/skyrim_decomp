// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function617dd0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// SaveState617dd0: GUESS(low) STANDIN; save-state subobject
struct SaveState617dd0 { void Function(); };

class BGSSaveLoadGame
{
public:
    std::uint8_t unknown00[0x208];
    SaveState617dd0 state;

    void Function617dd0();
};
