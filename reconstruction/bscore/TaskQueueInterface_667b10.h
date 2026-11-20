// Source exposure: mixed (pinned image listings and existing project task queue units).
// Code origin: stand-in declarations from the observed argument accesses and the project packed-task layout.
// Function667b10, Function667c20, Function667f10, Function667f50, Function667ff0: GUESS(low)
// Function668140, Function668170, Function668310, Function668350, Function668380: GUESS(low)
// Function6683b0, Function668440, Function668480, Function668500, Function668540: GUESS(low)
// Function668580, Function668680, Function668780, Function6688b0, Function6688f0: GUESS(low)
// Function668930, Function668a50, Function668a90, Function668ad0, Function668b10: GUESS(low)
// Function668b50, Function668c40, Function668c80, Function668da0, Function668de0: GUESS(low)
// Function668e20, Function669010, Function6691b0, Function6691f0, Function669220: GUESS(low)
// Function669250, Function6692d0, Function669310, Function669340, Function669370: GUESS(low)
// Function6693a0, Function6693d0, Function669450, Function669480, Function669550: GUESS(low)
// Function669590: GUESS(low)
// TaskQueueInterface, QueueIfActive, BSPackedTask: STANDIN GUESS(low)
// TaskObject, TaskReference: STANDIN GUESS(low)
#pragma once

#include <cstdint>

struct BSPackedTask;
struct TaskObject;
struct TaskReference;

class TaskQueueInterface
{
public:
    void QueueIfActive(BSPackedTask& a_task);
    void Function667b10(TaskObject* a_target);
    void Function667c20(TaskObject* a_target, std::uint32_t a_value);
    void Function667f10(void* a_target);
    void Function667f50(void* a_target);
    void Function667ff0(TaskReference* a_target, std::uint8_t a_value);
    void Function668140();
    void Function668170(TaskReference* a_target);
    void Function668310(TaskReference* a_target);
    void Function668350(TaskReference* a_target);
    void Function668380(TaskReference* a_target);
    void Function6683b0(TaskReference* a_target);
    void Function668440(TaskObject* a_target);
    void Function668480(TaskObject* a_target);
    void Function668500(TaskObject* a_target, std::uint32_t a_value);
    void Function668540(TaskObject* a_target, std::uint32_t a_value);
    void Function668580(TaskObject* a_target, std::uint32_t a_value);
    void Function668680(TaskReference* a_target);
    void Function668780(TaskReference* a_target, std::uint8_t a_value);
    void Function6688b0(TaskReference* a_target, std::uint8_t a_value);
    void Function6688f0(TaskObject* a_target);
    void Function668930(TaskReference* a_target);
    void Function668a50(TaskReference* a_target);
    void Function668a90(TaskReference* a_target);
    void Function668ad0(TaskReference* a_target);
    void Function668b10(TaskReference* a_target);
    void Function668b50(TaskReference* a_target);
    void Function668c40(const std::uint32_t& a_handle, float a_value);
    void Function668c80(TaskReference* a_target, std::uint8_t a_value);
    void Function668da0(TaskReference* a_target);
    void Function668de0(TaskReference* a_target);
    void Function668e20(TaskReference* a_target);
    void Function669010(const std::uint32_t& a_handle, void* a_object);
    void Function6691b0(TaskReference* a_target, std::uint32_t a_value);
    void Function6691f0(std::uint32_t a_argument, std::uint8_t a_value);
    void Function669220(std::uint8_t a_argument);
    void Function669250(std::uint32_t a_argument, std::uint32_t a_value);
    void Function6692d0(TaskReference* a_target);
    void Function669310(std::uint8_t a_argument);
    void Function669340(TaskObject* a_target);
    void Function669370(TaskObject* a_target);
    void Function6693a0(TaskObject* a_target);
    void Function6693d0(TaskReference* a_target);
    void Function669450(std::uint32_t a_argument);
    void Function669480(void* a_target, std::uint8_t a_value);
    void Function669550(TaskReference* a_target);
    void Function669590(const std::uint32_t& a_handle, std::uint8_t a_value);
};
