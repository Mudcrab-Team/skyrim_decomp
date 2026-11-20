// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionDispatcher__AgentFuncs; size 0x28
#pragma once

#include "hkBool.h"
struct hkpCdBodyPairCollector;
struct hkpCdBody_cce531ab;
struct hkpCdPointCollector_f72767ea;
struct hkpCollisionAgent;
struct hkpCollisionInput;
struct hkpContactMgr;
struct hkpLinearCastCollisionInput;
struct hkpCollisionDispatcher__AgentFuncs {
    hkpCollisionAgent*(*m_createFunc_0)(hkpCdBody_cce531ab* , hkpCdBody_cce531ab* , hkpCollisionInput* , hkpContactMgr* );
    void (*m_getPenetrationsFunc_8)(hkpCdBody_cce531ab* , hkpCdBody_cce531ab* , hkpCollisionInput* , hkpCdBodyPairCollector* );
    void (*m_getClosestPointFunc_10)(hkpCdBody_cce531ab* , hkpCdBody_cce531ab* , hkpCollisionInput* , hkpCdPointCollector_f72767ea* );
    void (*m_linearCastFunc_18)(hkpCdBody_cce531ab* , hkpCdBody_cce531ab* , hkpLinearCastCollisionInput* , hkpCdPointCollector_f72767ea* , hkpCdPointCollector_f72767ea* );
    hkBool m_isFlipped_20;
    hkBool m_isPredictive_21;
    char _pad_22[6];
};
static_assert(sizeof(hkpCollisionDispatcher__AgentFuncs) == 40, "hkpCollisionDispatcher__AgentFuncs layout differs from the PDB");
