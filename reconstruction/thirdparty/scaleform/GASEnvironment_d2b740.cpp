// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0xd2b740 GASEnvironment::IsVerboseActionErrors
#include "GASEnvironment_d2b740.h"

// True when flag bit 6 of the movie root is clear. The bit is read as a switch that suppresses these
// reports (a guess), so a clear bit means verbose error reporting is on.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
bool GASEnvironment::IsVerboseActionErrors() const
{
    return (target->GetMovieRoot()->flags25E0 & (1u << 6)) == 0;
}
