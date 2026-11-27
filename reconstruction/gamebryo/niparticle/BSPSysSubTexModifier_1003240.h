// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiPSysModifier, BSPSysSubTexModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysSubTexModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier::IsEqual, NiPSysModifier::unk00, BSPSysSubTexModifier::startFrame, BSPSysSubTexModifier::startFrameFudge, BSPSysSubTexModifier::endFrame, BSPSysSubTexModifier::loopStartFrame, BSPSysSubTexModifier::loopStartFrameFudge, BSPSysSubTexModifier::frameCount, BSPSysSubTexModifier::frameCountFudge: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiPSysModifier
{
public:
    bool IsEqual(NiPSysModifier* a_other);

    std::uint8_t unk00[0x30];
};
static_assert(sizeof(NiPSysModifier) == 0x30, "NiPSysModifier size");

class BSPSysSubTexModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiPSysModifier* a_other);

    float startFrame;
    float startFrameFudge;
    float endFrame;
    float loopStartFrame;
    float loopStartFrameFudge;
    float frameCount;
    float frameCountFudge;
};
static_assert(offsetof(BSPSysSubTexModifier, startFrame) == 0x30, "startFrame offset");
static_assert(offsetof(BSPSysSubTexModifier, frameCountFudge) == 0x48, "frameCountFudge offset");
