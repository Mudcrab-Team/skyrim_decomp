// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: TESLevItem::~TESLevItem follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevitem.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevitem.cpp:93
// TESLevItem, TESLevItem::~TESLevItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESBoundObject, TESBoundObject::~TESBoundObject, TESLeveledList, TESLeveledList::~TESLeveledList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08: GUESS(low)
// TESLevItem::TESLevItem: STANDIN SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); emits the vftable.
#pragma once

#include <cstdint>

class TESBoundObject
{
public:
    virtual ~TESBoundObject();

    std::uint8_t unk08[0x28];
};

class TESLeveledList
{
public:
    virtual ~TESLeveledList();

    std::uint8_t unk08[0x20];
};

class TESLevItem : public TESBoundObject, public TESLeveledList
{
public:
    TESLevItem();
    ~TESLevItem() override;
};
static_assert(sizeof(TESBoundObject) == 0x30, "leveled list base offset");
static_assert(sizeof(TESLevItem) == 0x58, "leveled item layout");
