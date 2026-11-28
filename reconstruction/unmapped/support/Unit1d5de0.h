// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// StagePayload1d5de0, StageEntry1d5de0, StageList1d5de0, Unit1d5de0, g_defaultReturn1d5de0, GetPayloadMetric1d5de0, FindThresholdHealth1d5de0, unk00, metricLimit, healthPercent, payload, maxHealth, count, stages, list: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern const float g_defaultReturn1d5de0;

struct StagePayload1d5de0
{
    std::uint8_t unk00[0xCC];  // 00
    float metricLimit;         // CC
};
static_assert(offsetof(StagePayload1d5de0, metricLimit) == 0xCC, "StagePayload1d5de0::metricLimit offset");

float GetPayloadMetric1d5de0(StagePayload1d5de0* a_payload);

struct StageEntry1d5de0
{
    std::uint8_t unk00;           // 00
    std::uint8_t healthPercent;   // 01
    StagePayload1d5de0* payload;  // 08
};
static_assert(offsetof(StageEntry1d5de0, healthPercent) == 0x01, "StageEntry1d5de0::healthPercent offset");
static_assert(offsetof(StageEntry1d5de0, payload) == 0x08, "StageEntry1d5de0::payload offset");

struct StageList1d5de0
{
    std::uint32_t maxHealth;  // 00
    std::uint8_t count;       // 04
    StageEntry1d5de0** stages;  // 08
};
static_assert(offsetof(StageList1d5de0, count) == 0x04, "StageList1d5de0::count offset");
static_assert(offsetof(StageList1d5de0, stages) == 0x08, "StageList1d5de0::stages offset");

struct Unit1d5de0
{
    std::uint64_t unk00;    // 00
    StageList1d5de0* list;  // 08

    float FindThresholdHealth1d5de0(std::uint8_t a_currentPercent, float a_minMetric, float a_maxLimit, StagePayload1d5de0** a_outPayload);  // compared: 0x1d5de0
};
static_assert(offsetof(Unit1d5de0, list) == 0x08, "Unit1d5de0::list offset");
