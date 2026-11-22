// Source exposure: community-headers
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// DetectLifeEffect, CheckTarget: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
// MagicTarget: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetOwnerActor: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// CheckTargetArgs, target, caster: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); names and two member offsets from that header, so this file is GPL-3.0
// g_player: GUESS(low); the player singleton pointer
#pragma once

class Actor;

class MagicTarget
{
public:
    Actor* GetOwnerActor();  // bound: 0x5d26e0
};

namespace ActiveEffectFactory
{
    struct CheckTargetArgs
    {
        MagicTarget* target;  // 00
        Actor* caster;        // 08
    };
}

extern Actor* g_player;

class DetectLifeEffect
{
public:
    static bool CheckTarget(ActiveEffectFactory::CheckTargetArgs& a_args);  // compared: 0x5c5900
};
