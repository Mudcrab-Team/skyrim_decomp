// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpShapeKeyTrackWriter; size 0x20
#pragma once

#include "hkPadSpu_hkBlockList_uint32_512.h"
#include "hkPadSpu_hkBlockList_uint32_512___Block.h"
#include "hkPadSpu_int32.h"
struct hkpShapeKeyTrackWriter {
    hkPadSpu_hkBlockList_uint32_512 m_blockList_0;
    hkPadSpu_hkBlockList_uint32_512___Block m_currentBlock_8;
    hkPadSpu_int32 m_currentElement_10;
    char _pad_14[4];
    hkPadSpu_hkBlockList_uint32_512___Block m_prevBlock_18;
};
static_assert(sizeof(hkpShapeKeyTrackWriter) == 32, "hkpShapeKeyTrackWriter layout differs from the PDB");
