// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// CombatGroup: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Function81f450: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Entry81f450: GUESS(low) STANDIN; combat-group entry
struct Entry81f450 { std::uint8_t unknown00[9]; std::uint8_t flag; };

class CombatGroup
{
public:
    Entry81f450* Find(unsigned);

    void Function81f450(unsigned id);
};
