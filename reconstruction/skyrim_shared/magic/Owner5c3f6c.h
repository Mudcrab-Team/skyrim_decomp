// Source exposure: mixed (pinned image listings and RTTI, project layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: partial declarations follow the cited class layouts and pinned RTTI. Stamped as a twin of matched 0x146464 (skyrim_shared/magic/MagicItem_146428): source copied, names replaced by placeholders.
// SpellItem: EXE_RTTI
// MagicItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESModelTextureSwap, TESIcon: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSMessageIcon, TESWeightForm, BGSEquipType, BGSDestructibleObjectForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSSoundDescriptorForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Owner5c3f6c: GUESS(low) STANDIN
// BGSPickupPutdownSounds, addictionItem, addictionChance, consumptionSound, pad14, data, GetData1: GUESS(low) STANDIN
#pragma once
#include "MagicItem_146428.h"

class Owner5c3f6c :
    public MagicItem,
    public TESModelTextureSwap,
    public TESIcon,
    public BGSMessageIcon,
    public TESWeightForm,
    public BGSEquipType,
    public BGSDestructibleObjectForm,
    public BGSPickupPutdownSounds
{
public:
    Owner5c3f6c();
    ~Owner5c3f6c() override;
    const MagicItem::Data* GetData1() const override;

private:
    struct Data : MagicItem::Data
    {
        SpellItem* addictionItem;
        float addictionChance;
        std::uint32_t pad14;
        BGSSoundDescriptorForm* consumptionSound;
    };
    Data data;
};
