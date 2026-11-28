// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing.
// ScaleformContext117dc80, ScaleformTarget117dc80, CriticalSection117dc80, ScopedLock117dc80, SetTargetField, lock, target, field748, unk00, unkC0: GUESS(low) STANDIN; community list calls 0x117dc80 BSScaleformImageLoader::sub_140F47EC0, which does not fit the PDB 0x48-byte layout
#pragma once

#include <cstdint>

struct CriticalSection117dc80
{
    std::uint8_t unk00[0x28];  // 00
};
static_assert(sizeof(CriticalSection117dc80) == 0x28, "CriticalSection117dc80 size");

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(CriticalSection117dc80* section);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CriticalSection117dc80* section);

struct ScopedLock117dc80
{
    CriticalSection117dc80* section;

    explicit ScopedLock117dc80(CriticalSection117dc80& lock) : section(&lock)
    {
        EnterCriticalSection(section);
    }

    ~ScopedLock117dc80()
    {
        LeaveCriticalSection(section);
    }
};

struct ScaleformTarget117dc80
{
    std::uint8_t unk00[0x748];  // 000
    void*        field748;      // 748
};

class ScaleformContext117dc80
{
public:
    void SetTargetField(void* value);

    std::uint8_t            unk00[0x98];  // 00
    CriticalSection117dc80  lock;         // 98
    std::uint8_t            unkC0[0x8];   // C0
    ScaleformTarget117dc80* target;       // C8
};
static_assert(sizeof(ScaleformContext117dc80) == 0xD0, "ScaleformContext117dc80 size");
