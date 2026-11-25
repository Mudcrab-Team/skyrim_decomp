// Source exposure: mixed (local binary analysis, community declarations, permitted sibling study).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// CheckForExpiredDetectionEvent: CRASHLOGGER_PDB(59818@2026.10.24); address suffix omitted
// HighProcessData, DetectionEvent, AITimeStamp: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// actorsGeneratedDetectionEvent, timeStamp: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// currentAITime, detectionEventExpireTime, unaccessedPrefix, unk14: GUESS(low); timer and expiry data inferred from use
// High_10: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstddef>
#include <cstdint>

struct AITimeStamp { float timeStamp; };
struct DetectionEvent { std::uint64_t unaccessedPrefix[2]; AITimeStamp timeStamp; std::uint32_t unk14; };
struct HighProcessData { char unaccessedPrefix[0x3D8]; DetectionEvent* actorsGeneratedDetectionEvent; };
class ActorProcess
{
public:
    void CheckForExpiredDetectionEvent();
    char unaccessedPrefix[0x10];
    HighProcessData* High_10;
};
extern float currentAITime;
extern float detectionEventExpireTime;
static_assert(sizeof(DetectionEvent) == 0x18, "detection event allocation size");
static_assert(offsetof(DetectionEvent, timeStamp) == 0x10, "event timestamp offset");
static_assert(offsetof(HighProcessData, actorsGeneratedDetectionEvent) == 0x3D8, "event pointer offset");
static_assert(offsetof(ActorProcess, High_10) == 0x10, "High_10 process offset");
