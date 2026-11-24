// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x186120 ExtraPatrolRefData::ClearPatrolData
// Adapted bodies: none
#include "ExtraPatrolRefData_186120.h"

void ExtraPatrolRefData::ClearPatrolData()
{
    delete patrolData;
    patrolData = nullptr;
}
