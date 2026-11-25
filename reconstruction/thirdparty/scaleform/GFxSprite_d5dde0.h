// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxSprite: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond5dde0: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>

// SpriteStated5dde0: GUESS(low) STANDIN; sprite state object
struct SpriteStated5dde0 { void Release(); };

class GFxSprite
{
public:
    std::uint8_t unknown00[0x320];
    SpriteStated5dde0* state;
    void SetState(bool);

    void Functiond5dde0();
};
