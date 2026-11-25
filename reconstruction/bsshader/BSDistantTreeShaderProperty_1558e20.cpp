// Source exposure: mixed (pinned image, community declarations and permitted symbol prototypes).
// Code origin: reconstruction using the labelled sources and pinned-image observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1558e20 BSDistantTreeShaderProperty::ForEachTexture
#include "BSDistantTreeShaderProperty_1558e20.h"

std::int32_t BSDistantTreeShaderProperty::ForEachTexture(BSShaderProperty::ForEachVisitor& visitor)
{
    std::int32_t result;
    for (std::int64_t index = 0; index < 1; ++index) {
        result = visitor.Accept(spTexture[index]);
        if (result <= 0)
            break;
    }
    return result;
}
