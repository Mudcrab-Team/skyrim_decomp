// Recipe: reconstruction/recipes/o2-fpfast.json
// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPSysLODModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysLODModifier::IsEqual: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x157e0a0 BSPSysLODModifier::IsEqual
#include "BSPSysLODModifier_157e0a0.h"

// Compare the base particle modifier and all four LOD float parameters.
bool BSPSysLODModifier::IsEqual(NiPSysModifier* a_other)
{
    if (!NiPSysModifier::IsEqual(a_other)) {
        return false;
    }

    auto* other = static_cast<BSPSysLODModifier*>(a_other);
    return other->lodBeginDistance == lodBeginDistance &&
           other->lodEndDistance == lodEndDistance &&
           other->endEmitScale == endEmitScale &&
           other->endSize == endSize;
}
