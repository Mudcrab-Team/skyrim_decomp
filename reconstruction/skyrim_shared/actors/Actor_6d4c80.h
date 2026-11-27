// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and CrashLogger PDB declarations only
// SPDX-License-Identifier: CC0-1.0
// ActorMagicCaster, Actor, Actor::magicCasters, Actor::sub_1406302B0: CRASHLOGGER_PDB(59818@2026.10.24)
// g_threadState_tls_0x768, ThreadStateScope6d4c80, Actor::unk00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern __declspec(thread) std::uint32_t g_threadState_tls_0x768;

class ThreadStateScope6d4c80
{
public:
    explicit ThreadStateScope6d4c80(std::uint32_t a_value) : saved(g_threadState_tls_0x768) { g_threadState_tls_0x768 = a_value; }
    ~ThreadStateScope6d4c80() { g_threadState_tls_0x768 = saved; }

private:
    std::uint32_t saved;
};

class ActorMagicCaster
{
public:
    virtual ~ActorMagicCaster() noexcept;
};

class Actor
{
public:
    void sub_1406302B0();

    std::uint8_t      unk00[0x1a8];
    ActorMagicCaster* magicCasters[4];  // 0x1a8
};
static_assert(offsetof(Actor, magicCasters) == 0x1a8, "Actor::magicCasters offset");
