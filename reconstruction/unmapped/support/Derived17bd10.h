// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Base17bd10: GUESS(low)
// Derived17bd10: GUESS(low)
#pragma once

#include <cstdint>

struct Base17bd10
{
    virtual ~Base17bd10()
    {
    }
};

struct Derived17bd10 : Base17bd10
{
    ~Derived17bd10() override;

    std::uint64_t unk08;
    char* buffer;
};
