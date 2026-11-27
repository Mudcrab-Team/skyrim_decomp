// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1863d0 ExtraPortalRefData::~ExtraPortalRefData
// Adapted bodies: none
#include "ExtraPortalRefData_1863d0.h"

ExtraPortalRefData::ExtraPortalRefData()
    : data(nullptr)
{
}

ExtraPortalRefData::~ExtraPortalRefData()
{
    if (data)
    {
        delete data;
    }
    data = nullptr;
}
