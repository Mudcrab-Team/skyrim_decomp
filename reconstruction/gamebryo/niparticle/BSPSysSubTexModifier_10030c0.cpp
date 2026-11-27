// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSPSysSubTexModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSPSysSubTexModifier::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x10030c0 BSPSysSubTexModifier::SaveBinary
#include "BSPSysSubTexModifier_10030c0.h"

// Save the base particle modifier and all seven sub-texture frame floats to the stream.
void BSPSysSubTexModifier::SaveBinary(NiStream& a_stream)
{
    NiPSysModifier::SaveBinary(a_stream);
    a_stream.oStr->Write(&startFrame);
    a_stream.oStr->Write(&startFrameFudge);
    a_stream.oStr->Write(&endFrame);
    a_stream.oStr->Write(&loopStartFrame);
    a_stream.oStr->Write(&loopStartFrameFudge);
    a_stream.oStr->Write(&frameCount);
    a_stream.oStr->Write(&frameCountFudge);
}
