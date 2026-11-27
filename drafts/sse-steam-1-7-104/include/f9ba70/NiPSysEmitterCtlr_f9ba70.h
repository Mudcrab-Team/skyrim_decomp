// Exposure detail: (pinned-image observations and RTTI).
// Source exposure: binary-analysis
// Code origin: original; observed initialization and RTTI class identity.
// SPDX-License-Identifier: CC0-1.0
// NiPSysEmitterCtlr, NiPSysModifierCtlr: EXE_RTTI
// baseData, visibilityInterpolator, unknown68, scaledLastTime, unknown74, unknown78, state, State: GUESS(low) STANDIN

#pragma once
#include <cstdint>
#include <cstddef>
class NiPSysModifierCtlr {
public:
    NiPSysModifierCtlr();
    virtual ~NiPSysModifierCtlr();
    std::uint8_t baseData[0x58];
};
class NiPSysEmitterCtlr : public NiPSysModifierCtlr {
public:
    NiPSysEmitterCtlr();
    ~NiPSysEmitterCtlr() override;
    void* visibilityInterpolator;
    void* unknown68;
    float scaledLastTime;
    std::uint32_t unknown74;
    std::uint64_t unknown78;
    struct State { std::uint64_t first, second; } state;
};
static_assert(offsetof(NiPSysEmitterCtlr, visibilityInterpolator) == 0x60, "interpolator offset");
static_assert(offsetof(NiPSysEmitterCtlr, state) == 0x80, "state offset");
static_assert(sizeof(NiPSysEmitterCtlr) == 0x90, "emitter controller size");
