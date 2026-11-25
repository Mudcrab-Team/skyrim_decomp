// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// SpriteLogd63420: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond63420: GUESS(low); provisional member name
// 0xd63420 SpriteLogd63420::Functiond63420
// CI hash: 0xd63420 ?Functiond63420@SpriteLogd63420@@QEAAXPEBDZZ
#include "SpriteLogd63420_d63420.h"

// Guess: Log through the containing sprite after the secondary-base adjustment.
void SpriteLogd63420::Functiond63420(const char* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    auto* sprite=static_cast<Sprited63420*>(this);
    auto* log=sprite->GetLog();
    if(log) { log->Print(16, format, arguments); }
    va_end(arguments);
}
