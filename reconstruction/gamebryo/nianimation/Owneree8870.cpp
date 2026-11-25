// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf66fa0 (gamebryo/nianimation/NiPathInterpolator_f64ac0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xee8870 Owneree8870::Functionee8870
#include "Owneree8870.h"

// guess: same compiled code as matched 0xf66fa0 apart from relocated fields; its role here is not established.
void Owneree8870::Functionee8870(NiStream& stream, const std::uint16_t& value)
{
    auto& binary = *stream.oStr;
    std::uint32_t width = sizeof(std::uint16_t);
    const auto transferred = binary._writeFn(&binary, &value, sizeof(value), &width, 1);
    binary._absoluteCurrentPos += transferred;
}
