// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the listing
// SPDX-License-Identifier: CC0-1.0
// JobEventSlot_ec1d30, JobManager_ec1d30, g_threadIndex_tls_0x880, g_jobManager_ec1d30, Functionec1d30, SetEvent, events, unk00, slots, eventIndex: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern "C" __declspec(dllimport) int __stdcall SetEvent(void* eventHandle);

struct JobEventSlot_ec1d30
{
    void** events;  // 0x00
};

struct JobManager_ec1d30
{
    std::uint64_t unk00;          // 0x00
    JobEventSlot_ec1d30** slots;  // 0x08
};
static_assert(offsetof(JobManager_ec1d30, slots) == 0x08, "slots offset");

extern __declspec(thread) std::uint32_t g_threadIndex_tls_0x880;
extern JobManager_ec1d30* g_jobManager_ec1d30;

void Functionec1d30(std::uint32_t eventIndex);
