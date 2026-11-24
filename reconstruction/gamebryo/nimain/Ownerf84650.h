// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layouts for serializing a multi-bound node's fields. Stamped as a twin of matched 0xff35e0 (gamebryo/nimain/NiStream_ff3510): source copied, names replaced by placeholders.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// NiBinaryStream: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiStreamVTable: GUESS(low)
// Functionf84650, Ownerf84650: GUESS(low) STANDIN
// iStr, oStr, ReadUInt32: GUESS(low) STANDIN
#pragma once
#include "NiStream_ff3510.h"

class Ownerf84650
{
public:
    void ReadUInt32(std::uint32_t& output);
    void Functionf84650(const std::uint32_t& value);

    const NiStreamVTable* vtable;
    std::uint8_t unknown08[0x290];
    NiBinaryStream* iStr;
    NiBinaryStream* oStr;
};

