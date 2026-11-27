// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing, CommonLibSSE-NG declarations and CrashLogger PDB declarations only
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorValueOwner, ActorValueOwner::ModifyActorValue_140351740: CRASHLOGGER_PDB(59818@2026.10.24)
// ActorValueOwner::GetBaseActorValue, ActorValueOwner::SetBaseActorValue: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValueOwner::Unk_01, ActorValueOwner::Unk_02: GUESS(low)
#pragma once

#include <cstdint>

class ActorValueOwner
{
public:
    virtual ~ActorValueOwner();
    virtual float Unk_01(std::int32_t a_av) const;
    virtual float Unk_02(std::int32_t a_av) const;
    virtual float GetBaseActorValue(std::int32_t a_av) const;         // 0x03 (0x18)
    virtual void  SetBaseActorValue(std::int32_t a_av, float a_val);  // 0x04 (0x20)

    void ModifyActorValue_140351740(std::int32_t a_av, float a_delta);
};
