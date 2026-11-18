// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1e85e0 TESIcon::GetDefaultPath
// 0x1e85f0 TESIcon::~TESIcon
#include "TESIcon.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESIcon::TESIcon()
{
}

// GetDefaultPath: the listing returns the address of a fixed string.
const char* TESIcon::GetDefaultPath() const
{
    return "Textures";
}

// The destructor is declared only in the header: the target calls the complete destructor and then
// tests the delete flag, so attempt binds that call to its RVA (cookbook rule 18).
