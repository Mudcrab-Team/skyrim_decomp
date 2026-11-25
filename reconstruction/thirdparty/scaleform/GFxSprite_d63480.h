// Source exposure: binary-analysis
// Code origin: original; pinned-image observations, inferred ownership
// Adapted bodies: none
// GFxSprite: GUESS(low) STANDIN; owner inferred from nearby named functions and body shape
// Functiond63480: GUESS(low); provisional member name
#pragma once
#include <cstdint>
#include <cstddef>
#include <cstdarg>

// Logd63480: GUESS(low) STANDIN; variadic logging interface
struct Logd63480 { virtual ~Logd63480(); virtual void Print(unsigned,const char*,va_list); };

class GFxSprite
{
public:
    Logd63480* GetLog();

    void Functiond63480(const char* format, ...);
};
