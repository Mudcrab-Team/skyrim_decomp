// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBound::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfcd790 BSMultiBound::SaveBinary
#include "BSMultiBound_fcd790.h"

// Save base object data and write the link ID for the bound shape.
void BSMultiBound::SaveBinary(NiStream& a_stream)
{
    NiObject::SaveBinary(a_stream);
    a_stream.SaveLinkID(data);
}
