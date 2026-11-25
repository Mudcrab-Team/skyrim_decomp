// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf66fa0 (gamebryo/nianimation/NiPathInterpolator_f64ac0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionee8870, Owneree8870: GUESS(low) STANDIN
// unknown18, pathData, percentData, ReadBinaryUInt32, ReadPathUInt16, ReadPathUInt32, WritePathUInt32: GUESS(low) STANDIN
#pragma once
#include "NiPathInterpolator_f64ac0.h"

class Owneree8870 : public NiKeyBasedInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    static void ReadBinaryUInt32(NiBinaryStream& binary, std::uint32_t& value);
    static void ReadPathUInt16(NiStream& stream, std::uint16_t& value);
    static void ReadPathUInt32(NiStream& stream, std::uint32_t& value);
    static void Functionee8870(NiStream& stream, const std::uint16_t& value);
    static void WritePathUInt32(NiStream& stream, const std::uint32_t& value);

private:
    std::uint8_t unknown18[0x10];
    NiObject* pathData;
    NiObject* percentData;
};

