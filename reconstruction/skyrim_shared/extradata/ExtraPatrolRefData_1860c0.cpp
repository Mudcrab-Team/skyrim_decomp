// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1860c0 ExtraPatrolRefData::~ExtraPatrolRefData
// Adapted bodies: none
#include "ExtraPatrolRefData_1860c0.h"

ExtraPatrolRefData::ExtraPatrolRefData()
    : patrolData(nullptr)
{
}

ExtraPatrolRefData::~ExtraPatrolRefData()
{
    delete patrolData;
    patrolData = nullptr;
}
