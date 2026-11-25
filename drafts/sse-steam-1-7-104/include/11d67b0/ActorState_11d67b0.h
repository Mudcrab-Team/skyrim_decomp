// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorState, Movement, MaxSpeeds, speeds, rotateWhileMovingRun: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoGetMovementSpeed, DoGetRotationSpeed, Unk_01, Unk_02, Unk_03, Unk_04, Unk_07: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// DoGetCurrentMaxSpeeds: SYMBOLS(tesv-2013-map); query signature inferred locally
// GetForwardRunSpeed: GUESS(low); selected component of queried speeds

#pragma once

#include <cstddef>

namespace Movement
{
struct MaxSpeeds
{
    float speeds[5][2]; // 00
    float rotateWhileMovingRun; // 28
};
static_assert(sizeof(MaxSpeeds) == 0x2C, "movement speed data size");
}

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
    virtual bool DoGetCurrentMaxSpeeds(Movement::MaxSpeeds&);
    float GetForwardRunSpeed();
};
