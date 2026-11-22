// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ObjectRefHandle, HighProcessData, AIProcess, AIProcess::high: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members this unit reads
// ObjectRefHandle::value: GUESS(low); NG hides it as a private _handle, the destructor keeps the handle non-trivial as in NG
// g_nullHandle: GUESS(low); the pack names this global kNullHandle (from community sources, not in the pinned NG)
#pragma once

#include <cstdint>

struct ObjectRefHandle
{
    std::uint32_t value;
    ~ObjectRefHandle() { value = 0; }
};

extern const ObjectRefHandle g_nullHandle;

// HighProcessData::headTrackTarget, HighProcessData::headTracked: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct HighProcessData
{
    unsigned char unk000[0x140];
    ObjectRefHandle headTrackTarget[6];
    bool headTracked[6];
};

class AIProcess
{
public:
    // AIProcess::GetHeadtrackTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    ObjectRefHandle GetHeadtrackTarget() const;

    void* unk00;
    void* unk08;
    HighProcessData* high;
};
