// Source exposure: mixed (pinned image listings, project queue units, and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: project queue layout, two method declarations adapted from CommonLibSSE-NG, and inferred argument types.
// QueueUpdateDestructibleObject, TESObjectREFR, NiPoint3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function667b50, Function667b90, Function667bd0, Function668230: GUESS(low)
// Function6683f0, Function6684c0, Function6685c0, Function668600: GUESS(low)
// Function668640, Function668730, Function668970, Function6689c0: GUESS(low)
// Function668a00, Function668b90, Function668cc0, Function668d60: GUESS(low)
// Function668e60, Function668f20, Function668f70, Function669050: GUESS(low)
// Function669280, Function669410: GUESS(low)
// TaskQueueInterface, QueueIfActive, BSPackedTask, TaskCounter, TaskReference, TaskObject, FlaggedTarget, HandleSource: STANDIN GUESS(low)
#pragma once

#include <cstdint>

struct BSPackedTask;
struct TaskCounter;
struct TaskObject;
struct TaskReference;
class TESObjectREFR;
class NiPoint3;
struct HandleSource;
struct FlaggedTarget;

class TaskQueueInterface
{
public:
    void QueueIfActive(BSPackedTask& a_task);
    void Function667b50(const std::uint32_t& a_handle, TaskObject* a_object);
    void Function667b90(void* a_target, TaskCounter* a_object);
    void Function667bd0(void* a_target, TaskCounter* a_object, std::uint8_t a_argument);
    void QueueUpdateDestructibleObject(TESObjectREFR* a_refr, float a_damage, bool a_arg3, TESObjectREFR* a_cause);
    void Function668230(TaskReference* a_target, std::uint8_t a_value, std::uint8_t a_argument);
    void Function6683f0(TaskObject* a_target, TaskObject* a_object, std::uint32_t a_argument);
    void Function6684c0(TaskObject* a_target, std::uint32_t a_value, std::uint8_t a_argument);
    void Function6685c0(TaskObject* a_target, std::uint32_t a_value, std::uint32_t a_argument);
    void Function668600(TaskObject* a_target, std::uint32_t a_value, std::uint32_t a_argument);
    void Function668640(TaskObject* a_target, float a_value);
    void Function668730(TaskObject* a_target, std::uint8_t a_value, std::uint8_t a_argument, std::uint8_t a_extra);
    void Function668970(TaskReference* a_target, void* a_object, std::uint8_t a_argument, std::uint8_t a_extra);
    void Function6689c0(TaskReference* a_target, void* a_object, std::uint8_t a_argument);
    void Function668a00(TaskReference* a_target, void* a_object, std::uint8_t a_argument, std::uint8_t a_extra);
    void Function668b90(TaskReference* a_target, std::uint8_t a_value, std::uint8_t a_argument);
    void Function668cc0(float a_scale, const NiPoint3& a_position);
    void Function668d60(TaskReference* a_target, std::uint8_t a_value, std::uint8_t a_argument);
    void Function668e60(TaskReference* a_target, TaskObject* a_object);
    void Function668f20(HandleSource* a_target);
    void Function668f70(FlaggedTarget* a_target);
    void Function669050(TaskReference* a_target, std::uint32_t a_value, std::uint8_t a_argument, std::uint8_t a_extra);
    void Function669280(TaskReference* a_target, TaskObject* a_object);
    void Function669410(TaskReference* a_target, void* a_object, void* a_argument);
};
