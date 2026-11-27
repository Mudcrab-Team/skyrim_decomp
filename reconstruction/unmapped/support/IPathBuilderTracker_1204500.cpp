// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x1204500 IPathBuilderTracker::MessageWithPathingLocation
#include "IPathBuilderTracker_1204500.h"

// Forwards a formatted tracker message with pathing location to virtual slot 1.
void IPathBuilderTracker::MessageWithPathingLocation(const void* a_location, const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VMessageWithPathingLocation(a_location, 0, a_fmt, args);
    va_end(args);
}
