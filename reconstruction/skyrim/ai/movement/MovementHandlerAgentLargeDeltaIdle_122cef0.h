// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// MovementHandlerAgentLargeDeltaIdle, MovementHandlerAgentLargeDeltaIdle::Func6_141117470: CRASHLOGGER_PDB(59818@2026.10.24)
// BSFixedString, LargeDeltaInterface, LargeDeltaInterfaceHolder, gLargeDeltaInterfaceName, QueryInterface, ClearIdle, holder, state: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct BSFixedString
{
    const char* data;  // 00
};

extern BSFixedString gLargeDeltaInterfaceName;

class LargeDeltaInterface
{
public:
    virtual ~LargeDeltaInterface();  // 00
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void ClearIdle();  // 04 (0x20)
};

class LargeDeltaInterfaceHolder
{
public:
    virtual ~LargeDeltaInterfaceHolder();  // 00
    virtual void Slot01();
    virtual void Slot02();
    virtual LargeDeltaInterface* QueryInterface(const BSFixedString& a_name);  // 03 (0x18)
};

class MovementHandlerAgentLargeDeltaIdle
{
public:
    virtual ~MovementHandlerAgentLargeDeltaIdle();
    void Func6_141117470();  // compared: 0x122cef0

    std::uint8_t unk08[0x18];  // 08
    LargeDeltaInterfaceHolder* holder;  // 20
    std::uint32_t state;  // 28
};
static_assert(offsetof(MovementHandlerAgentLargeDeltaIdle, holder) == 0x20, "holder offset");
static_assert(offsetof(MovementHandlerAgentLargeDeltaIdle, state) == 0x28, "state offset");
