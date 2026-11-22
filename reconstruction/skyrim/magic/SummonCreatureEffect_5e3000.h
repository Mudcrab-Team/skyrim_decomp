// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SummonCreatureEffect, ClearTargetImpl, summonPlacementEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ClearTargetImpl name also appears in the FO4 symbols: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// ActiveEffect, MagicTarget, InvalidateCommandedActorEffect, SummonPlacementEffect, target: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk30: GUESS(low); the member of the placement effect the function clears
#pragma once

class ActiveEffect;

class MagicTarget
{
public:
    virtual ~MagicTarget();                                              // 00
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void InvalidateCommandedActorEffect(ActiveEffect* a_effect);  // 05
};

class SummonPlacementEffect
{
public:
    unsigned char pad00[0x30];  // 00
    void* unk30;                // 30
};

class ActiveEffect
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
    virtual void ClearTargetImpl();  // 12

    unsigned char pad08[0x48];  // 08
    MagicTarget* target;        // 50
};

class SummonCreatureEffect : public ActiveEffect
{
public:
    void ClearTargetImpl() override;  // 12 (compared: 0x5e3000)

    unsigned char pad58[0x58];                    // 58
    SummonPlacementEffect* summonPlacementEffect;  // B0
};
