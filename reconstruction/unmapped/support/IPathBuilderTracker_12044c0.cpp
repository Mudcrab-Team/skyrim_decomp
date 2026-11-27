// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x12044c0 IPathBuilderTracker::PostMessage2
#include "IPathBuilderTracker_12044c0.h"

// Forwards a formatted level-2 tracker message to virtual slot 2.
void IPathBuilderTracker::PostMessage2(const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VPostMessage(2, a_fmt, args);
    va_end(args);
}
