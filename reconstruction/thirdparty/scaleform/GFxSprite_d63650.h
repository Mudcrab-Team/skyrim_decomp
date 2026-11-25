// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxSprite: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond63650: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// Rootd63650, Stated63650: GUESS(low) STANDIN; sprite root and update state
struct Rootd63650 { std::uint8_t unknown00[0x25e0]; unsigned flags; };
struct Stated63650 { void Update(); };

class GFxSprite
{
public:
    std::uint8_t unknown00[0x118];
    Rootd63650* root;
    std::uint64_t unknown120;
    Stated63650 state;

    void Functiond63650();
};
