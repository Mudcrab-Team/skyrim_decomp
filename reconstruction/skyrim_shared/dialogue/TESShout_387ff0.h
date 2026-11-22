// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESShout: GUESS(low); the class is the placeholder owner, layout stand-in
// IsSpellItem: CRASHLOGGER_PDB(59818@2026.10.24)
// Variation, variations, word, spell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESWordOfPower, SpellItem, GetKnown: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

class SpellItem;

class TESShout
{
public:
    struct Variation
    {
        struct TESWordOfPower* word;  // 00
        SpellItem* spell;      // 08
        float recoveryTime;    // 10
        unsigned int pad14;    // 14
    };

    bool IsSpellItem(SpellItem* a_spell);  // compared: 0x387ff0

    unsigned char pad00[0x60];  // 00
    Variation variations[3];    // 60
};
