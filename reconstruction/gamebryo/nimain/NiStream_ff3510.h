// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layouts for serializing a multi-bound node's fields.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// NiStream, NiBinaryStream, iStr, oStr, BSMultiBound, BSMultiBoundNode, NiNode, Read, Write, SaveBinary, multiBound, cullingMode, SaveLinkID: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// ReadUInt32, WriteUInt32, position, readFn, writeFn, NiStreamVTable: GUESS(low)
#pragma once

#include <cstdint>

class BSMultiBound;
class NiStream;

class NiBinaryStream
{
public:
    void ReadUInt32(std::uint32_t& output);

    std::uint8_t unknown00[8];
    std::uint32_t position;
    std::uint32_t unknown0C;
    std::uint32_t (*readFn)(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    std::uint32_t (*writeFn)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};

struct NiStreamVTable
{
    std::uint8_t unknown00[0x60];
    void (*SaveLinkID)(NiStream*, const BSMultiBound*);
};

class NiStream
{
public:
    void ReadUInt32(std::uint32_t& output);
    void WriteUInt32(const std::uint32_t& value);

    const NiStreamVTable* vtable;
    std::uint8_t unknown08[0x290];
    NiBinaryStream* iStr;
    NiBinaryStream* oStr;
};

class NiNode
{
public:
    void SaveBinary(NiStream& stream);

protected:
    std::uint8_t unknown00[0x128];
};

class BSMultiBoundNode : public NiNode
{
public:
    void SaveBinary(NiStream& stream);

private:
    BSMultiBound* multiBound;
    std::uint32_t cullingMode;
};
