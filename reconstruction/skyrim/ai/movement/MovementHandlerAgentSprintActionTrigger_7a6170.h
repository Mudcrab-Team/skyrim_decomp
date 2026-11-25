// Source exposure: mixed (pinned-image observations; community and symbol names).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: CC0-1.0
// MovementHandlerAgentSprintActionTrigger, Func12_1406FD830: CRASHLOGGER_PDB(59818@2026.10.24)
// eState, bWantSprinting, bCrippled: SYMBOLS(fo4-pdb)
// BSPathingStreamRead: STANDIN GUESS(low)
// ReadState, ReadBool, GetVersion, SprintState: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
class BSPathingStreamRead
{
public:
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void ReadState(std::uint32_t&) = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void ReadBool(bool&) = 0;
    virtual void Slot0B() = 0;
    virtual void Slot0C() = 0;
    virtual void Slot0D() = 0;
    virtual void Slot0E() = 0;
    virtual void Slot0F() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Slot12() = 0;
    virtual std::uint32_t GetVersion() = 0;
};
class MovementHandlerAgentSprintActionTrigger
{
public:
    void Func12_1406FD830(BSPathingStreamRead& stream);
    std::uint8_t unk00[0x38];
    std::uint32_t eState;
    bool bWantSprinting;
    bool bCrippled;
};
static_assert(offsetof(MovementHandlerAgentSprintActionTrigger, eState) == 0x38, "state offset");
