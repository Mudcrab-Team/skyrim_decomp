// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// Adapted bodies: none
// 0xd2b700 GASEnvironment::IsVerboseAction
#include "GASEnvironment_d2b700.h"

// Returns whether the verbose ActionScript logging flag is set on the movie root.
bool GASEnvironment::IsVerboseAction() const
{
    return (target->GetMovieRoot()->flags25E0 & (1u << 2)) != 0;
}
