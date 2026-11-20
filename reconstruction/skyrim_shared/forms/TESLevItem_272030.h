// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementations from the pinned listings and partial declarations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESLevItem: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SaveGame, Revert, InitItemImpl: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESLeveledList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// leveledList, Init: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESLeveledList
{
public:
    void SaveGame(BGSSaveFormBuffer* buffer);
    void Revert(BGSLoadFormBuffer* buffer);
    void Init(TESForm* owner);
};

class TESLevItem : public TESForm
{
public:
    void InitItemImpl() override;
    void SaveGame(BGSSaveFormBuffer* buffer) override;
    void Revert(BGSLoadFormBuffer* buffer) override;

private:
    std::uint8_t padding20[0x10];
    TESLeveledList leveledList;
};
