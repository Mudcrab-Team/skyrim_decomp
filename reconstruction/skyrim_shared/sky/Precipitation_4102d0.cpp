// Source exposure: mixed (binary-analysis of the pinned image, community-headers, sibling sources).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x4102d0 Precipitation::dtor_deleting
// CI hash: 0x4102d0 ??_GPrecipitation@@UEAAPEAXI@Z
#include "Precipitation_4102d0.h"

Precipitation::Precipitation()
{
}

Precipitation::~Precipitation()
{
    currentPrecip = nullptr;
    lastPrecip = nullptr;
}
