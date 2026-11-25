// Source exposure: mixed
// Code origin: written for this reconstruction from the listing; names and layout from the unit header. Stamped as a twin of matched 0x5d3e00 (skyrim/magic/ActiveEffect): source copied, names replaced by placeholders.
// Origin: independently decoded target, anonymous sibling hint, and public declarations.
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:12
// Sibling source: fo4-private@1b765c70 src/Game/Magic/ActiveEffect.cpp:203
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Function1599520, Owner1599520: GUESS(low) STANDIN
#pragma once
#include "ActiveEffect.h"

class Owner1599520 {
public:
    virtual void* GetVisualsTarget();
    virtual void* VirtualSlot1();
    virtual void* VirtualSlot2();
    virtual void* VirtualSlot3();
    virtual void* VirtualSlot4();
    virtual void* VirtualSlot5();
    virtual void* VirtualSlot6();
    virtual void* VirtualSlot7();
    virtual void* VirtualSlot8();
    virtual void* VirtualSlot9();
    virtual void* VirtualSlot10();
    virtual void* VirtualSlot11();
    virtual void* VirtualSlot12();
    bool CanFinish() const;
    EffectController hitEffectController;
    SoundHandle persistentSound;
    unsigned caster;
    void* sourceNode;
    MagicItem* spell;
    EffectItemInfo* effect;
    MagicTarget* target;
    void* source;
    void* hitEffects;
    void* displacementSpell;
    float elapsedSeconds, duration, magnitude;
    unsigned flags, conditionStatus;
    unsigned short uniqueID, pad86;
    unsigned castingSource;
public:
    void* Function1599520();
};

