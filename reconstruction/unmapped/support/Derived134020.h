// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// Base134020, Derived134020: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>

struct Base134020
{
    ~Base134020();

    std::uint64_t unk00[11];  // 0x00
};

static_assert(sizeof(Base134020) == 0x58, "Base134020 size");

struct Derived134020 : Base134020
{
    ~Derived134020();  // compared: 0x134020

    std::vector<void*> items;  // 0x58
};

static_assert(sizeof(Derived134020) == 0x70, "Derived134020 size");
