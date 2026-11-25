// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxSprite: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond63650: GUESS(low); provisional member name
// 0xd63650 GFxSprite::Functiond63650
// CI hash: 0xd63650 ?Functiond63650@GFxSprite@@QEAAXXZ
#include "GFxSprite_d63650.h"

// Guess: Update sprite state and mark the movie root dirty.
void GFxSprite::Functiond63650()
{
    state.Update();
    root->flags |= 0x400;
}
