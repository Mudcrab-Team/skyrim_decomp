// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPSysLODModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysLODModifier::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x157dfb0 BSPSysLODModifier::SaveBinary
#include "BSPSysLODModifier_157dfb0.h"

// Save the base particle modifier and all four LOD float parameters to the stream.
void BSPSysLODModifier::SaveBinary(NiStream& a_stream)
{
    NiPSysModifier::SaveBinary(a_stream);
    a_stream.oStr->Write(&lodBeginDistance);
    a_stream.oStr->Write(&lodEndDistance);
    a_stream.oStr->Write(&endEmitScale);
    a_stream.oStr->Write(&endSize);
}
