// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSExtraData, ExtraTeleport, ExtraTeleport::~ExtraTeleport: CRASHLOGGER_PDB(59818@2026.10.24) STANDIN
// ExtraTeleport::teleportData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>
#include <cstddef>

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    std::uint8_t unk08[0x8];
};

struct DoorTeleportData
{
    ~DoorTeleportData();
    std::uint8_t unk00[0x20];
};

class ExtraTeleport : public BSExtraData
{
public:
    ~ExtraTeleport() override;  // compared: 0x181060

    DoorTeleportData* teleportData;  // 0x10
    std::uint64_t unk18;
};
static_assert(sizeof(ExtraTeleport) == 32, "ExtraTeleport size");
