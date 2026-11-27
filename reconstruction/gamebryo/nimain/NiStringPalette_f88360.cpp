// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: written from the listing and community PDB names; see Adapted bodies.
// Adapted bodies: ReadValue, treated as adapted: the origin check reports similarity to the sibling bodies cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/staging/blk_00a80000_o2.cpp:3546
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a80000_o2.cpp:3512
// 0xf88360 NiStringPalette::LoadBinary_140CF3220
#include "NiStringPalette_f88360.h"

// ReadValue: GUESS
template <class T>
static void ReadValue(NiBinaryStream* a_binary, T& a_value)
{
    std::uint32_t componentSize = sizeof(T);
    a_binary->position += a_binary->read(a_binary, &a_value, sizeof(T), &componentSize, 1);
}

// ReadBytes: GUESS
static void ReadBytes(NiBinaryStream* a_binary, char* a_buffer, std::uint32_t a_count)
{
    std::uint32_t componentSize = 1;
    a_binary->position += a_binary->read(a_binary, a_buffer, a_count, &componentSize, 1);
}

// Loads the string palette buffer and length metadata from a stream.
void NiStringPalette::LoadBinary_140CF3220(NiStream& a_stream)
{
    NiObject::LoadBinary(a_stream);
    ReadValue(a_stream.input, allocatedSize);
    if (allocatedSize > 0)
    {
        palette = NiAlloc(allocatedSize);
        ReadBytes(a_stream.input, palette, allocatedSize);
    }
    ReadValue(a_stream.input, lastByte);
}
