// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// ListNode127e90, Target127e90, gListHead127e90, gNextId127e90, Function127e90: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct ListNode127e90
{
    std::uint32_t kind;    // 0x00
    std::uint32_t unk04;   // 0x04
    std::uint64_t unk08;   // 0x08
    std::uint64_t unk10;   // 0x10
    std::uint64_t unk18;   // 0x18
    std::uint64_t unk20;   // 0x20
    void* value;           // 0x28
    ListNode127e90* next;  // 0x30
};

struct Target127e90
{
    std::uint64_t unk00;   // 0x00
    std::uint32_t unk08;   // 0x08
    std::uint8_t ready;    // 0x0c
    void* value;           // 0x10
    std::uint32_t state;   // 0x18
    std::uint64_t seqId;   // 0x20
};

extern ListNode127e90* gListHead127e90;
extern std::uint64_t gNextId127e90;

void Function127e90(Target127e90* a_target);  // compared: 0x127e90
