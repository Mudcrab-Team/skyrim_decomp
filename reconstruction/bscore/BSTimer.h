// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: declarations written for this reconstruction; names from the community headers
// below, layout from analysis of the pinned image; no implementation bodies reused.
// Adapted bodies: none declared; tools/check_origin.py reports none above its threshold (0.75)
// at CommonLibSSE-NG b93280e, powerof3/CommonLibSSE 654e55f and momusdigital/fnv_decomp 91e1b6e8.
// This is a minimal stand-in. All names are COMMUNITY (that revision, MIT) and unverified, except
// unk-prefixed members which are GUESS-free placeholders for unknown fields.
#pragma once

#include <cstdint>

class BSTimer {
public:
    // COMMUNITY: BSTimer::SetGlobalTimeMultiplier
    void SetGlobalTimeMultiplier(float a_multiplier, bool a_arg2);

    // BSTimer::Update: GUESS(low)
    // Advances the timer to a_tick (a millisecond counter).
    void Update(std::uint32_t a_tick);

    // COMMUNITY: QGlobalTimeMultiplier / QGlobalTimeMultiplierTarget accessors in NG read these
    // globals. They are modelled here as static data; the map binds them to the image addresses.
    static float QGlobalTimeMultiplier;
    static float QGlobalTimeMultiplierTarget;

    // frameSamples, smoothedTime, lastTime, baseTick, pauseCount, sampleCount, sampleIndex: GUESS(low)
    float*        frameSamples;                   // 00 ring buffer of recent deltas
    std::uint32_t lastPerformanceCount;           // 08
    std::uint32_t pad0C;                          // 0C (GUESS: alignment padding)
    float         clamp;                          // 10
    float         clampRemainder;                 // 14
    float         delta;                          // 18
    float         realTimeDelta;                  // 1C
    std::uint32_t smoothedTime;                   // 20
    std::uint32_t lastTime;                       // 24
    std::uint32_t baseTick;                       // 28
    std::uint32_t unk2C;                          // 2C
    std::uint32_t unk30;                          // 30
    std::uint32_t pauseCount;                     // 34
    std::uint8_t  sampleCount;                    // 38
    std::uint8_t  sampleIndex;                    // 39
    bool          useGlobalTimeMultiplierTarget;  // 3A
    std::uint8_t  pad3B;                          // 3B
    std::uint32_t pad3C;                          // 3C
};
