// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// QClassType: SIBLING(fo4-private@1b765c70, author-permission)
// MovementHandlerAgentSprintActionTrigger, Function7a5c30, IMovementSetSprinting, SprintTarget, Unregister, unk30: GUESS(low)
#pragma once

#include <cstdint>

class IMovementSetSprinting
{
public:
    static const void* QClassType();  // callee, matched elsewhere
};

class SprintTarget
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void Unregister(const void* a_type);
};

class MovementHandlerAgentSprintActionTrigger
{
public:
    void Function7a5c30();  // compared: 0x7a5c30

    char unk00[0x30];
    SprintTarget* unk30;
};
