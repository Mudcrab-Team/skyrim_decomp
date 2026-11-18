// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0x391b80 BGSIdleMarker::GetIgnoredBySandbox
#include "BGSIdleMarker.h"

// TODO body: RVA 0x391b80, 10 bytes, BGSIdleMarker::GetIgnoredBySandbox.
bool BGSIdleMarker::GetIgnoredBySandbox() const
{
    return (unknown60 >> 4) & 1;
}
