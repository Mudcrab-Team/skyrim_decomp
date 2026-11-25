// Source exposure: mixed (local target observations; permitted sibling game-code study).
// Code origin: original reconstruction; no adapted bodies.
// SPDX-License-Identifier: CC0-1.0
// MovementHandlerAgentPlayerControls: SIBLING(fo4-private@1b765c70, author-permission)
// MovementHandlerAgentPlayerControls::Func12_1406FC1F0: CRASHLOGGER_PDB(59818@2026.10.24)
// PlayerInputStream, PlayerInputStream members, unknown00, unknown38, unknown3c, unknown48, unknown4c: GUESS(low) STANDIN; opaque stream values and observed offsets.
#pragma once
#include <cstddef>
#include <cstdint>

struct PlayerInputStream
{
    virtual void unknown00();
    virtual void ReadValue1(std::uint32_t* value);
    virtual void unknown02();
    virtual void unknown03();
    virtual void ReadValue4(std::uint32_t* value);
    virtual void unknown05();
    virtual void unknown06();
    virtual void unknown07();
    virtual void unknown08();
    virtual void unknown09();
    virtual void ReadValue10(std::uint32_t* value);
};
class MovementHandlerAgentPlayerControls
{
public:
    void Func12_1406FC1F0(PlayerInputStream* stream);
    std::uint8_t unknown00[0x38];
    std::uint32_t unknown38;
    std::uint8_t unknown3c[0x0c];
    std::uint32_t unknown48;
    std::uint32_t unknown4c;
};
static_assert(offsetof(MovementHandlerAgentPlayerControls, unknown38) == 0x38, "input value offset");
static_assert(offsetof(MovementHandlerAgentPlayerControls, unknown48) == 0x48, "second stream destination");
static_assert(offsetof(MovementHandlerAgentPlayerControls, unknown4c) == 0x4c, "third stream destination");
