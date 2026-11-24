// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling. Stamped as a twin of matched 0x181060 (skyrim_shared/extradata/ExtraTeleport_181060): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:1565
// DoorTeleportData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Owner181dc0: GUESS(low) STANDIN
// BSExtraData: GUESS(low) STANDIN
#pragma once
#include "ExtraTeleport_181060.h"

class Owner181dc0 : public BSExtraData
{
public:
    ~Owner181dc0() override;

    DoorTeleportData* teleportData;
};
static_assert(sizeof(Owner181dc0) == 0x18, "Owner181dc0 size");
