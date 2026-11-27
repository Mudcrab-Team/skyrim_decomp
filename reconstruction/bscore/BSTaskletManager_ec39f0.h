// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTaskletManager::canCreateTaskGroup, BSTaskletManager::CreateTaskGroup: CRASHLOGGER_PDB(59818@2026.10.24)
// BSTaskletManager::Unk_00, BSTaskletManager::Unk_01, BSTaskletManager::Unk_02, BSTaskletManager::Unk_03, BSTaskletManager::DoCreateTaskGroup: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class BSTaskletManager
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual bool DoCreateTaskGroup(void** a_outGroup);

    bool CreateTaskGroup(void** a_outGroup);

    bool canCreateTaskGroup;
};
static_assert(offsetof(BSTaskletManager, canCreateTaskGroup) == 0x08, "canCreateTaskGroup offset");
