// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTaskletManager::canCreateTaskGroup, BSTaskletManager::started, BSTaskletManager::instanceSemaphore, BSTaskletManager::instanceCount, BSTaskletManager::SignalInstanceAvailable: CRASHLOGGER_PDB(59818@2026.10.24)
// ReleaseSemaphore, BSTaskletManager::Unk_00, BSTaskletManager::Unk_01, BSTaskletManager::Unk_02, BSTaskletManager::Unk_03, BSTaskletManager::Unk_04, BSTaskletManager::Unk_05, BSTaskletManager::Unk_06, BSTaskletManager::Unk_07, BSTaskletManager::Unk_08, BSTaskletManager::Unk_09, BSTaskletManager::unk0A, BSTaskletManager::unk1C: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall ReleaseSemaphore(void* a_semaphore, long a_releaseCount, long* a_previousCount);

class BSTaskletManager
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();

    void SignalInstanceAvailable();

    bool canCreateTaskGroup;
    bool started;
    std::uint8_t unk0A[6];
    void* instanceSemaphore;
    long instanceCount;
    std::uint32_t unk1C;
};
static_assert(offsetof(BSTaskletManager, started) == 0x09, "started offset");
static_assert(offsetof(BSTaskletManager, instanceSemaphore) == 0x10, "instanceSemaphore offset");
static_assert(offsetof(BSTaskletManager, instanceCount) == 0x18, "instanceCount offset");
static_assert(sizeof(BSTaskletManager) == 0x20, "BSTaskletManager size");
