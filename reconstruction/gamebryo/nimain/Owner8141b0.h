// Source exposure: binary-analysis (names are guesses; layout read from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0xeeb4f0 (gamebryo/nimain/BSDynamicTriShape_eeb4f0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// RefCounted: GUESS(low)
// Function8141b0, Owner8141b0: GUESS(low) STANDIN
#pragma once
#include "BSDynamicTriShape_eeb4f0.h"

// The class keeps the placeholder name of the unit.
class Owner8141b0
{
public:
    void Function8141b0();

    std::uint8_t pad00[0x60];  // 0x00
    RefCounted* object;  // 0x18
};

