// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess, high, HighProcessData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// StartShout: SYMBOLS(tesv-2013-map); candidate identity inferred from local behavior
#pragma once
#include <cstddef>
// TESShout: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// voiceState, currentShout, currentShoutVariation, voiceTimeElapsed: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknownProcessPrefix: GUESS(low); unmodeled storage
class TESShout;
struct HighProcessData
{
    unsigned int voiceState;
    unsigned int pad004;
    TESShout* currentShout;
    unsigned int currentShoutVariation;
    float voiceTimeElapsed;
};
static_assert(offsetof(HighProcessData, currentShout) == 0x8, "current shout offset");
static_assert(offsetof(HighProcessData, currentShoutVariation) == 0x10, "variation offset");
static_assert(offsetof(HighProcessData, voiceTimeElapsed) == 0x14, "elapsed time offset");
class AIProcess
{
public:
    bool StartShout(TESShout* shout, unsigned int variation);
    unsigned char unknownProcessPrefix[0x10];
    HighProcessData* high;
};
static_assert(offsetof(AIProcess, high) == 0x10, "high process offset");
