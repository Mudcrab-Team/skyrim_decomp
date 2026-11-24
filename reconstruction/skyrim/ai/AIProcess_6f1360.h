// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess, AIProcess::SetLastSeenPosition: GUESS(low)
// AIProcess::high, AIProcess::middleHigh, MiddleHighProcessData::lastSeenPosition: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
#pragma once

#include <cstdint>
#include <cstddef>

struct NiPoint3
{
    float x;
    float y;
    float z;
};

struct MiddleHighProcessData
{
    std::uint8_t pad00[0xE0];
    NiPoint3 lastSeenPosition;  // 0E0
};

struct HighProcessData;

class AIProcess
{
public:
    void SetLastSeenPosition(const NiPoint3& a_position);  // compared: 0x6f1360

    void* middleLow;                      // 000
    MiddleHighProcessData* middleHigh;    // 008
    HighProcessData* high;                // 010
};
