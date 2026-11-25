// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction; body written from the listing.; Written for this reconstruction from the listing; the lock state layout and imports are local stand-ins.; Written for this reconstruction from the listing; member names are local guesses.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xaa2c40 hkReferencedObject::CalcContentStatistics
// hkReferencedObject::CalcContentStatistics: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// g_specialClass, StatBuf, GetStatFlag, CollectStat: GUESS(low)
// Adapted bodies: none
// 0xaa2b50 hkReferencedObject::Functionaa2b50
// Drafted by v-macrev, assisted by claude-sonnet-5-5.
// 0xaa2ab0 hkReferencedObject::Functionaa2ab0
// 0xaa2870 hkReferencedObject::Functionaa2870
// 0xaa2890 hkReferencedObject::Functionaa2890
#include "hkReferencedObject.h"

// CRITICAL_SECTION, LockState, g_lockState, g_lockTlsIndex, TlsSetValue, LeaveCriticalSection: GUESS(low); local stand-ins for the Win32 lock types
struct CRITICAL_SECTION
{
    void* debugInfo;
    long lockCount;
    long recursionCount;
    void* owningThread;
    void* lockSemaphore;
    std::uintptr_t spinCount;
};
static_assert(sizeof(CRITICAL_SECTION) == 0x28, "CRITICAL_SECTION size");

struct LockState
{
    std::uint8_t unknown00[0x10];
    std::uint32_t value;
    std::int32_t count;
    std::uint8_t unknown18[0x10];
    CRITICAL_SECTION section;
};

extern LockState* g_lockState;
extern std::uint32_t g_lockTlsIndex;

extern "C" __declspec(dllimport) int __stdcall TlsSetValue(unsigned long a_index, void* a_value);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(CRITICAL_SECTION* a_section);

void hkReferencedObject::CalcContentStatistics(hkStatisticsCollector* a_collector, const hkClass* a_class) const
{
    if (!a_class) {
        return;
    }
    if (a_class == &g_specialClass) {
        return;
    }
    StatBuf buf;
    if (*GetStatFlag(&buf, a_class)) {
        CollectStat(this, a_class, a_collector);
    }
}

void hkReferencedObject::Functionaa2b50()
{
    LockState* state = g_lockState;
    if (--state->count <= 0) {
        TlsSetValue(g_lockTlsIndex, nullptr);
        LeaveCriticalSection(&state->section);
    }
}

void hkReferencedObject::Functionaa2ab0(std::uint32_t a_value)
{
    g_lockState->value = a_value;
}

void hkReferencedObject::Functionaa2870()
{
    if (memSizeAndFlags) {
        ++referenceCount;
    }
}

void hkReferencedObject::Functionaa2890()
{
    if (memSizeAndFlags) {
        if (--referenceCount == 0) {
            delete this;
        }
    }
}
