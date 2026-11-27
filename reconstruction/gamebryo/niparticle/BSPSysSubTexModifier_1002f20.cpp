// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPSysSubTexModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysSubTexModifier::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x1002f20 BSPSysSubTexModifier::LoadBinary
#include "BSPSysSubTexModifier_1002f20.h"

// Load the base particle modifier and all seven sub-texture frame floats from the stream.
void BSPSysSubTexModifier::LoadBinary(NiStream& a_stream)
{
    NiPSysModifier::LoadBinary(a_stream);
    a_stream.iStr->Read(&startFrame);
    a_stream.iStr->Read(&startFrameFudge);
    a_stream.iStr->Read(&endFrame);
    a_stream.iStr->Read(&loopStartFrame);
    a_stream.iStr->Read(&loopStartFrameFudge);
    a_stream.iStr->Read(&frameCount);
    a_stream.iStr->Read(&frameCountFudge);
}
