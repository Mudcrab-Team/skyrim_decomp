// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiPSysModifier, BSPSysLODModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysLODModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier::IsEqual, NiPSysModifier::unk00, BSPSysLODModifier::lodBeginDistance, BSPSysLODModifier::lodEndDistance, BSPSysLODModifier::endEmitScale, BSPSysLODModifier::endSize: GUESS(low)
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

class BSPSysLODModifier : public NiPSysModifier
{
public:
    bool IsEqual(NiPSysModifier* a_other);

    float lodBeginDistance;
    float lodEndDistance;
    float endEmitScale;
    float endSize;
};
static_assert(offsetof(BSPSysLODModifier, lodBeginDistance) == 0x30, "lodBeginDistance offset");
static_assert(offsetof(BSPSysLODModifier, endSize) == 0x3C, "endSize offset");
