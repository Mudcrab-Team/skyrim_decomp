// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiBinaryExtraData: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiBinaryExtraData::LoadBinary_140C83C80: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xf0f9c0 NiBinaryExtraData::LoadBinary_140C83C80
#include "NiBinaryExtraData_f0f9c0.h"

// Load the base extra data, read payload byte count, and create and read the payload buffer.
void NiBinaryExtraData::LoadBinary_140C83C80(NiStream& a_stream)
{
    NiExtraData::LoadBinary(a_stream);
    a_stream.iStr->Read(&size);
    if (size > 0) {
        data = AllocBinaryPayload(size);
        a_stream.iStr->ReadBytes(data, size);
    }
}
