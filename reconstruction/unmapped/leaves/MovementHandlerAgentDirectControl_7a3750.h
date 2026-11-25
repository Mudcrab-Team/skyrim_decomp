// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentDirectControl.cpp:79
// pRegisterInterface, MovementHandlerAgentDirectControl: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// MovementHandlerAgentDirectControl: CRASHLOGGER_PDB(59818@2026.10.24)
// MovementHandlerAgent, IMovementHandlerInterface, unk08, unk20, unk50: GUESS(low)
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

class MovementHandlerAgentDirectControl : public MovementHandlerAgent, public IMovementHandlerInterface
{
public:
    MovementHandlerAgentDirectControl();
    ~MovementHandlerAgentDirectControl() override;  // compared: 0x7a3750 (scalar deleting destructor)

    std::uint8_t unk20[0x28];
    void* pRegisterInterface;  // 48
    std::uint8_t unk50[0x28];
};
static_assert(sizeof(MovementHandlerAgentDirectControl) == 0x78, "movement agent size");
