// Source exposure: mixed (community headers; the pinned image listing and decompiler output).
// Code origin: brown-room reconstruction from disassembly
// Drafted by: eclepso, assisted by claude-sonnet-5-5
// 0xce36b0 BSTimer::Update
// 0xce3970 BSTimer::SetGlobalTimeMultiplier
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "BSTimer.h"

void BSTimer::SetGlobalTimeMultiplier(float a_multiplier, bool a_arg2)
{
    // The flag is read before the global store: bool aliases any object, so the store would
    // otherwise force a reload after it.
    const bool useTarget = useGlobalTimeMultiplierTarget;
    QGlobalTimeMultiplierTarget = a_multiplier;
    if (useTarget) {
        if (a_arg2) {
            QGlobalTimeMultiplier = a_multiplier;
        }
    } else if (a_multiplier != QGlobalTimeMultiplier) {
        delta /= QGlobalTimeMultiplier;
        QGlobalTimeMultiplier = a_multiplier;
        delta *= a_multiplier;
    }
}

void BSTimer::Update(std::uint32_t a_tick)
{
    std::uint32_t now = a_tick - baseTick;
    if (pauseCount == 0) {
        float fixedStep = clamp;
        if (fixedStep != 0.0f) {
            float total = fixedStep + clampRemainder;
            std::uint32_t whole = static_cast<std::uint32_t>(total);
            clampRemainder = total - static_cast<float>(whole);
            now = lastTime + whole;
            delta = fixedStep * 0.001f;
        } else {
            float ms = static_cast<float>(now - lastTime);
            if (ms > 166.666672f) {
                delta = 0.166666672f;
            } else {
                delta = ms * 0.001f;
            }
        }
        std::uint32_t count = sampleCount;
        if (count >= 3) {
            frameSamples[sampleIndex] = delta;
            sampleIndex = static_cast<std::uint8_t>((sampleIndex + 1u) % count);
            float hi = 0.0f;
            float lo = 0.166666672f;
            float sum = 0.0f;
            for (std::uint32_t i = 0; i < count; ++i) {
                float v = frameSamples[i];
                sum += v;
                hi = v > hi ? v : hi;
                lo = v < lo ? v : lo;
            }
            hi = hi > 0.0f ? hi : 0.0f;
            hi = hi < 0.05f ? hi : 0.05f;
            delta = (sum - hi - lo) / static_cast<float>(count - 2);
            smoothedTime += static_cast<std::uint32_t>(delta * 1000.0f);
            lastTime = now;
        } else {
            smoothedTime = now;
            lastTime = now;
        }
        realTimeDelta = delta;
        delta = delta * QGlobalTimeMultiplier;
    } else {
        delta = 0.0f;
        realTimeDelta = 0.0f;
    }
}
