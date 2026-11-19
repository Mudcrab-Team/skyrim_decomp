// Source exposure: mixed (pinned image listings and existing project task queue units).
// Code origin: original methods from the pinned image; task layout follows the existing TaskQueueInterface units.
// Adapted bodies: none
// 0x667b10 TaskQueueInterface::Function667b10
// 0x667c20 TaskQueueInterface::Function667c20
// 0x667f10 TaskQueueInterface::Function667f10
// 0x667f50 TaskQueueInterface::Function667f50
// 0x667ff0 TaskQueueInterface::Function667ff0
// 0x668140 TaskQueueInterface::Function668140
// 0x668170 TaskQueueInterface::Function668170
// 0x668310 TaskQueueInterface::Function668310
// 0x668350 TaskQueueInterface::Function668350
// 0x668380 TaskQueueInterface::Function668380
// 0x6683b0 TaskQueueInterface::Function6683b0
// 0x668440 TaskQueueInterface::Function668440
// 0x668480 TaskQueueInterface::Function668480
// 0x668500 TaskQueueInterface::Function668500
// 0x668540 TaskQueueInterface::Function668540
// 0x668580 TaskQueueInterface::Function668580
// 0x668680 TaskQueueInterface::Function668680
// 0x668780 TaskQueueInterface::Function668780
// 0x6688b0 TaskQueueInterface::Function6688b0
// 0x6688f0 TaskQueueInterface::Function6688f0
// 0x668930 TaskQueueInterface::Function668930
// 0x668a50 TaskQueueInterface::Function668a50
// 0x668a90 TaskQueueInterface::Function668a90
// 0x668ad0 TaskQueueInterface::Function668ad0
// 0x668b10 TaskQueueInterface::Function668b10
// 0x668b50 TaskQueueInterface::Function668b50
// 0x668c40 TaskQueueInterface::Function668c40
// 0x668c80 TaskQueueInterface::Function668c80
// 0x668da0 TaskQueueInterface::Function668da0
// 0x668de0 TaskQueueInterface::Function668de0
// 0x668e20 TaskQueueInterface::Function668e20
// 0x669010 TaskQueueInterface::Function669010
// 0x6691b0 TaskQueueInterface::Function6691b0
// 0x6691f0 TaskQueueInterface::Function6691f0
// 0x669220 TaskQueueInterface::Function669220
// 0x669250 TaskQueueInterface::Function669250
// 0x6692d0 TaskQueueInterface::Function6692d0
// 0x669310 TaskQueueInterface::Function669310
// 0x669340 TaskQueueInterface::Function669340
// 0x669370 TaskQueueInterface::Function669370
// 0x6693a0 TaskQueueInterface::Function6693a0
// 0x6693d0 TaskQueueInterface::Function6693d0
// 0x669450 TaskQueueInterface::Function669450
// 0x669480 TaskQueueInterface::Function669480
// 0x669550 TaskQueueInterface::Function669550
// 0x669590 TaskQueueInterface::Function669590
#include "TaskQueueInterface_667b10.h"
#include <intrin.h>

// PackedTaskData, BSPackedTask, data, integer, pointer, byte, real: STANDIN GUESS(low)
union PackedTaskData
{
    std::uint32_t integer;
    void* pointer;
    std::uint8_t byte;
    float real;
};

struct BSPackedTask
{
    PackedTaskData data[16];
};

// TaskObject, TaskReference, unknown, refCount: STANDIN GUESS(low)
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

// RetainTaskTarget: STANDIN GUESS(low)
template <class T>
static void RetainTaskTarget(T* a_target)
{
    // Retain the target while the queued task owns it.
    _InterlockedIncrement(&a_target->refCount);
}

void TaskQueueInterface::Function667b10(TaskObject* a_target)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 62;
    task.data[1].pointer = a_target;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function667c20(TaskObject* a_target, std::uint32_t a_value)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 6;
    task.data[1].pointer = a_target;
    task.data[2].integer = a_value;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function667f10(void* a_target)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[1].pointer = a_target;
    task.data[0].integer = 17;
    QueueIfActive(task);
}

void TaskQueueInterface::Function667f50(void* a_target)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[1].pointer = a_target;
    task.data[0].integer = 66;
    QueueIfActive(task);
}

