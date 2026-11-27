// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: ExtraTeleport::~ExtraTeleport follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:1565
// ExtraTeleport: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraTeleport::~ExtraTeleport: CRASHLOGGER_PDB(59818@2026.10.24)
// BSExtraData, BSExtraData::~BSExtraData, ::GetType, ::IsNotEqual, ::next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoorTeleportData, ExtraTeleport::teleportData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoorTeleportData::~DoorTeleportData, unknown00, oldData: GUESS(low); destination cleanup and opaque storage.
#pragma once

#include <cstdint>

void operator delete(void*, unsigned __int64) noexcept;

class BSExtraData
{
public:
    virtual ~BSExtraData() {}
    virtual std::uint32_t GetType() const;
    virtual bool IsNotEqual(const BSExtraData* rhs) const;

    BSExtraData* next;
};
static_assert(sizeof(BSExtraData) == 0x10, "BSExtraData size");

struct DoorTeleportData
{
    ~DoorTeleportData();
    std::uint32_t unknown00[8];
};
static_assert(sizeof(DoorTeleportData) == 0x20, "DoorTeleportData size");

class ExtraTeleport : public BSExtraData
{
public:
    ~ExtraTeleport() override;

    DoorTeleportData* teleportData;
};
static_assert(sizeof(ExtraTeleport) == 0x18, "ExtraTeleport size");
