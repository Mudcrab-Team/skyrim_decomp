// Source exposure: mixed (local binary analysis, community declarations, permitted sibling study).
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// FadeIn: CRASHLOGGER_PDB(59818@2026.10.24)
// Actor, TESObjectREFR, HighProcessData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// fadeState, fadeAlpha, fadeTrigger, FADE_STATE, kNormal, kIn, kTeleportIn, kOutDisable, kOutDelete: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unaccessedPrefix: GUESS(low); unaccessed prefix of each reduced declaration
// High_10: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include <cstddef>
#include <cstdint>

class Actor;
class TESObjectREFR;
struct HighProcessData
{
    enum class FADE_STATE : std::uint32_t { kNormal=0, kIn=1, kTeleportIn=3, kOutDisable=5, kOutDelete=6 };
    char unaccessedPrefix[0x130];
    FADE_STATE fadeState;
    float fadeAlpha;
    TESObjectREFR* fadeTrigger;
};
class ActorProcess
{
public:
    void FadeIn(Actor* actor, bool teleport);
    char unaccessedPrefix[0x10];
    HighProcessData* High_10;
};
static_assert(offsetof(ActorProcess, High_10) == 0x10, "High_10 process offset");
static_assert(offsetof(HighProcessData, fadeState) == 0x130, "fade state offset");
static_assert(offsetof(HighProcessData, fadeAlpha) == 0x134, "fade alpha offset");
static_assert(offsetof(HighProcessData, fadeTrigger) == 0x138, "fade trigger offset");
