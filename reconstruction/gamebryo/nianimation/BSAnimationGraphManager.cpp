// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// Adapted bodies: none (write "none" when attempt prints no "origin advice" line;
// otherwise name each adapted body, its upstream file, revision and licence).
// 0xbc3c30 BSAnimationGraphManager::~BSAnimationGraphManager
#include "BSAnimationGraphManager.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSAnimationGraphManager::BSAnimationGraphManager()
{
}

// RVA 0xbc3c30, 52 bytes: the destructor is declared in the header only. The target calls the
// complete base destructor first, then tests bit 0 of the flag argument before freeing the object.
