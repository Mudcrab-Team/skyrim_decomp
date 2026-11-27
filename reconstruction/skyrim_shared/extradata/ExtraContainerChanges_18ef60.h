// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: ExtraContainerChanges::~ExtraContainerChanges follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/extradataobjects.cpp:1917
// ExtraContainerChanges: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraContainerChanges::~ExtraContainerChanges: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSExtraData, BSExtraData::~BSExtraData, ::GetType, ::IsNotEqual, ::next: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InventoryChanges, InventoryChanges::~InventoryChanges: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraContainerChanges::changes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00, oldChanges: GUESS(low); opaque storage and the owned pointer.
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

class InventoryChanges
{
public:
    ~InventoryChanges();
    std::uint64_t unknown00[4];
};

class ExtraContainerChanges : public BSExtraData
{
public:
    ExtraContainerChanges();
    ~ExtraContainerChanges() override;

    InventoryChanges* changes;
};
static_assert(sizeof(ExtraContainerChanges) == 0x18, "ExtraContainerChanges size");
