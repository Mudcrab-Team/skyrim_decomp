// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESShout: GUESS(low); the class is the placeholder owner, layout stand-in
// GetShoutLevel: CRASHLOGGER_PDB(59818@2026.10.24)
// Variation, variations, word, spell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESWordOfPower, SpellItem, GetKnown: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

class SpellItem;

class TESWordOfPower
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual bool GetKnown() const;  // 17
};

class TESShout
{
public:
    struct Variation
    {
        TESWordOfPower* word;  // 00
        SpellItem* spell;      // 08
        float recoveryTime;    // 10
        unsigned int pad14;    // 14
    };

    int GetShoutLevel();  // compared: 0x387da0

    unsigned char pad00[0x60];  // 00
    Variation variations[3];    // 60
};
