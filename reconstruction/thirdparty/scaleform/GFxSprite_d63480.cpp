// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxSprite: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond63480: GUESS(low); provisional member name
// 0xd63480 GFxSprite::Functiond63480
// CI hash: 0xd63480 ?Functiond63480@GFxSprite@@QEAAXPEBDZZ
#include "GFxSprite_d63480.h"

// Guess: Send a formatted sprite diagnostic to the configured log.
void GFxSprite::Functiond63480(const char* format, ...)
{
    va_list arguments;
    va_start(arguments, format);
    auto* log = GetLog();
    if (log) { log->Print(0x10, format, arguments); }
    va_end(arguments);
}
