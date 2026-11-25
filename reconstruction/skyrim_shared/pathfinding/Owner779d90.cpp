// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// Code origin: Stamped as a twin of matched 0x11f01d0 (skyrim_shared/pathfinding/BSNavmeshInfoMap): source copied, names replaced by placeholders.
// image).
// 0x779d90 Owner779d90::~Owner779d90
#include "Owner779d90.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Owner779d90::Owner779d90()
{
}

// guess: same compiled code as matched 0x11f01d0 apart from relocated fields; its role here is not established.
Owner779d90::~Owner779d90()
{
    bsNavmeshInfoMapInstance = nullptr;
}
