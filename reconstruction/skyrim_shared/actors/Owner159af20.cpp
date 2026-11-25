// Source exposure: mixed (pinned image and RTTI, project layouts, and CommonLib declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE names; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original bodies using the cited declarations and the observed receiver offsets. Stamped as a twin of matched 0x6a51b0 (skyrim_shared/actors/Actor_674b70): source copied, names replaced by placeholders.
// 0x159af20 Owner159af20::Function159af20
#include "Owner159af20.h"

struct MovementKey;

class MotionGate
{
public:
    virtual ~MotionGate();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual void FunctionSlot04();
    virtual void FunctionSlot05();
    virtual bool FunctionSlot06() const;
};

class IMovementControllerRegisterInterface
{
public:
    virtual ~IMovementControllerRegisterInterface();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual MotionGate* FunctionSlot03(const MovementKey& key);
};

class MovementControllerNPC : public IMovementControllerRegisterInterface
{
};

Owner159af20::Owner159af20()
{
}

// guess: same compiled code as matched 0x6a51b0 apart from relocated fields; its role here is not established.
MovementControllerNPC* const& Owner159af20::Function159af20() const
{
    return movementController;
}
