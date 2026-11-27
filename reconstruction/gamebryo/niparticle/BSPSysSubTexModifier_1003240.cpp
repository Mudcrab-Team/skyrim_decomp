// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPSysSubTexModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysSubTexModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x1003240 BSPSysSubTexModifier::IsEqual
#include "BSPSysSubTexModifier_1003240.h"

// Compare the base particle modifier and all seven sub-texture frame floats.
bool BSPSysSubTexModifier::IsEqual(NiPSysModifier* a_other)
{
    if (!NiPSysModifier::IsEqual(a_other)) {
        return false;
    }

    auto* other = static_cast<BSPSysSubTexModifier*>(a_other);
    return other->startFrame == startFrame &&
           other->startFrameFudge == startFrameFudge &&
           other->endFrame == endFrame &&
           other->loopStartFrame == loopStartFrame &&
           other->loopStartFrameFudge == loopStartFrameFudge &&
           other->frameCount == frameCount &&
           other->frameCountFudge == frameCountFudge;
}
