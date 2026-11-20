// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original implementations based on the pinned game build.
// 0xf12100 NiIntegerExtraData::LoadBinary
// 0xf12180 NiIntegerExtraData::SaveBinary
// 0xf12380 NiIntegerExtraData::dtor
#include "NiIntegerExtraData_f12100.h"

NiIntegerExtraData::NiIntegerExtraData() = default;

void NiIntegerExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_readFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

void NiIntegerExtraData::SaveBinary(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(value);
    const auto transferred = binary->_writeFn(binary, &value, sizeof(value), &width, 1);
    binary->_absoluteCurrentPos += transferred;
}

NiIntegerExtraData::~NiIntegerExtraData()
{

}
