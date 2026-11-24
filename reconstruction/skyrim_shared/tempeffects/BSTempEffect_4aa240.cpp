// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x4aa240 BSTempEffect::BSTempEffect
// Adapted bodies: none
// DuplicateDebrisFileName: GUESS(low); nullable copy for the owned file name.
#include "BSTempEffect_4aa240.h"

#include <cstring>

static inline const char* DuplicateDebrisFileName(const char* name)
{
    if (name == nullptr) {
        return nullptr;
    }
    const auto length = std::strlen(name) + 1;
    auto* copy = new char[length];
    std::memcpy(copy, name, length);
    return copy;
}

BSTempEffect::BSTempEffect() :
    BSTempEffectBase(nullptr, 0.0f),
    debris3D(nullptr),
    debrisFileName(DuplicateDebrisFileName(nullptr)),
    unk40(0)
{
}
