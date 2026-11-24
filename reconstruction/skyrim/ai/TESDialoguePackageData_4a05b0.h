// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESDialoguePackageData: EXE_RTTI
// TESPackageData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESDialoguePackageDataUnk18, TESDialoguePackageData::unk18: GUESS(low); an owned polymorphic object deleted through its vftable
#pragma once

class TESDialoguePackageDataUnk18
{
public:
    virtual ~TESDialoguePackageDataUnk18();
};

class TESPackageData
{
public:
    TESPackageData();
    virtual ~TESPackageData() {}
};

class TESDialoguePackageData : public TESPackageData
{
public:
    TESDialoguePackageData();
    ~TESDialoguePackageData() override
    {
        delete unk18;
    }

    char unk08[0x10];
    TESDialoguePackageDataUnk18* unk18;
    char unk20[0x10];
};
static_assert(sizeof(TESDialoguePackageData) == 0x30, "TESDialoguePackageData size from the deleting destructor");
