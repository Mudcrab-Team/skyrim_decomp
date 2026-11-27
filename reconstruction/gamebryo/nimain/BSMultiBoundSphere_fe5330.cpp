// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Write as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitransform.cpp:25
// SPDX-License-Identifier: CC0-1.0
// BSMultiBoundSphere: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBoundSphere::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfe5330 BSMultiBoundSphere::SaveBinary
#include "BSMultiBoundSphere_fe5330.h"

// Save the base bound shape, sphere center, and radius to the binary stream.
void BSMultiBoundSphere::SaveBinary(NiStream& a_stream)
{
    BSMultiBoundShape::SaveBinary(a_stream);
    center.SaveBinary(a_stream);
    a_stream.oStr->Write(&radius);
}