void TaskQueueInterface::Function667ff0(TaskReference* a_target, std::uint8_t a_value)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 59;
    task.data[1].pointer = a_target;
    task.data[2].byte = a_value;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function668140()
{
    BSPackedTask task;
    task.data[0].integer = 81;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668170(TaskReference* a_target)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 82;
    task.data[1].pointer = a_target;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function668310(TaskReference* a_target)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 14;
    task.data[1].pointer = a_target;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function668350(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 85;
    task.data[1].pointer = a_target;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function668380(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 15;
    task.data[1].pointer = a_target;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function6683b0(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 54;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668440(TaskObject* a_target)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    RetainTaskTarget(a_target);
    task.data[1].pointer = a_target;
    task.data[0].integer = 20;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668480(TaskObject* a_target)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    RetainTaskTarget(a_target);
    task.data[1].pointer = a_target;
    task.data[0].integer = 19;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668500(TaskObject* a_target, std::uint32_t a_value)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    RetainTaskTarget(a_target);
    task.data[1].pointer = a_target;
    task.data[0].integer = 35;
    task.data[2].integer = a_value;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668540(TaskObject* a_target, std::uint32_t a_value)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    RetainTaskTarget(a_target);
    task.data[1].pointer = a_target;
    task.data[0].integer = 36;
    task.data[2].integer = a_value;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668580(TaskObject* a_target, std::uint32_t a_value)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    RetainTaskTarget(a_target);
    task.data[1].pointer = a_target;
    task.data[0].integer = 37;
    task.data[2].integer = a_value;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668680(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 49;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668780(TaskReference* a_target, std::uint8_t a_value)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    task.data[0].integer = 76;
    task.data[1].pointer = a_target;
    task.data[2].byte = a_value;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function6688b0(TaskReference* a_target, std::uint8_t a_value)
{
    BSPackedTask task;
    task.data[0].integer = 74;
    task.data[1].pointer = a_target;
    task.data[2].byte = a_value;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function6688f0(TaskObject* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 96;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668930(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 70;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668a50(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 24;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668a90(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 25;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668ad0(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 26;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668b10(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 27;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668b50(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 28;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668c40(const std::uint32_t& a_handle, float a_value)
{
    BSPackedTask task;
    task.data[2].real = a_value;
    task.data[0].integer = 33;
    task.data[1].integer = a_handle;
    QueueIfActive(task);
}

void TaskQueueInterface::Function668c80(TaskReference* a_target, std::uint8_t a_value)
{
    BSPackedTask task;
    task.data[0].integer = 41;
    task.data[1].pointer = a_target;
    task.data[2].byte = a_value;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668da0(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 47;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668de0(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 48;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function668e20(TaskReference* a_target)
{
    if (!a_target) {
        return;
    }

    BSPackedTask task;
    RetainTaskTarget(a_target);
    task.data[1].pointer = a_target;
    task.data[0].integer = 52;
    QueueIfActive(task);
}

void TaskQueueInterface::Function669010(const std::uint32_t& a_handle, void* a_object)
{
    BSPackedTask task;
    task.data[0].integer = 94;
    task.data[1].integer = a_handle;
    task.data[2].pointer = a_object;
    QueueIfActive(task);
}

void TaskQueueInterface::Function6691b0(TaskReference* a_target, std::uint32_t a_value)
{
    BSPackedTask task;
    task.data[0].integer = 67;
    task.data[1].pointer = a_target;
    task.data[2].integer = a_value;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function6691f0(std::uint32_t a_argument, std::uint8_t a_value)
{
    BSPackedTask task;
    task.data[1].integer = a_argument;
    task.data[0].integer = 68;
    task.data[2].byte = a_value;
    QueueIfActive(task);
}

void TaskQueueInterface::Function669220(std::uint8_t a_argument)
{
    BSPackedTask task;
    task.data[1].byte = a_argument;
    task.data[0].integer = 69;
    QueueIfActive(task);
}

void TaskQueueInterface::Function669250(std::uint32_t a_argument, std::uint32_t a_value)
{
    BSPackedTask task;
    task.data[1].integer = a_argument;
    task.data[0].integer = 71;
    task.data[2].integer = a_value;
    QueueIfActive(task);
}

void TaskQueueInterface::Function6692d0(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 73;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function669310(std::uint8_t a_argument)
{
    BSPackedTask task;
    task.data[1].byte = a_argument;
    task.data[0].integer = 75;
    QueueIfActive(task);
}

void TaskQueueInterface::Function669340(TaskObject* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 78;
    task.data[1].pointer = a_target;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function669370(TaskObject* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 79;
    task.data[1].pointer = a_target;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function6693a0(TaskObject* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 86;
    task.data[1].pointer = a_target;
    RetainTaskTarget(a_target);
    QueueIfActive(task);
}

void TaskQueueInterface::Function6693d0(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 80;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function669450(std::uint32_t a_argument)
{
    BSPackedTask task;
    task.data[1].integer = a_argument;
    task.data[0].integer = 87;
    QueueIfActive(task);
}

void TaskQueueInterface::Function669480(void* a_target, std::uint8_t a_value)
{
    BSPackedTask task;
    task.data[1].pointer = a_target;
    task.data[0].integer = 88;
    task.data[2].byte = a_value;
    QueueIfActive(task);
}

void TaskQueueInterface::Function669550(TaskReference* a_target)
{
    BSPackedTask task;
    task.data[0].integer = 89;
    task.data[1].pointer = a_target;
    if (a_target) {
        RetainTaskTarget(a_target);
    }
    QueueIfActive(task);
}

void TaskQueueInterface::Function669590(const std::uint32_t& a_handle, std::uint8_t a_value)
{
    BSPackedTask task;
    task.data[0].integer = 90;
    task.data[1].integer = a_handle;
    task.data[2].byte = a_value;
    QueueIfActive(task);
}
