// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentPlayerControlsActionTrigger.cpp:25
// MovementHandlerAgentPlayerControlsActionTrigger, MovementHandlerAgent, MyHandle, iBits: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// MovementHandlerAgentPlayerControlsActionTrigger, MovementHandlerAgent: CRASHLOGGER_PDB(59818@2026.10.24)
// BSPointerHandle, IMovementInterface, unk08: GUESS(low)
#pragma once

#include <cstdint>

struct BSPointerHandle
{
    BSPointerHandle() : iBits(0) {}

    std::uint32_t iBits;
};

class MovementHandlerAgent
{
public:
    MovementHandlerAgent();
    virtual ~MovementHandlerAgent();

    std::uint8_t unk08[0x10];
};

class IMovementInterface
{
public:
    virtual ~IMovementInterface() {}
};

class MovementHandlerAgentPlayerControlsActionTrigger : public MovementHandlerAgent, public IMovementInterface
{
public:
    MovementHandlerAgentPlayerControlsActionTrigger();  // compared: 0x7a5680
    ~MovementHandlerAgentPlayerControlsActionTrigger() override;

    BSPointerHandle MyHandle;  // 20
};
static_assert(sizeof(MovementHandlerAgentPlayerControlsActionTrigger) == 0x28, "trigger size");
