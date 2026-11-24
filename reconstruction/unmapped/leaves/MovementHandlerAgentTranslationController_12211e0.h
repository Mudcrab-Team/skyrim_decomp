// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentSprintActionTrigger.cpp:4
// MovementHandlerAgent, IMovementInterface: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// MovementHandlerAgentTranslationController, IMovementInterface: CRASHLOGGER_PDB(59818@2026.10.24)
// IMovementHandlerInterface, IMovementTranslationInterface, unk08, unk28: GUESS(low)
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

class IMovementTranslationInterface : public IMovementInterface
{
public:
    ~IMovementTranslationInterface() override {}
};

class MovementHandlerAgentTranslationController : public MovementHandlerAgent, public IMovementHandlerInterface, public IMovementTranslationInterface
{
public:
    MovementHandlerAgentTranslationController();
    ~MovementHandlerAgentTranslationController() override;  // compared: 0x12211e0

    std::uint8_t unk28[0x18];
};
static_assert(sizeof(MovementHandlerAgentTranslationController) == 0x40, "sprint trigger size");
