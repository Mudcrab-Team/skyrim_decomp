// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSParentVelocityModifier: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSParentVelocityModifier::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x1001890 BSParentVelocityModifier::LoadBinary
#include "BSParentVelocityModifier_1001890.h"

// Load the base particle modifier and the damping factor from the stream.
void BSParentVelocityModifier::LoadBinary(NiStream& a_stream)
{
    NiPSysModifier::LoadBinary(a_stream);
    a_stream.iStr->Read(&damping);
}
