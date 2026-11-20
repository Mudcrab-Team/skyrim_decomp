// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAgent3ProcessInput; size 0x80
#pragma once

#include "hkPadSpu_float.h"
#include "hkPadSpu_hkpCdBody.h"
#include "hkPadSpu_hkpContactMgr.h"
#include "hkPadSpu_hkpProcessCollisionInput.h"
#include "hkTransform.h"
struct hkpAgent3ProcessInput {
    hkPadSpu_hkpCdBody m_bodyA_0;
    hkPadSpu_hkpCdBody m_bodyB_8;
    hkPadSpu_hkpCdBody m_overrideBodyA_10;
    hkPadSpu_hkpProcessCollisionInput m_input_18;
    hkPadSpu_hkpContactMgr m_contactMgr_20;
    char _pad_28[8];
    hkTransform m_aTb_30;
    hkPadSpu_float m_distAtT1_70;
    char _pad_74[12];
};
static_assert(sizeof(hkpAgent3ProcessInput) == 128, "hkpAgent3ProcessInput layout differs from the PDB");
