// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// Data8f1ad0, Manager8f1ad0, Character8f1ad0, g_targetId8f1ad0, g_manager8f1ad0, g_minScale8f1ad0, GetData, ComputeScaledValue, unk00, baseValue, factor, count, id: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Data8f1ad0
{
    std::uint64_t unk00[4];  // 0x00
    float baseValue;         // 0x20
    std::uint32_t unk24;     // 0x24
    float factor;            // 0x28
};
static_assert(offsetof(Data8f1ad0, baseValue) == 0x20, "baseValue offset");
static_assert(offsetof(Data8f1ad0, factor) == 0x28, "factor offset");

struct Manager8f1ad0
{
    std::uint8_t unk00[0xAD0];  // 0x000
    std::uint32_t count;        // 0xAD0
};
static_assert(offsetof(Manager8f1ad0, count) == 0xAD0, "count offset");

extern std::uint32_t g_targetId8f1ad0;
extern Manager8f1ad0* g_manager8f1ad0;
extern float g_minScale8f1ad0;

class Character8f1ad0
{
public:
    Data8f1ad0* GetData();
    float ComputeScaledValue();

    std::uint8_t unk00[0x104];  // 0x000
    std::uint32_t id;           // 0x104
};
static_assert(offsetof(Character8f1ad0, id) == 0x104, "id offset");
