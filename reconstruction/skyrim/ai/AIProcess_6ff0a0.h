// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess, AIProcess::GetHeadtrackTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// AIProcess::high, HighProcessData::headTrackTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) STANDIN
// ObjectRefHandle, g_nullRefHandle: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct ObjectRefHandle
{
    ObjectRefHandle() : native(0) {}
    ObjectRefHandle(const ObjectRefHandle& a_rhs) : native(a_rhs.native) {}
    ~ObjectRefHandle() {}
    std::uint32_t native;
};

extern ObjectRefHandle g_nullRefHandle;

struct HighProcessData
{
    std::uint8_t pad00[0x140];
    ObjectRefHandle headTrackTarget[6];  // 140
};

class AIProcess
{
public:
    ObjectRefHandle GetHeadtrackTarget(std::int32_t a_type) const;  // compared: 0x6ff0a0

    void* middleLow;                // 000
    void* middleHigh;               // 008
    HighProcessData* high;          // 010
};
