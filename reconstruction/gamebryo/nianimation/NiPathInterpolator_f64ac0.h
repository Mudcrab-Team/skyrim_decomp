// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPathInterpolator: EXE_RTTI
// unknown18, pathData, percentData, ReadBinaryUInt32, ReadPathUInt16, ReadPathUInt32, WritePathUInt16, WritePathUInt32: GUESS(low)
#pragma once

#include "NiKeyBasedInterpolator_f6e600.h"

class NiPathInterpolator : public NiKeyBasedInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    static void ReadBinaryUInt32(NiBinaryStream& binary, std::uint32_t& value);
    static void ReadPathUInt16(NiStream& stream, std::uint16_t& value);
    static void ReadPathUInt32(NiStream& stream, std::uint32_t& value);
    static void WritePathUInt16(NiStream& stream, const std::uint16_t& value);
    static void WritePathUInt32(NiStream& stream, const std::uint32_t& value);

private:
    std::uint8_t unknown18[0x10];
    NiObject* pathData;
    NiObject* percentData;
};
