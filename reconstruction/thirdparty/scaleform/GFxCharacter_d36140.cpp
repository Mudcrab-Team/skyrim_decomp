// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xd36140 GFxCharacter::IsVerboseActionErrors
#include "GFxCharacter_d36140.h"

// True when flag bit 6 of the movie root is clear. The bit is read as a switch that suppresses these
// reports (a guess), so a clear bit means verbose error reporting is on.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool GFxCharacter::IsVerboseActionErrors() const
{
    return ((GetMovieRoot()->flags >> 6) & 1) == 0;
}
