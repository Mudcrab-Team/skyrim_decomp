// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// SpriteLogd634e0: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond634e0: GUESS(low); provisional member name
// 0xd634e0 SpriteLogd634e0::Functiond634e0
// CI hash: 0xd634e0 ?Functiond634e0@SpriteLogd634e0@@QEAAXPEBDZZ
#include "SpriteLogd634e0_d634e0.h"

// Guess: Log through the containing sprite after the secondary-base adjustment.
void SpriteLogd634e0::Functiond634e0(const char* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    auto* sprite=static_cast<Sprited634e0*>(this);
    auto* log=sprite->GetLog();
    if(log) { log->Print(17, format, arguments); }
    va_end(arguments);
}
