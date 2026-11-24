// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSTempEffectSPG, BSTempEffectSPG::spg3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSTempEffectSPG::DetachGeometry, pad00: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>
#include "gamebryo/nimain/NiAVObject.h"

class BSTempEffectSPG
{
public:
    void DetachGeometry();

    std::uint8_t pad00[0x38];
    NiAVObject* spg3D;
};

static_assert(offsetof(BSTempEffectSPG, spg3D) == 0x38, "particle geometry offset");
