// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x390fa0 TESModelTri::~TESModelTri
#include "TESModelTri.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESModelTri::TESModelTri()
{
}

// RVA 0x390fa0, 52 bytes, TESModelTri::~TESModelTri: the target calls the complete destructor and
// then frees with class-scope delete, so only the declaration in the header remains and the compiler
// emits the deleting destructor.
