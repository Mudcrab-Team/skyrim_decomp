// Source exposure: mixed (local binary analysis and public names).
// Code origin: original; the two bodies are written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// NiPSysEmitterCtlr: EXE_RTTI
// Functionf62de0, Functioneb11e0, Functionf9a3f0, field50, field98: GUESS(low)
#pragma once
#include <cstdint>

class NiPSysEmitterCtlr;
void Functionf62de0(NiPSysEmitterCtlr* a_source, NiPSysEmitterCtlr* a_destination);
void Functioneb11e0(void* a_destination, void* a_source);
void Functionf9a3f0(NiPSysEmitterCtlr* a_source, NiPSysEmitterCtlr* a_destination);

class NiPSysEmitterCtlr
{
public:
    virtual std::uint32_t GetInterpolatorCount() const;
    void Functionfa0950(NiPSysEmitterCtlr* a_other);
    void Functionff4f40(NiPSysEmitterCtlr* a_other);

    std::uint8_t pad08[0x48];  // 08
    std::uint8_t field50[0x10];  // 50
    std::uint8_t pad60[0x38];  // 60
    std::uint16_t field98;  // 98
};
