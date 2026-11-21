// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpAgent3Input; size 0x70
#pragma once

#include "hkPadSpu_hkpCdBody.h"
#include "hkPadSpu_hkpContactMgr.h"
#include "hkPadSpu_hkpProcessCollisionInput.h"
#include "hkTransform.h"
struct hkpAgent3Input {
    hkPadSpu_hkpCdBody m_bodyA_0;
    hkPadSpu_hkpCdBody m_bodyB_8;
    hkPadSpu_hkpCdBody m_overrideBodyA_10;
    hkPadSpu_hkpProcessCollisionInput m_input_18;
    hkPadSpu_hkpContactMgr m_contactMgr_20;
    char _pad_28[8];
    hkTransform m_aTb_30;
};
static_assert(sizeof(hkpAgent3Input) == 112, "hkpAgent3Input layout differs from the PDB");
