// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// NiFormArray, sub_1402BD1D0: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFormArrayPair, NiSecondaryArray, NiFreeStorage, data, unk10, unk18, primary, secondary: GUESS(low) STANDIN
#pragma once

#include <cstdint>

void NiFreeStorage(void* ptr);

class NiFormArray
{
public:
    virtual ~NiFormArray()
    {
        NiFreeStorage(data);
    }

    void*         data;   // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
};
static_assert(sizeof(NiFormArray) == 0x20, "NiFormArray size");

class NiSecondaryArray
{
public:
    virtual ~NiSecondaryArray()
    {
        NiFreeStorage(data);
    }

    void*         data;   // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
};
static_assert(sizeof(NiSecondaryArray) == 0x20, "NiSecondaryArray size");

struct NiFormArrayPair
{
    ~NiFormArrayPair();

    NiFormArray      primary;    // 00
    NiSecondaryArray secondary;  // 20
};
static_assert(sizeof(NiFormArrayPair) == 0x40, "NiFormArrayPair size");
