// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Read as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nianimation/niboolinterpolator.cpp:678
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nianimation/nibsplinefloatinterpolator.cpp:29
// SPDX-License-Identifier: CC0-1.0
// BSValueNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSValueNode::LoadBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfd32a0 BSValueNode::LoadBinary
#include "BSValueNode_fd32a0.h"

// Load base node data, numeric value, and flags from the binary stream.
void BSValueNode::LoadBinary(NiStream& a_stream)
{
    NiNode::LoadBinary(a_stream);

    std::uint32_t loadedValue;
    a_stream.iStr->Read(&loadedValue);
    value = loadedValue;
    a_stream.iStr->Read(&flags);
}
