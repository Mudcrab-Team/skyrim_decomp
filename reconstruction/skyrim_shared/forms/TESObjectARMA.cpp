// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: TESObjectARMA::~TESObjectARMA, momusdigital/fnv_decomp@91e1b6e8,
// 0x27d3f8 TESObjectARMA::dtor
#include "TESObjectARMA.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESObjectARMA::TESObjectARMA()
{
}

TESObjectARMA::~TESObjectARMA()
{
}
