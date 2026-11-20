// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionDispatcher__Agent3FuncsIntern; size 0x90
#pragma once

#include "hkBool.h"
struct hkStatisticsCollector;
struct hkpAgent3Input;
struct hkpAgent3ProcessInput;
struct hkpAgentEntry;
struct hkpCdBody_cce531ab;
struct hkpCollisionDispatcher;
struct hkpCollisionInput;
struct hkpConstraintOwner;
struct hkpContactMgr;
struct hkpProcessCollisionOutput;
struct hkpShapeKeyTrackConsumer;
struct hkpShapeKeyTrackWriter;
struct hkpCollisionDispatcher__Agent3FuncsIntern {
    void*(*m_createFunc_0)(hkpAgent3Input* , hkpAgentEntry* , void* );
    void (*m_destroyFunc_8)(hkpAgentEntry* , void* , hkpContactMgr* , hkpConstraintOwner* , hkpCollisionDispatcher* );
    void*(*m_cleanupFunc_10)(hkpAgentEntry* , void* , hkpContactMgr* , hkpConstraintOwner* );
    void (*m_removePointFunc_18)(hkpAgentEntry* , void* , unsigned short);
    void (*m_commitPotentialFunc_20)(hkpAgentEntry* , void* , unsigned short);
    void (*m_createZombieFunc_28)(hkpAgentEntry* , void* , unsigned short);
    void (*m_updateFilterFunc_30)(hkpAgentEntry* , void* , hkpCdBody_cce531ab* , hkpCdBody_cce531ab* , hkpCollisionInput* , hkpContactMgr* , hkpConstraintOwner* );
    void (*m_calcStatisticsFunc_38)(hkpAgentEntry* , void* , hkpCollisionInput* , hkStatisticsCollector* );
    void (*m_invalidateTimFunc_40)(hkpAgentEntry* , void* , hkpCollisionInput* );
    void (*m_warpTimeFunc_48)(hkpAgentEntry* , void* , float, float, hkpCollisionInput* );
    void (*m_sepNormalFunc_50)(hkpAgent3Input* , hkpAgentEntry* , void* , void*);
    void*(*m_processFunc_58)(hkpAgent3ProcessInput* , hkpAgentEntry* , void* , void*, hkpProcessCollisionOutput* );
    void*(*m_processMidphaseFunc_60)(hkpAgent3ProcessInput* , void* , hkpShapeKeyTrackWriter* );
    void*(*m_processPostMidphaseFunc_68)(hkpAgent3ProcessInput* , void* , hkpShapeKeyTrackConsumer* , hkpProcessCollisionOutput* );
    hkBool m_isPredictive_70;
    hkBool m_ignoreSymmetricVersion_71;
    hkBool m_reusePreviousEntry_72;
    char _pad_73[13];
    int m_symmetric_80;
    char _pad_84[12];
};
static_assert(sizeof(hkpCollisionDispatcher__Agent3FuncsIntern) == 144, "hkpCollisionDispatcher__Agent3FuncsIntern layout differs from the PDB");
