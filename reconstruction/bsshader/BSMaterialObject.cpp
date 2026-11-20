// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1534210 Leaf1534210::Invoke
// 0x321da0 BSMaterialObject::~BSMaterialObject
#include "BSMaterialObject.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
BSMaterialObject::BSMaterialObject()
{
}

// EnsureLoaded: the listing is a bare return; there is no work to do.
void BSMaterialObject::EnsureLoaded()
{
}

// The destructor is declared only in the header: the target calls the complete destructor and then
// tests the delete flag, so attempt binds that call to its RVA (cookbook rule 18).
