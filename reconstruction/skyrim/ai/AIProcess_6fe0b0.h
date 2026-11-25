// Source exposure: mixed
// Code origin: declarations and layout reconstruction using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// AIProcess, high, HighProcessData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FadeOut: SYMBOLS(tesv-2013-map); candidate identity inferred from local behavior
#pragma once
#include <cstddef>
// fadeState, fadeAlpha, fadeTrigger: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// FADE_STATE, kNormal, kIn, kOut, kTeleportIn, kTeleportOut, kOutDisable, kOutDelete: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknownPrefix, unknownProcessPrefix: GUESS(low); unmodeled storage
class TESObjectREFR;
struct HighProcessData
{
    enum FADE_STATE : unsigned int { kNormal, kIn, kOut, kTeleportIn, kTeleportOut, kOutDisable, kOutDelete };
    unsigned char unknownPrefix[0x130];
    FADE_STATE fadeState;
    float fadeAlpha;
    TESObjectREFR* fadeTrigger;
};
static_assert(offsetof(HighProcessData, fadeState) == 0x130, "fade state offset");
static_assert(offsetof(HighProcessData, fadeAlpha) == 0x134, "fade alpha offset");
static_assert(offsetof(HighProcessData, fadeTrigger) == 0x138, "fade trigger offset");
// Actor, TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class Actor;
class AIProcess
{
public:
    void FadeOut(Actor* actor, TESObjectREFR* trigger, bool teleport);
    unsigned char unknownProcessPrefix[0x10];
    HighProcessData* high;
};
static_assert(offsetof(AIProcess, high) == 0x10, "high process offset");
