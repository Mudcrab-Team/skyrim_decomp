// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActiveEffect, target: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AllowHitEffects: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb); the unit keeps the placeholder class ActiveEffect
// MagicTarget: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetOwnerActor: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_player, g_hitEffectSource, g_hitEffectCounter: GUESS(low); globals the function reads
#pragma once

class Actor;

class MagicTarget
{
public:
    Actor* GetOwnerActor();  // bound: 0x5d26e0
};

struct HitEffectSource
{
    unsigned char pad00[0x160];  // 00
    unsigned int count;          // 160
};

extern Actor* g_player;
extern HitEffectSource* g_hitEffectSource;
extern int g_hitEffectCounter;

class ActiveEffect
{
public:
    bool AllowHitEffects();  // compared: 0x74a6f0

    unsigned char pad00[0x50];  // 00
    MagicTarget* target;        // 50
};
