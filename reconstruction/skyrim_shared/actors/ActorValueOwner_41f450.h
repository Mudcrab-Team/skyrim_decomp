// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// ActorValueOwner, ActorValueOwner::GetArmorRatingSkillMultiplier: CRASHLOGGER_PDB(59818@2026.10.24)
// fPlayerMaxMult41f450, fPlayerMinMult41f450, fNpcMaxMult41f450, fNpcMinMult41f450, ActorValueOwner::Unk_01 to Unk_07, ActorValueOwner::GetIsPlayerOwner: GUESS(low)
#pragma once

extern float fPlayerMaxMult41f450;
extern float fPlayerMinMult41f450;
extern float fNpcMaxMult41f450;
extern float fNpcMinMult41f450;

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual bool GetIsPlayerOwner() const;  // 0x08 (0x40)

    static float GetArmorRatingSkillMultiplier(const ActorValueOwner* a_owner, float a_skill);
};
