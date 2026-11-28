// Source exposure: mixed (community PDB declarations; the pinned image listing).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xf12af0 NiIntegersExtraData::dtor_deleting
// CI hash: 0xf12af0 ??_GNiIntegersExtraData@@UEAAPEAXI@Z
#include "NiIntegersExtraData_f12af0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiIntegersExtraData::NiIntegersExtraData()
{
}

// Free the integer array buffer and destroy the base extra-data object.
NiIntegersExtraData::~NiIntegersExtraData()
{
    NiFree(data);
    data = nullptr;
}
