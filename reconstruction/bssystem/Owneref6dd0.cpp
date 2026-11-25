// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xf12ab0 (bssystem/NiStream_19e930): source copied, names replaced by placeholders.
// 0xef6dd0 Owneref6dd0::Functionef6dd0
#include "Owneref6dd0.h"
#include <cstring>

// guess: same compiled code as matched 0xf12ab0 apart from relocated fields; its role here is not established.
void Owneref6dd0::Functionef6dd0(const std::uint32_t* values, std::uint32_t count)
{
    auto* binary = oStr;
    std::uint32_t width = sizeof(*values);
    const auto transferred = binary->_writeFn(binary, values, count * sizeof(*values), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}
