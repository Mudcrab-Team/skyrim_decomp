// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// CI hash: 0xeee2c0 ??_GNiTPrimitiveArray_uint_@@UEAAPEAXI@Z
// Adapted bodies: none
// 0xeee2c0 NiTPrimitiveArray_uint_::dtor_deleting
#include "NiTPrimitiveArray_uint__eee2c0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiTPrimitiveArray_uint_::NiTPrimitiveArray_uint_() {}

// Free the backing buffer of unsigned 32-bit elements.
NiTPrimitiveArray_uint_::~NiTPrimitiveArray_uint_()
{
    NiFree(data);
}
