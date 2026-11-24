// Source exposure: mixed (sibling source; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/Game/AI/Movement/MovementHandlerAgentStairsHelper.cpp:37
// pActor, MovementHandlerAgentStairsHelper: SIBLING(fo4-private@1b765c70, author-permission) STANDIN
// MovementHandlerAgentStairsHelper: CRASHLOGGER_PDB(59818@2026.10.24)
// MovementHandlerAgent, IMovementHandlerInterface, unk08, unk28: GUESS(low)
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

class MovementHandlerAgentStairsHelper : public MovementHandlerAgent, public IMovementHandlerInterface
{
public:
    MovementHandlerAgentStairsHelper();  // compared: 0x7a6610
    ~MovementHandlerAgentStairsHelper() override;

    void* pActor;  // 20
    std::uint8_t unk28[0x8];
};
static_assert(sizeof(MovementHandlerAgentStairsHelper) == 0x30, "movement agent size");
