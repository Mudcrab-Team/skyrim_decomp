// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorState, Unk_01, Unk_02, Unk_03, Unk_04, DoGetMovementSpeed, DoGetRotationSpeed, Unk_07: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoGetCurrentMaxSpeeds: SYMBOLS(tesv-2013-map); inferred virtual-slot association
// ReadMaxSpeedComponent, MaxSpeedData, SpeedPair, pairs, values, trailing: GUESS(low); unknown semantic component
// MaxSpeedData: STANDIN GUESS(low); only the observed output-buffer extent is represented

#pragma once
#include <cstdint>

struct SpeedPair
{
    float values[2];
};

struct MaxSpeedData
{
    SpeedPair pairs[5];
    float trailing;
};
static_assert(sizeof(MaxSpeedData) == 44, "output-buffer extent");

class ActorState
{
public:
    virtual ~ActorState();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual float DoGetMovementSpeed();
    virtual float DoGetRotationSpeed();
    virtual void Unk_07();
    virtual bool DoGetCurrentMaxSpeeds(MaxSpeedData& speeds);
    float ReadMaxSpeedComponent();
};
