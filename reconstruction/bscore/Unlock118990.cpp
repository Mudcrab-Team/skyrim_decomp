// Source exposure: binary-analysis
// Code origin: Original reconstruction from pinned-image observations.
// Unlock118990: GUESS(low) STANDIN; original owner is unknown
// Function118990: GUESS(low); provisional entry name
// 0x118990 Unlock118990::Function118990
#include "Unlock118990.h"

int Unlock118990::Function118990(char* dest, std::size_t size, const char* format, ...)
{
    va_list args; va_start(args, format);
    auto result = FormatUnflagged(dest, size, format, args);
    va_end(args);
    return result;
}
