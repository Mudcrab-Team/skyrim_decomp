// Source exposure: mixed (names from the community PDB table where labelled; the pinned image listing).
// Code origin: original; written from the listing and community PDB name.
// Adapted bodies: none
// 0x1204450 IPathBuilderTracker::PostMessage0
#include "IPathBuilderTracker_1204450.h"

// Forwards a formatted level-0 tracker message to virtual slot 2.
void IPathBuilderTracker::PostMessage0(const char* a_fmt, ...)
{
    std::va_list args;
    va_start(args, a_fmt);
    VPostMessage(0, a_fmt, args);
    va_end(args);
}
