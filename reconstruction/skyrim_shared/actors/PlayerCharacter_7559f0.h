// Source exposure: mixed (community headers; the pinned image listing; CrashLogger names).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// PlayerCharacter, PlayerFlags, TESPackage, PlayerCamera: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to what this function uses
// ActorProcess, SetAIDriven, GetPackageThatIsRunning: CRASHLOGGER_PDB(59818@2026.10.24)
// aiControlledPackage: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the flags sit at 0xBE8 in this build
// ControlHolder, GetControlHolder, unkF8, unkBE8, unk24, gPlayerCamera, ResetPlayerCamera: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESPackage
{
public:
    char unk00[0x24];
    std::uint8_t unk24;
};

class ActorProcess
{
public:
    TESPackage* GetPackageThatIsRunning();
};

class PlayerCamera;

struct ControlHolder
{
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
    virtual void Enable();
    virtual void Disable();
};

struct PlayerFlags
{
    char unk00[2];
    bool unk2_0 : 1;
    bool aiControlledToPos : 1;
    bool aiControlledFromPos : 1;
    bool aiControlledPackage : 1;
    bool returnToLastKnownGoodPosition : 1;
    bool isBeingChased : 1;
    bool unk2_6 : 1;
    bool unk2_7 : 1;
};

extern PlayerCamera* gPlayerCamera;
void ResetPlayerCamera(PlayerCamera* camera);

class PlayerCharacter
{
public:
    void SetAIDriven(bool aiDriven);
    ControlHolder** GetControlHolder();

    char unk000[0xF8];
    ActorProcess* unkF8;
    char unk100[0xBE8 - 0x100];
    PlayerFlags unkBE8;
};
