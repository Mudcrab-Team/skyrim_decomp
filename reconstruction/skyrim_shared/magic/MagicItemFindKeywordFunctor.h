// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// 0x153250 compared function
// Code origin: original stand-in; no external declaration or body reused.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MagicItemFindKeywordFunctor: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0) EXE_RTTI
// MagicItemFindKeywordFunctor::MatchCondition: CRASHLOGGER_PDB(59818@2026.10.24)
// MagicItemTraversalFunctor, MagicItemFindFunctor: STANDIN EXE_RTTI
// unknown08, unknown10, unknown18, MatcherAt40, MatcherHolder, ArgType, their members: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class MagicItemTraversalFunctor
{
public:
    virtual ~MagicItemTraversalFunctor() = default;
    std::uint8_t unknown08[0x8];  // 08
};
static_assert(sizeof(MagicItemTraversalFunctor) == 0x10, "MagicItemTraversalFunctor size");

class MagicItemFindFunctor : public MagicItemTraversalFunctor
{
public:
    std::uint8_t unknown10[0x8];  // 10
};
static_assert(sizeof(MagicItemFindFunctor) == 0x18, "MagicItemFindFunctor size");

class MatcherAt40
{
public:
    virtual void Unk08();
    virtual void Unk10();
    virtual void Unk18();
    virtual void Unk20();
    virtual bool Matches(void* a_keyword);
};

class MatcherHolder
{
public:
    std::uint8_t unknown00[0x40];  // 00
    MatcherAt40 matcher;  // 40
};

class ArgType
{
public:
    std::uint8_t unknown00[0x10];  // 00
    MatcherHolder* field10;  // 10
};

class MagicItemFindKeywordFunctor : public MagicItemFindFunctor
{
public:
    MagicItemFindKeywordFunctor();
    virtual ~MagicItemFindKeywordFunctor();  // compared: 0x152790 (scalar deleting destructor)

    bool MatchCondition(ArgType* a_arg);  // compared: 0x153250

    void* field18;  // 18
};
static_assert(sizeof(MagicItemFindKeywordFunctor) == 0x20, "MagicItemFindKeywordFunctor size");
