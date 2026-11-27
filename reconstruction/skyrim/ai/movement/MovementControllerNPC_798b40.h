// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original; pinned-image observations and labelled naming sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MovementControllerNPC: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IMovementMotionDrivenControl: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// IMovementMotionDrivenControl::Unk_01, IMovementMotionDrivenControl::Unk_02, IMovementMotionDrivenControl::Unk_03, IMovementMotionDrivenControl::Unk_04, IMovementMotionDrivenControl::Unk_05, IMovementMotionDrivenControl::Unk_06, IMovementMotionDrivenControl::Unk_07, IMovementMotionDrivenControl::Unk_08: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; unknown return types narrowed to observed boolean results.
// MovementControllerNPC::Function798b40, MovementControllerNPC::unk000, MovementControllerNPC::motionDrivenControl: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
class IMovementMotionDrivenControl
{
public:
    virtual ~IMovementMotionDrivenControl();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual bool Unk_06();
    virtual bool Unk_07();
    virtual bool Unk_08();
};
class MovementControllerNPC
{
public:
    void Function798b40();
    std::uint8_t unk000[0x128];
    IMovementMotionDrivenControl motionDrivenControl;
};
static_assert(offsetof(MovementControllerNPC, motionDrivenControl) == 0x128, "observed interface offset");
