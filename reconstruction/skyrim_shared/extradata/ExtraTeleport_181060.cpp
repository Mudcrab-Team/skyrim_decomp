// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x181060 ExtraTeleport::~ExtraTeleport
// Adapted bodies: ExtraTeleport::~ExtraTeleport follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:1565
#include "ExtraTeleport_181060.h"

ExtraTeleport::~ExtraTeleport()
{
    DoorTeleportData* oldData = teleportData;
    delete oldData;
}
