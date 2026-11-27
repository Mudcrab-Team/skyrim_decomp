// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTaskletManager: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTaskletManager::canCreateTaskGroup, BSTaskletManager::AttachTask: CRASHLOGGER_PDB(59818@2026.10.24)
// TaskHandle, TaskHandle::ptr, GroupHandle, GroupHandle::unk00, GroupHandle::data, BSTaskletManager::Unk_00, BSTaskletManager::Unk_01, BSTaskletManager::Unk_02, BSTaskletManager::Unk_03, BSTaskletManager::Unk_04, BSTaskletManager::Unk_05, BSTaskletManager::DoAttachTask: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct TaskHandle
{
    void* ptr;
};

struct GroupHandle
{
    std::uint64_t unk00;
    void* data;
};
static_assert(offsetof(GroupHandle, data) == 0x08, "data offset");

class BSTaskletManager
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual bool DoAttachTask(void* a_task, void* a_group);

    bool AttachTask(const TaskHandle& a_task, const GroupHandle& a_group);

    bool canCreateTaskGroup;
};
static_assert(offsetof(BSTaskletManager, canCreateTaskGroup) == 0x08, "canCreateTaskGroup offset");
