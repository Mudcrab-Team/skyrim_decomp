// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf0fe70 NiBooleanExtraData::LoadBinary
// 0xf0ff00 NiBooleanExtraData::SaveBinary
// Adapted bodies: none
#include "NiBooleanExtraData_f0fe70.h"

void NiBooleanExtraData::LoadBinary(NiStream& stream)
{
    NiExtraData::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint8_t encoded;
    std::uint32_t width = sizeof(encoded);
    const auto count = binary->_readFn(binary, &encoded, sizeof(encoded), &width, 1);
    binary->_absoluteCurrentPos += count;
    value = encoded != 0;
}

void NiBooleanExtraData::SaveBinary(NiStream& stream)
{
    NiExtraData::SaveBinary(stream);
    std::uint8_t encoded = value;
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(encoded);
    const auto count = binary->_writeFn(binary, &encoded, sizeof(encoded), &width, 1);
    binary->_absoluteCurrentPos += count;
}
