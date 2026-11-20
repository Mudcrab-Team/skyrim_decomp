// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build.
// 0xf10eb0 NiFloatExtraData::LoadBinary
// 0xf10f30 NiFloatExtraData::SaveBinary
#include "NiFloatExtraData_f10eb0.h"

void NiFloatExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_readFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiFloatExtraData::SaveBinary(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_writeFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}
