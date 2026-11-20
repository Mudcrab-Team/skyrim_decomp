// Source exposure: mixed (pinned image listings, project queue units, and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstructions from the listings using the project packed-task layout.
// Adapted bodies: none
// 0x667b50 TaskQueueInterface::Function667b50
// 0x667b90 TaskQueueInterface::Function667b90
// 0x667bd0 TaskQueueInterface::Function667bd0
// 0x667f90 TaskQueueInterface::QueueUpdateDestructibleObject
// 0x668230 TaskQueueInterface::Function668230
// 0x6683f0 TaskQueueInterface::Function6683f0
// 0x6684c0 TaskQueueInterface::Function6684c0
// 0x6685c0 TaskQueueInterface::Function6685c0
// 0x668600 TaskQueueInterface::Function668600
// 0x668640 TaskQueueInterface::Function668640
// 0x668730 TaskQueueInterface::Function668730
// 0x668970 TaskQueueInterface::Function668970
// 0x6689c0 TaskQueueInterface::Function6689c0
// 0x668a00 TaskQueueInterface::Function668a00
// 0x668b90 TaskQueueInterface::Function668b90
// 0x668cc0 TaskQueueInterface::Function668cc0
// 0x668d60 TaskQueueInterface::Function668d60
// 0x668e60 TaskQueueInterface::Function668e60
// 0x668f20 TaskQueueInterface::Function668f20
// 0x668f70 TaskQueueInterface::Function668f70
// 0x669050 TaskQueueInterface::Function669050
// 0x669280 TaskQueueInterface::Function669280
// 0x669410 TaskQueueInterface::Function669410
#include "TaskQueueInterface_667b50.h"
#include <intrin.h>

// PackedTaskData, BSPackedTask, data, integer, real, pointer, byte, boolean: STANDIN GUESS(low)
union PackedTaskData
{
    std::uint32_t integer;
    float real;
    void* pointer;
    std::uint8_t byte;
    bool boolean;
};

struct BSPackedTask
{
    PackedTaskData data[16];
};

// TaskCounter, TaskObject, TaskReference, unknown, refCount: STANDIN GUESS(low)
struct TaskCounter
{
    volatile long refCount;
};

struct TaskObject
{
    std::uint8_t unknown[0x8];
    volatile long refCount;
};

struct TaskReference
{
    std::uint8_t unknown[0x28];
    volatile long refCount;
};

class TESObjectREFR
{
public:
    std::uint8_t unknown[0x28];
    volatile long refCount;
};

// RetainTaskTarget: STANDIN GUESS(low)
template <class T>
static void RetainTaskTarget(T* a_target)
{
    // Retain the target while the queued task owns it.
    _InterlockedIncrement(&a_target->refCount);
}

// x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiPoint3
{
public:
    float x;
    float y;
    float z;
};

// HandleSource, GetTaskHandle, FlaggedTarget, flags, kQueuedBit, PrepareForQueue: STANDIN GUESS(low)
struct HandleSource
{
    const std::uint32_t& GetTaskHandle(std::uint32_t& a_result);
};

struct FlaggedTarget
{
    std::uint8_t unknown[0x7C];
    std::uint32_t flags;
    static constexpr unsigned kQueuedBit = 30;
    void PrepareForQueue();
};

void TaskQueueInterface::Function667b50(const std::uint32_t& a_handle, TaskObject* a_object)
{
    if (!a_object) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 56;
    task.data[1].integer = a_handle;
    task.data[2].pointer = a_object;
    RetainTaskTarget(a_object);
    QueueIfActive(task);
}

void TaskQueueInterface::Function667b90(void* a_target, TaskCounter* a_object)
{
    if (!a_target || !a_object) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 57;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    RetainTaskTarget(a_object);
    QueueIfActive(task);
}

void TaskQueueInterface::Function667bd0(void* a_target, TaskCounter* a_object, std::uint8_t a_argument)
{
    if (!a_target || !a_object) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 58;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    task.data[3].byte = a_argument;
    RetainTaskTarget(a_object);
    QueueIfActive(task);
}

