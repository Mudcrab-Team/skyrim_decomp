// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// BGSSaveLoadGame: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function616de0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Form616de0, SaveTable616de0: GUESS(low) STANDIN; save identity lookup
struct Form616de0 { std::uint8_t unknown00[0x14]; unsigned formID; };
struct SaveTable616de0 { bool Contains(unsigned); };

class BGSSaveLoadGame
{
public:
    std::uint8_t unknown00[0x338];
    SaveTable616de0* table;

    bool Function616de0(const Form616de0* form);
};
