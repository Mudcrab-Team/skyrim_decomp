// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf11950 NiFloatsExtraData::dtor_deleting
// CI hash: 0xf11950 ??_GNiFloatsExtraData@@UEAAPEAXI@Z
#include "NiFloatsExtraData_f11950.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiFloatsExtraData::NiFloatsExtraData()
{
}

// Free the float array buffer and destroy the base extra-data object.
NiFloatsExtraData::~NiFloatsExtraData()
{
    NiFree(data);
    data = nullptr;
}
