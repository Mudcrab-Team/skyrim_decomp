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
    void Init(TESForm* owner);
};

class TESLevItem : public TESForm
{
public:
    void InitItemImpl() override;

private:
    std::uint8_t padding20[0x10];
    TESLeveledList leveledList;
};
