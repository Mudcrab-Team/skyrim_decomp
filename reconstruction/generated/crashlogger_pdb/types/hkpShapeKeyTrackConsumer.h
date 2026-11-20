// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeKeyTrackConsumer; size 0x18
#pragma once

#include "hkPadSpu_hkBlockList_uint32_512.h"
#include "hkPadSpu_hkBlockList_uint32_512___Block.h"
#include "hkPadSpu_int32.h"
struct hkpShapeKeyTrackConsumer {
    hkPadSpu_hkBlockList_uint32_512 m_blockList_0;
    hkPadSpu_hkBlockList_uint32_512___Block m_currentBlock_8;
    hkPadSpu_int32 m_currentElement_10;
    hkPadSpu_int32 m_numElementsToRead_14;
};
static_assert(sizeof(hkpShapeKeyTrackConsumer) == 24, "hkpShapeKeyTrackConsumer layout differs from the PDB");
