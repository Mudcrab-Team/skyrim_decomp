// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Read as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp:678
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitransform.cpp:19
// SPDX-License-Identifier: CC0-1.0
// BSMultiBoundSphere: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBoundSphere::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfe5290 BSMultiBoundSphere::LoadBinary
#include "BSMultiBoundSphere_fe5290.h"

// Load the base bound shape, sphere center, and radius from the binary stream.
void BSMultiBoundSphere::LoadBinary(NiStream& a_stream)
{
    BSMultiBoundShape::LoadBinary(a_stream);
    center.LoadBinary(a_stream);
    a_stream.iStr->Read(&radius);
}
