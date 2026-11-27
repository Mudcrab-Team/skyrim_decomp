// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: WriteValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:197
// 0xf88460 NiStringPalette::SaveBinary_140CF3320
#include "NiStringPalette_f88460.h"

// WriteValue: GUESS
template <class T>
static void WriteValue(NiBinaryStream* a_binary, const T& a_value)
{
    std::uint32_t componentSize = sizeof(T);
    a_binary->position += a_binary->write(a_binary, &a_value, sizeof(T), &componentSize, 1);
}

// WriteBytes: GUESS
static void WriteBytes(NiBinaryStream* a_binary, const char* a_buffer, std::uint32_t a_count)
{
    std::uint32_t componentSize = 1;
    a_binary->position += a_binary->write(a_binary, a_buffer, a_count, &componentSize, 1);
}

// Saves the string palette buffer and length metadata to a stream.
void NiStringPalette::SaveBinary_140CF3320(NiStream& a_stream)
{
    NiObject::SaveBinary(a_stream);
    std::uint32_t length = lastByte;
    WriteValue(a_stream.output, length);
    if (length > 0)
    {
        WriteBytes(a_stream.output, palette, length);
    }
    WriteValue(a_stream.output, lastByte);
}
