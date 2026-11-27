// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: WriteValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// NiStringPalette, NiStringPalette::SaveBinary_140CF3320: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryStream, NiStream, NiObject, NiObject::SaveBinary, vtable, position, unk0C, read, write, unk00, input, output, palette, allocatedSize, lastByte: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class NiBinaryStream
{
public:
    void* vtable;
    std::uint32_t position;
    std::uint32_t unk0C;
    std::uint32_t (*read)(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    std::uint32_t (*write)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};

class NiStream
{
public:
    std::uint8_t unk00[0x298];
    NiBinaryStream* input;
    NiBinaryStream* output;
};

class NiObject
{
public:
    void SaveBinary(NiStream& a_stream);

    std::uint8_t unk00[0x10];
};

class NiStringPalette : public NiObject
{
public:
    void SaveBinary_140CF3320(NiStream& a_stream);

    char* palette;
    std::uint32_t allocatedSize;
    std::uint32_t lastByte;
};

static_assert(offsetof(NiStream, output) == 0x2A0, "output offset");
static_assert(offsetof(NiStringPalette, palette) == 0x10, "palette offset");
static_assert(offsetof(NiStringPalette, lastByte) == 0x1C, "lastByte offset");
