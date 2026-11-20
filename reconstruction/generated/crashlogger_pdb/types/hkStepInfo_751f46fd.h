// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkStepInfo; size 0x10
// one of 2 different PDB types sharing this name
#pragma once

#include "hkPadSpu_float.h"
struct hkStepInfo_751f46fd {
    hkPadSpu_float m_startTime_0;
    hkPadSpu_float m_endTime_4;
    hkPadSpu_float m_deltaTime_8;
    hkPadSpu_float m_invDeltaTime_C;
};
static_assert(sizeof(hkStepInfo_751f46fd) == 16, "hkStepInfo_751f46fd layout differs from the PDB");
