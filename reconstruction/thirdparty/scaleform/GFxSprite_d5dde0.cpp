// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxSprite: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond5dde0: GUESS(low); provisional member name
// 0xd5dde0 GFxSprite::Functiond5dde0
// CI hash: 0xd5dde0 ?Functiond5dde0@GFxSprite@@QEAAXXZ
#include "GFxSprite_d5dde0.h"

// Guess: Update sprite state and release its auxiliary object.
void GFxSprite::Functiond5dde0()
{
    SetState(true);
    state->Release();
}