void TaskQueueInterface::QueueUpdateDestructibleObject(TESObjectREFR* a_refr, float a_damage, bool a_arg3, TESObjectREFR* a_cause)
{
    if (!a_refr) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 9;
    task.data[1].pointer = a_refr;
    task.data[2].real = a_damage;
    task.data[3].boolean = a_arg3;
    task.data[4].pointer = a_cause;
    RetainTaskTarget(a_refr);
    if (a_cause) {
        RetainTaskTarget(a_cause);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668230(TaskReference* a_target, std::uint8_t a_value, std::uint8_t a_argument)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 11;
    task.data[1].pointer = a_target;
    task.data[2].byte = a_value;
    task.data[3].byte = a_argument;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function6683f0(TaskObject* a_target, TaskObject* a_object, std::uint32_t a_argument)
{
    if (!a_target) {
        return;
    }

    RetainTaskTarget(a_target);
    if (a_object) {
        RetainTaskTarget(a_object);
    }

    BSPackedTask task;
    task.data[0].integer = 18;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    task.data[3].integer = a_argument;
    QueueIfActive(task);
}

void TaskQueueInterface::Function6684c0(TaskObject* a_target, std::uint32_t a_value, std::uint8_t a_argument)
{
    if (!a_target) {
        return;
    }

    RetainTaskTarget(a_target);

    BSPackedTask task;
    task.data[0].integer = 34;
    task.data[1].pointer = a_target;
    task.data[2].integer = a_value;
    task.data[3].byte = a_argument;
    QueueIfActive(task);
}

void TaskQueueInterface::Function6685c0(TaskObject* a_target, std::uint32_t a_value, std::uint32_t a_argument)
{
    if (!a_target) {
        return;
    }

    RetainTaskTarget(a_target);

    BSPackedTask task;
    task.data[0].integer = 38;
    task.data[1].pointer = a_target;
    task.data[2].integer = a_value;
    task.data[3].integer = a_argument;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668600(TaskObject* a_target, std::uint32_t a_value, std::uint32_t a_argument)
{
    if (!a_target) {
        return;
    }

    RetainTaskTarget(a_target);

    BSPackedTask task;
    task.data[0].integer = 39;
    task.data[1].pointer = a_target;
    task.data[2].integer = a_value;
    task.data[3].integer = a_argument;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668640(TaskObject* a_target, float a_value)
{
    if (!a_target) {
        return;
    }

    RetainTaskTarget(a_target);

    BSPackedTask task;
    task.data[0].integer = 40;
    task.data[1].pointer = a_target;
    task.data[2].real = a_value;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668730(TaskObject* a_target, std::uint8_t a_value, std::uint8_t a_argument, std::uint8_t a_extra)
{
    BSPackedTask task;
    task.data[0].integer = 60;
    task.data[1].pointer = a_target;
    task.data[2].byte = a_value;
    task.data[3].byte = a_argument;
    task.data[4].byte = a_extra;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function668970(TaskReference* a_target, void* a_object, std::uint8_t a_argument, std::uint8_t a_extra)
{
    BSPackedTask task;
    task.data[0].integer = 21;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    task.data[3].byte = a_argument;
    task.data[4].byte = a_extra;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function6689c0(TaskReference* a_target, void* a_object, std::uint8_t a_argument)
{
    BSPackedTask task;
    task.data[0].integer = 22;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    task.data[3].byte = a_argument;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668a00(TaskReference* a_target, void* a_object, std::uint8_t a_argument, std::uint8_t a_extra)
{
    if (!a_target || !a_object) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 23;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    task.data[3].byte = a_argument;
    task.data[4].byte = a_extra;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function668b90(TaskReference* a_target, std::uint8_t a_value, std::uint8_t a_argument)
{
    BSPackedTask task;
    task.data[0].integer = 29;
    task.data[1].pointer = a_target;
    task.data[2].byte = a_value;
    task.data[3].byte = a_argument;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668cc0(float a_scale, const NiPoint3& a_position)
{
    BSPackedTask task;
    task.data[0].integer = 44;
    task.data[1].real = a_scale;
    task.data[2].real = a_position.x;
    task.data[3].real = a_position.y;
    task.data[4].real = a_position.z;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668d60(TaskReference* a_target, std::uint8_t a_value, std::uint8_t a_argument)
{
    BSPackedTask task;
    task.data[0].integer = 46;
    task.data[1].pointer = a_target;
    task.data[2].byte = a_value;
    task.data[3].byte = a_argument;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668e60(TaskReference* a_target, TaskObject* a_object)
{
    if (!a_target) {
        return;
    }

    RetainTaskTarget(a_target);
    if (a_object) {
        RetainTaskTarget(a_object);
    }

    BSPackedTask task;
    task.data[0].integer = 53;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668f20(HandleSource* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 43;
    std::uint32_t handle;
    task.data[1].integer = a_target->GetTaskHandle(handle);
    QueueIfActive(task);
}

void TaskQueueInterface::Function668f70(FlaggedTarget* a_target)
{
    if (!a_target || (static_cast<std::uint8_t>(a_target->flags >> FlaggedTarget::kQueuedBit) & 1)) {
        return;
    }

    a_target->flags |= 1u << FlaggedTarget::kQueuedBit;
    BSPackedTask task;
    task.data[0].integer = 55;
    task.data[1].pointer = a_target;
    a_target->PrepareForQueue();
    QueueIfActive(task);
}

void TaskQueueInterface::Function669050(TaskReference* a_target, std::uint32_t a_value, std::uint8_t a_argument, std::uint8_t a_extra)
{
    BSPackedTask task;
    task.data[0].integer = 61;
    task.data[1].pointer = a_target;
    task.data[2].integer = a_value;
    task.data[3].byte = a_argument;
    task.data[4].byte = a_extra;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function669280(TaskReference* a_target, TaskObject* a_object)
{
    BSPackedTask task;
    task.data[0].integer = 72;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    if (a_object) {
        RetainTaskTarget(a_object);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function669410(TaskReference* a_target, void* a_object, void* a_argument)
{
    BSPackedTask task;
    task.data[0].integer = 84;
    task.data[1].pointer = a_target;
    task.data[2].pointer = a_object;
    task.data[3].pointer = a_argument;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}
