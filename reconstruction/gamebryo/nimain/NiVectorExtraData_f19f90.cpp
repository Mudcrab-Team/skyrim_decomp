// Source exposure: mixed.
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: CC0-1.0
// 0xf19f90 NiVectorExtraData::CopyMembers
// Adapted bodies: none.
#include "NiVectorExtraData_f19f90.h"

void NiVectorExtraData::CopyMembers(NiVectorExtraData* destination, NiCloningProcess& process)
{
    NiExtraData::CopyMembers(destination, process);
    destination->values[0] = values[0];
    destination->values[1] = values[1];
    destination->values[2] = values[2];
    destination->values[3] = values[3];
}
