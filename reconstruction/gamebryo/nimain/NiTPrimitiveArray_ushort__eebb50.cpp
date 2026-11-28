// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0xeebb50 ??_GNiTPrimitiveArray_ushort_@@UEAAPEAXI@Z
// Adapted bodies: none
// 0xeebb50 NiTPrimitiveArray_ushort_::dtor_deleting
#include "NiTPrimitiveArray_ushort__eebb50.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiTPrimitiveArray_ushort_::NiTPrimitiveArray_ushort_() {}

// Free the backing buffer of unsigned 16-bit elements.
NiTPrimitiveArray_ushort_::~NiTPrimitiveArray_ushort_()
{
    NiFree(data);
}
