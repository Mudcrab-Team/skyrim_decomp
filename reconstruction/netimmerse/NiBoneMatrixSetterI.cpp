// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x15797a0 NiBoneMatrixSetterI::~NiBoneMatrixSetterI
#include "NiBoneMatrixSetterI.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiBoneMatrixSetterI::NiBoneMatrixSetterI()
{
}

// RVA 0x15797a0, 43 bytes, NiBoneMatrixSetterI::~NiBoneMatrixSetterI: the target inlines the complete
// destructor (vftable store, then class-scope delete), so the destructor is an empty inline body in
// the header.
