// Near miss: 4.5 alignment distance | control-flow
// Best attempt 1: function-size-mismatch; candidate size 52, target size 58; 33/58 aligned bytes.
// Remaining differences include control flow and Boolean materialization; stopped after compare 4.
// Exposure detail: (community declarations and pinned-image observations).
// Source exposure: mixed
// Code origin: original handwritten reconstruction
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// 0x2c4080 TESObjectCELL::Function2c4080

#include "include/2c4080/TESObjectCELL_2c4080.h"

bool TESObjectCELL::Function2c4080(std::uint32_t now, std::uint32_t last, bool cleared)
{
    const int zero_ = 0;
    if (last == 0)
        return true;
    std::uint32_t interval = resetInterval;
    if (cleared)
        interval = clearedInterval;
    unsigned char result = zero_;
    if (now > last) {
        now -= last;
        if (now > interval)
            result = 1;
    }
    return result;
}
