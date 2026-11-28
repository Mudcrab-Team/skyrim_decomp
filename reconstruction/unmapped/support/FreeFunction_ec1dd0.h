// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// JobEventSlot_ec1dd0, JobManager_ec1dd0, g_jobManager_ec1dd0, Functionec1dd0, WaitForSingleObject, events, unk00, slots, slotIndex, eventIndex: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* handle, unsigned long timeoutMs);

struct JobEventSlot_ec1dd0
{
    void** events;  // 0x00
};

struct JobManager_ec1dd0
{
    std::uint64_t unk00;          // 0x00
    JobEventSlot_ec1dd0** slots;  // 0x08
};
static_assert(offsetof(JobManager_ec1dd0, slots) == 0x08, "slots offset");

extern JobManager_ec1dd0* g_jobManager_ec1dd0;

void Functionec1dd0(std::uint32_t slotIndex, std::uint32_t eventIndex);
