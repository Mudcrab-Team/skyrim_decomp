// Exposure detail: (local binary analysis and labelled declarations).
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSPerk, BGSPerkEntry, Actor, perkEntries, RemovePerkEntry, CheckConditionFilters, GetFunction, GetFunctionData, GetType, ClearData, InitItem, Load, SetParent, GetID, ApplyPerkEntry, _data, _size: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RemovePerk: SIBLING(fo4-private@1b765c70, author-permission)
// unk00, unk08, EntryTable: GUESS(low); minimal entry and array declarations.

#pragma once
#include <cstddef>
#include <cstdint>

class Actor;
class BGSPerkEntry
{
public:
    virtual void CheckConditionFilters();
    virtual void GetFunction();
    virtual void GetFunctionData();
    virtual ~BGSPerkEntry();
    virtual void GetType();
    virtual void ClearData();
    virtual void InitItem();
    virtual void Load();
    virtual void SetParent();
    virtual void GetID();
    virtual void ApplyPerkEntry();
    virtual void RemovePerkEntry(Actor* actor);
};

class BGSPerk
{
public:
    void RemovePerk(Actor* actor);
    struct EntryTable
    {
        BGSPerkEntry** _data;
        std::uint8_t unk08[8];
        std::uint32_t _size;
    };
    std::uint8_t unk00[0x60];
    EntryTable perkEntries;
};
static_assert(offsetof(BGSPerk, perkEntries) == 0x60, "perk entries offset");
static_assert(offsetof(BGSPerk::EntryTable, _size) == 0x10, "entry count offset");
