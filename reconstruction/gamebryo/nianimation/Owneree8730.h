// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original reconstruction from the pinned animation code. Stamped as a twin of matched 0xf66f10 (gamebryo/nianimation/NiPathInterpolator_f64ac0): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Functionee8730, Owneree8730: GUESS(low) STANDIN
// unknown18, pathData, percentData, ReadBinaryUInt32, ReadPathUInt32, WritePathUInt16, WritePathUInt32: GUESS(low) STANDIN
#pragma once
#include "NiPathInterpolator_f64ac0.h"

class Owneree8730 : public NiKeyBasedInterpolator
{
public:
    bool RegisterStreamables(NiStream& stream) override;
    static void ReadBinaryUInt32(NiBinaryStream& binary, std::uint32_t& value);
    static void Functionee8730(NiStream& stream, std::uint16_t& value);
    static void ReadPathUInt32(NiStream& stream, std::uint32_t& value);
    static void WritePathUInt16(NiStream& stream, const std::uint16_t& value);
    static void WritePathUInt32(NiStream& stream, const std::uint32_t& value);

private:
    std::uint8_t unknown18[0x10];
    NiObject* pathData;
    NiObject* percentData;
};

