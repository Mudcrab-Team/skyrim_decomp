// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL, TESObjectCELL::extraList, TESObjectCELL::cellFlags, ExtraDataList, INTERIOR_DATA, EXTERIOR_DATA: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL::ClearData, CellData, TESObjectCELL::unk138: CRASHLOGGER_PDB(59818@2026.10.24)
// ExtraDataList::RemoveNonPersistentCellData: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// g_allocationContext, saved, unk20, unk00, unk60, unk70, Destroy: GUESS(low)
// Adapted bodies: TESObjectCELL::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesobjectcell.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00460000_o2.cpp:26311 (AutoMemContext destructor similarity, CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_005e0000_o2.cpp:27019 (AutoMemContext constructor similarity, CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesobjectcell.cpp:242
#pragma once

#include <cstdint>
#include "declarations/TESForm.h"

extern __declspec(thread) std::uint32_t g_allocationContext;

// AutoMemContext, AutoMemContext::~AutoMemContext: CRASHLOGGER_PDB(59818@2026.10.24)
class AutoMemContext
{
public:
    explicit AutoMemContext(std::uint32_t context) : saved(g_allocationContext)
    {
        g_allocationContext = context;
    }

    ~AutoMemContext();

private:
    std::uint32_t saved;
};

struct INTERIOR_DATA
{
    std::uint8_t unk00[0x60];
};

struct EXTERIOR_DATA
{
    void Destroy(std::uint32_t flags) noexcept;
};

union CellData
{
    INTERIOR_DATA* interior;
    EXTERIOR_DATA* exterior;
};

struct ExtraDataList
{
    void RemoveNonPersistentCellData();
    std::uint8_t unk00[0x18];
};

class TESObjectCELL : public TESForm
{
public:
    void ClearData() override;

    std::uint8_t unk20[0x20];
    std::uint16_t cellFlags;
    std::uint8_t unk42[6];
    ExtraDataList extraList;
    std::uint8_t unk60[8];
    CellData cellData;
    std::uint8_t unk70[0xC8];
    std::uint64_t unk138;
};
