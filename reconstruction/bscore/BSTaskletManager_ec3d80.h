// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTaskletManager::canCreateTaskGroup, BSTaskletManager::started, BSTaskletManager::instanceSemaphore, BSTaskletManager::instanceCount: CRASHLOGGER_PDB(59818@2026.10.24)
// CloseHandle, BSTaskletManager::unk0A, BSTaskletManager::unk1C: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* a_handle);

class BSTaskletManager
{
public:
    BSTaskletManager();
    virtual ~BSTaskletManager();

    bool canCreateTaskGroup;
    bool started;
    std::uint8_t unk0A[6];
    void* instanceSemaphore;
    long instanceCount;
    std::uint32_t unk1C;
};
static_assert(offsetof(BSTaskletManager, instanceSemaphore) == 0x10, "instanceSemaphore offset");
static_assert(sizeof(BSTaskletManager) == 0x20, "BSTaskletManager size");
