// Source exposure: mixed (community headers; the pinned image listing).
// Sibling source: fo4-private@1b765c70 src/Game/Script/BGSGameScriptUtils.cpp:97
// GameScript::WriteFormIDToSave: SIBLING(fo4-private@1b765c70, author-permission)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSNumericIDIndex: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// BSStorage, BSStorage::Read, BSStorage::Write, BGSNumericIDIndex::SetNumericID, BGSNumericIDIndex::GetNumericID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN OBSERVED; the parameter lists follow the listing
// BGSNumericIDIndex::cData1: GUESS(low); the name is the one the sibling body uses
// BSStorage::Unk_00, BSStorage::Unk_01, BSStorage::Unk_02, BSStorage::Unk_03: GUESS(low)
#pragma once

#include <cstdint>

struct BGSNumericIDIndex
{
    BGSNumericIDIndex() :
        cData1{ 0, 0, 0 }
    {}

    void SetNumericID(std::uint32_t a_formID);
    std::uint32_t GetNumericID() const;

    std::uint8_t cData1[3];  // 00
};

class BSStorage
{
public:
    virtual ~BSStorage();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual std::int32_t Read(std::uint32_t a_size, std::uint8_t* a_data) const;        // 04
    virtual std::int32_t Write(std::uint32_t a_size, const std::uint8_t* a_data);       // 05
};

namespace GameScript
{
    bool WriteFormIDToSave(BSStorage& a_storage, std::uint32_t a_formID);
}
