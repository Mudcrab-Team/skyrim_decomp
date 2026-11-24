// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.cpp:4
// MovementHandlerAgentSprintActionTrigger, MovementHandlerAgent, IMovementSetSprinting, IMovementInterface, eState, bWantSprinting, bCrippled: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// BSPathingStreamWrite, SaveGame: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// MovementHandlerAgentSprintActionTrigger, MovementHandlerAgent, IMovementInterface: CRASHLOGGER_PDB(59818@2026.10.24)
// IMovementHandlerInterface, DoWriteUInt, DoWriteBool, unk08, unk28: GUESS(low)
#pragma once

#include <cstdint>

class MovementHandlerAgent
{
public:
    MovementHandlerAgent();
    virtual ~MovementHandlerAgent();

    std::uint8_t unk08[0x10];
};

class IMovementHandlerInterface
{
public:
    virtual void unk00();
};

class IMovementInterface
{
public:
    virtual ~IMovementInterface();
};

class IMovementSetSprinting : public IMovementInterface
{
public:
    ~IMovementSetSprinting() override {}
};

class BSPathingStreamWrite
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void DoWriteUInt(std::uint32_t a_value);  // 04
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void DoWriteBool(bool a_value);  // 10
};

class MovementHandlerAgentSprintActionTrigger : public MovementHandlerAgent, public IMovementHandlerInterface, public IMovementSetSprinting
{
public:
    MovementHandlerAgentSprintActionTrigger();
    ~MovementHandlerAgentSprintActionTrigger() override;  // compared: 0x7a5ac0
    virtual void SaveGame(BSPathingStreamWrite& a_stream) const;

    std::uint8_t unk28[0x10];
    std::uint32_t eState;     // 38
    bool bWantSprinting;      // 3C
    bool bCrippled;           // 3D
};
static_assert(sizeof(MovementHandlerAgentSprintActionTrigger) == 0x40, "sprint trigger size");
