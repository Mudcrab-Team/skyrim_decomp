// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling. Stamped as a twin of matched 0x181060 (skyrim_shared/extradata/ExtraTeleport_181060): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:1565
// 0x181dc0 Owner181dc0::~Owner181dc0
#include "Owner181dc0.h"

// guess: same compiled code as matched 0x181060 apart from relocated fields; its role here is not established.
Owner181dc0::~Owner181dc0()
{
    DoorTeleportData* oldData = teleportData;
    delete oldData;
}
