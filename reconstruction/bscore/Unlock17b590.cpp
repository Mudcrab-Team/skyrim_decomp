// Source exposure: binary-analysis
// Unlock17b590: GUESS(low) STANDIN; original owner is unknown
// Function17b590: GUESS(low); provisional entry name
// 0x17b590 Unlock17b590::~Unlock17b590
#include "Unlock17b590.h"

Unlock17b590::~Unlock17b590()
{
    if (pointer)
        ReleaseReference(pointer);
}
