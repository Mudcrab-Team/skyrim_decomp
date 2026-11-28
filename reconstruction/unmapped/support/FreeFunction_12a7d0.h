// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// FuncImpl12a7d0, FuncStorage12a7d0, Function12a7d0: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct FuncImpl12a7d0
{
    virtual FuncImpl12a7d0* Copy(void* a_where) const = 0;
};

struct FuncStorage12a7d0
{
    std::uint64_t unk00[7];  // 0x00
    FuncImpl12a7d0* impl;    // 0x38
};

void Function12a7d0(FuncStorage12a7d0* a_dst, const FuncStorage12a7d0* a_src);  // compared: 0x12a7d0
