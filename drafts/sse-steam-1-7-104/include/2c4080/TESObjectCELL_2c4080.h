// Best attempt 1: function-size-mismatch; candidate size 52, target size 58; 33/58 aligned bytes.
// Remaining differences include control flow and Boolean materialization; stopped after compare 4.
// Exposure detail: (community declarations and pinned-image observations).
// Source exposure: mixed
// Code origin: original handwritten reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESObjectCELL: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESObjectCELL::Function2c4080, resetInterval, clearedInterval: GUESS(low)

#pragma once
#include <cstdint>

extern std::uint32_t resetInterval;
extern std::uint32_t clearedInterval;

class TESObjectCELL
{
public:
    static bool Function2c4080(std::uint32_t now, std::uint32_t last, bool cleared);
};
