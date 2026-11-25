// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1d1d50 (skyrim/ai/combat/BGSAttackDataForm_1d1d50): source copied, names replaced by placeholders.
// SPDX-License-Identifier: CC0-1.0
// AttackData: GUESS(low); minimal stand-ins, layout from the listing
// Functioneeb360, Ownereeb360: GUESS(low) STANDIN
// attackData, pad00: GUESS(low) STANDIN
#pragma once
#include "BGSAttackDataForm_1d1d50.h"

class Ownereeb360
{
public:
    void Functioneeb360(AttackData* a_data);

    std::uint8_t pad00[0x18];
    AttackData* attackData;
};

