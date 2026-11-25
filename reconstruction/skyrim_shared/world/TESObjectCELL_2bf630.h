// Source exposure: mixed (community declarations and pinned-image observations).
// Code origin: original handwritten reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL::cellFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL::Function2bf630, TESObjectCELL::unknown20: GUESS(low)
#pragma once
#include <cstdint>
#include "declarations/TESForm.h"

class TESObjectCELL : public TESForm
{
public:
    void Function2bf630(bool enabled);
    std::uint8_t unknown20[0x20];
    std::uint16_t cellFlags;
};
