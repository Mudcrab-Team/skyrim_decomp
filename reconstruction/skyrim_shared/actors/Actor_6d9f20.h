// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Actor, Actor::Function6d9f20, Actor::unk188: GUESS(low); a view of the node list head at 0x188 only
// g_threadState6d9f20 ThreadStateScope6d9f20 ListNode6d9f20 ListNode6d9f20::next: GUESS(low); a thread-local value at TLS offset 0x768, saved, set and restored around the body
#pragma once

#include <cstdint>

extern __declspec(thread) std::uint32_t g_threadState6d9f20;

class ThreadStateScope6d9f20
{
public:
    explicit ThreadStateScope6d9f20(std::uint32_t a_value) : saved(g_threadState6d9f20) { g_threadState6d9f20 = a_value; }
    ~ThreadStateScope6d9f20() { g_threadState6d9f20 = saved; }

private:
    std::uint32_t saved;
};

struct ListNode6d9f20
{
    void* unk00;
    void* unk08;
    ListNode6d9f20* next;  // 0x10
};

class Actor
{
public:
    void Function6d9f20();

    std::uint8_t pad000[0x188];
    ListNode6d9f20* unk188;  // 0x188
};
