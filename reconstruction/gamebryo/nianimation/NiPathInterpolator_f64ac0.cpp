// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf64ac0 NiPathInterpolator::RegisterStreamables
// 0xf66e60 NiPathInterpolator::ReadBinaryUInt32
// 0xf66f10 NiPathInterpolator::ReadPathUInt16
// 0xf66f50 NiPathInterpolator::ReadPathUInt32
// 0xf66fa0 NiPathInterpolator::WritePathUInt16
// 0xf66fe0 NiPathInterpolator::WritePathUInt32
// Adapted bodies: none
#include "NiPathInterpolator_f64ac0.h"

bool NiPathInterpolator::RegisterStreamables(NiStream& stream)
{
    const bool registered = NiKeyBasedInterpolator::RegisterStreamables(stream);
    if (!registered) {
        return registered;
    }
    if (pathData) {
        pathData->RegisterStreamables(stream);
    }
    if (percentData) {
        percentData->RegisterStreamables(stream);
    }
    return true;
}

void NiPathInterpolator::ReadBinaryUInt32(NiBinaryStream& binary, std::uint32_t& value)
{
    std::uint32_t width = sizeof(std::uint32_t);
    std::uint32_t temporary;
    const auto transferred = binary._readFn(&binary, &temporary, sizeof(temporary), &width, 1);
    binary._absoluteCurrentPos += transferred;
    value = temporary;
}

void NiPathInterpolator::ReadPathUInt16(NiStream& stream, std::uint16_t& value)
{
    auto& binary = *stream.iStr;
    std::uint32_t width = sizeof(std::uint16_t);
    const auto transferred = binary._readFn(&binary, &value, sizeof(value), &width, 1);
    binary._absoluteCurrentPos += transferred;
}

void NiPathInterpolator::ReadPathUInt32(NiStream& stream, std::uint32_t& value)
{
    auto& binary = *stream.iStr;
    std::uint32_t width = sizeof(std::uint32_t);
    std::uint32_t temporary;
    const auto transferred = binary._readFn(&binary, &temporary, sizeof(temporary), &width, 1);
    binary._absoluteCurrentPos += transferred;
    value = temporary;
}

void NiPathInterpolator::WritePathUInt16(NiStream& stream, const std::uint16_t& value)
{
    auto& binary = *stream.oStr;
    std::uint32_t width = sizeof(std::uint16_t);
    const auto transferred = binary._writeFn(&binary, &value, sizeof(value), &width, 1);
    binary._absoluteCurrentPos += transferred;
}

void NiPathInterpolator::WritePathUInt32(NiStream& stream, const std::uint32_t& value)
{
    auto& binary = *stream.oStr;
    std::uint32_t width = sizeof(std::uint32_t);
    const auto transferred = binary._writeFn(&binary, &value, sizeof(value), &width, 1);
    binary._absoluteCurrentPos += transferred;
}
