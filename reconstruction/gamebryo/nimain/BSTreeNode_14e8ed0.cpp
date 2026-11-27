// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BSTreeNode: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSTreeNode::RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// 0x14e8ed0 BSTreeNode::RegisterStreamables
#include "BSTreeNode_14e8ed0.h"

// Register the base node and both tree child object arrays with the stream.
bool BSTreeNode::RegisterStreamables(NiStream& a_stream)
{
    if (!BSLeafAnimNode::RegisterStreamables(a_stream)) {
        return false;
    }

    for (std::uint32_t i = 0; i < array1Size; ++i) {
        array1Data[i]->RegisterStreamables(a_stream);
    }
    for (std::uint32_t i = 0; i < array2Size; ++i) {
        array2Data[i]->RegisterStreamables(a_stream);
    }
    return true;
}
