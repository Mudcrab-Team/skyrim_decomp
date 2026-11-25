// Source exposure: binary-analysis (names are guesses; layout read from the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// NiStream, NiStream::Functionee43b0, NiStream::binaryStream, NiStream::loadFlag, NiStream::Notify, g_pendingCount, g_semaphore, SignalSemaphore: GUESS(low)
#pragma once

#include <cstdint>
#include <intrin.h>

extern volatile long g_pendingCount;
extern void* g_semaphore;
// Win32 ReleaseSemaphore, imported by the image; declared here to avoid the platform header.
extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* handle, long releaseCount, long* previousCount);

class NiStream
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual bool ReadHeader(void* header);
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void Notify();
    virtual void unk08();
    virtual void unk09();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual bool Load2();

    int Functionee43b0();

    std::uint8_t pad08[0x100];  // 0x08
    std::uint8_t header[0x190];  // 0x108
    void* binaryStream;  // 0x298
    std::uint8_t pad2a0[0x3c];  // 0x2a0
    std::uint8_t loadFlag;  // 0x2dc
};
