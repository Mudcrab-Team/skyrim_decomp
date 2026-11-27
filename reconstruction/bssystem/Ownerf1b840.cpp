// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build. Stamped as a twin of matched 0xf12a70 (bssystem/NiStream_19e930): source copied, names replaced by placeholders.
// 0xf1b840 Ownerf1b840::Functionf1b840
#include "Ownerf1b840.h"
#include <cstring>

// guess: same compiled code as matched 0xf12a70 apart from relocated fields; its role here is not established.
void Ownerf1b840::Functionf1b840(std::uint32_t* values, std::uint32_t count)
{
    auto* binary = iStr;
    std::uint32_t width = sizeof(*values);
    const auto transferred = binary->_readFn(binary, values, count * sizeof(*values), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}
