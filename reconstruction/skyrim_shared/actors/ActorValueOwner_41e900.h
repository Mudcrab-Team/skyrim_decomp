// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// ActorValueOwner, ActorValueOwner::GetArmorRatingSkillMultiplier: CRASHLOGGER_PDB(59818@2026.10.24)
// fPlayerMaxMult41e900, fPlayerMinMult41e900, fNpcMaxMult41e900, fNpcMinMult41e900, ActorValueOwner::Unk_01 to Unk_07, ActorValueOwner::GetIsPlayerOwner: GUESS(low)
#pragma once

extern float fPlayerMaxMult41e900;
extern float fPlayerMinMult41e900;
extern float fNpcMaxMult41e900;
extern float fNpcMinMult41e900;

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
