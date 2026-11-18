// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESObjectMISC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESObject, TESBoundObject: STANDIN EXE_RTTI
// TESObjectMISC::SaveGame: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MiscSaveBlock, MiscSaveBlock::SaveData: GUESS(low)
// unknownBase, saveBlock88: GUESS(low)
#pragma once

#include <cstdint>
#include "TESForm.h"

class TESObject : public TESForm
{
public:
};

class TESBoundObject : public TESObject
{
public:
};

class MiscSaveBlock
{
public:
    void SaveData(BGSSaveFormBuffer* a_buf);
};

class TESObjectMISC : public TESBoundObject
{
public:
    virtual void SaveGame(BGSSaveFormBuffer* a_buf);  // compared: 0x286eb0

    std::uint8_t unknownBase[0x88 - sizeof(TESBoundObject)];
    MiscSaveBlock saveBlock88;  // 88
};
