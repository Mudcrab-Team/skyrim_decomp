// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1578880 BSLight::Unk_03
// 0x1578840 BSLight::~BSLight
#include "BSLight.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSLight::BSLight()
{
}

// Unk_03: the listing returns false.
bool BSLight::Unk_03()
{
    return false;
}

// The destructor is declared only in the header: the target calls the complete destructor and then
// tests the delete flag, so attempt binds that call to its RVA (cookbook rule 18).
