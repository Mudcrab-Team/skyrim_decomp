// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// Adapted bodies: none known. The origin check reports NiBinaryStream::Write as similar to the sibling bodies cited below (CC0-1.0); the draft states it was written from the pinned image listing.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitransform.cpp:25
// SPDX-License-Identifier: CC0-1.0
// BSValueNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSValueNode::SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfd3370 BSValueNode::SaveBinary
#include "BSValueNode_fd3370.h"

// Save base node data, numeric value, and flags to the binary stream.
void BSValueNode::SaveBinary(NiStream& a_stream)
{
    NiNode::SaveBinary(a_stream);

    const std::uint32_t savedValue = value;
    a_stream.oStr->Write(&savedValue);
    a_stream.oStr->Write(&flags);
}
