// Source exposure: binary-analysis (pinned-image observations and image RTTI).
// Code origin: original polymorphic reconstruction with provisional method signatures.
// SPDX-License-Identifier: CC0-1.0
// BSThread: STANDIN EXE_RTTI
// BSThread::~BSThread, BSThread::Unk_01, BSThread::Unk_02, BSThread::Functionce4190, BSThread::criticalSection, BSThread::thread, BSThread::threadID, BSThread::running: GUESS(low)
#pragma once
#include <cstdint>
#include <cstddef>
#include <intrin.h>
#include <Windows.h>

class BSThread
{
public:
    virtual ~BSThread();
    virtual void Unk_01();
    virtual void Unk_02();
    void Functionce4190();
    CRITICAL_SECTION criticalSection;
    HANDLE thread;
    std::uint8_t unknown38[8];
    DWORD threadID;
    std::uint8_t unknown44[4];
    std::uint8_t running;
    std::uint8_t unknown49[7];
};
static_assert(offsetof(BSThread, criticalSection) == 8, "member position");
static_assert(offsetof(BSThread, thread) == 48, "member position");
static_assert(offsetof(BSThread, threadID) == 64, "member position");
static_assert(offsetof(BSThread, running) == 72, "member position");
static_assert(sizeof(BSThread) == 80, "observed class size");
