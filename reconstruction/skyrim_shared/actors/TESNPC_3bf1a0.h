// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// TESNPC, TESNPC::GetShortName: CRASHLOGGER_PDB(59818@2026.10.24)
// TESFullName, BGSLocalizedStringDL: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fullName, shortName, unk00, unkE0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

class TESFullName
{
public:
    virtual ~TESFullName();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual const char* GetFullName() const;
};
static_assert(sizeof(TESFullName) == 0x08, "TESFullName size");

class BGSLocalizedStringDL
{
public:
    const char* GetString() const;

    std::uint32_t id;
};

class TESNPC
{
public:
    const char* GetShortName() const;

    std::uint8_t unk00[0xD8];
    TESFullName fullName;
    std::uint8_t unkE0[0x208 - 0xE0];
    BGSLocalizedStringDL shortName;
};
static_assert(offsetof(TESNPC, fullName) == 0xD8, "TESNPC::fullName offset");
static_assert(offsetof(TESNPC, shortName) == 0x208, "TESNPC::shortName offset");
