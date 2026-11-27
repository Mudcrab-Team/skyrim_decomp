// Source exposure: mixed.
// Code origin: original observed copy sequence after studying the labelled sibling constructor.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/region system/tesregiondata.cpp (copy constructor; CC0-1.0).
// Unk24fe90: STANDIN GUESS(low)
// Unk24fe90::Unk24fe90: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
// Unk24fe90::~Unk24fe90, Unk24fe90::LoadDataHeader, Unk24fe90::LoadData, Unk24fe90::GetType, Unk24fe90::ConstructSelf, Unk24fe90::Unk_05, Unk24fe90::CopyFrom, Unk24fe90::IsLoaded, TESForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Unk24fe90::unk08, Unk24fe90::unk09, Unk24fe90::unk0a: OBSERVED
#pragma once
#include <cstdint>
class TESForm;
class Unk24fe90
{
public:
    Unk24fe90(const Unk24fe90& other);
    virtual ~Unk24fe90();
    virtual bool LoadDataHeader(void* data);
    virtual void LoadData(TESForm* form);
    virtual std::uint32_t GetType() const = 0;
    virtual void ConstructSelf() = 0;
    virtual void Unk_05() = 0;
    virtual void CopyFrom(Unk24fe90* source, bool copy) = 0;
    virtual bool IsLoaded() const = 0;
    std::uint8_t unk08;
    std::uint8_t unk09;
    std::uint8_t unk0a;
};
