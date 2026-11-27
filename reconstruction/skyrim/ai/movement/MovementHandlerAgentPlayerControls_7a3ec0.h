// Source exposure: mixed (local pinned-image observations; permitted sibling game-code study).
// Code origin: original reconstruction; no sibling bodies adapted.
// SPDX-License-Identifier: CC0-1.0
// MovementHandlerAgentPlayerControls::Func7_1406FB980: CRASHLOGGER_PDB(59818@2026.10.24)
// MovementHandlerAgentPlayerControls, PlayerInputStream, PlayerControlInputSink and their members: GUESS(low) STANDIN; observed virtual slots and object offset.
#pragma once
#include <cstdint>
#include <cstddef>

// PlayerInputValue: GUESS(low) STANDIN; a scalar wrapper returned through caller storage.
struct PlayerInputValue
{
    std::uint32_t value;
    PlayerInputValue();
};
struct PlayerInputStream
{
    virtual void unknown00();
    virtual void unknown01();
    virtual void unknown02();
    virtual void unknown03();
    virtual PlayerInputValue ReadInput();
};
struct PlayerControlInputSink
{
    virtual void unknown00();
    virtual void unknown01();
    virtual void unknown02();
    virtual void SetInput(std::uint32_t value);
};
class MovementHandlerAgentPlayerControls
{
public:
    void Func7_1406FB980(PlayerInputStream* stream);
    std::uint8_t unknown00[0x20];
    PlayerControlInputSink inputSink;
};
static_assert(offsetof(MovementHandlerAgentPlayerControls, inputSink) == 0x20, "input sink offset");
