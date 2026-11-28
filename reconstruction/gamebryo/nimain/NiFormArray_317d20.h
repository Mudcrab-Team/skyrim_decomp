// Source exposure: mixed (pinned image and cited public names).
// Code origin: original reconstruction using cited names and stand-in layouts.
// NiFormArray: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFreeStorage, data, unk10, unk18: GUESS(low) STANDIN
#pragma once

#include <cstdint>

void NiFreeStorage(void* ptr);

class NiFormArray
{
public:
    NiFormArray();
    virtual ~NiFormArray();

    void*         data;   // 08
    std::uint64_t unk10;  // 10
    std::uint64_t unk18;  // 18
};
static_assert(sizeof(NiFormArray) == 0x20, "NiFormArray size");
