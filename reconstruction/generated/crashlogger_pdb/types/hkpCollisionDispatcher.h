// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionDispatcher; size 0x5970
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkArray_hkpCollisionDispatcher__ShapeInheritance_hkContainerHeapAllocator.h"
#include "hkBool.h"
#include "hkpCollisionDispatcher__Agent3FuncsIntern.h"
#include "hkpCollisionDispatcher__AgentFuncs.h"
#include "hkpCollisionDispatcher__DebugEntry.h"
#include "hkpCollisionQualityInfo_c41be01b.h"
struct hkpCdBody_cce531ab;
struct hkpCollisionAgent;
struct hkpCollisionDispatcher__VFTable;
struct hkpCollisionInput;
struct hkpContactMgr;
struct hkpContactMgrFactory;
#pragma pack(push, 1)
struct hkpCollisionDispatcher {
    hkpCollisionDispatcher__DebugEntry m_debugAgent3Table_2978[32][32];
    unsigned char m_agent2TypesPred_6B0[32][32];
    hkBool m_midphaseAgent3Registered_2952;
    hkBool m_checkEnabled_2953;
    float m_expectedMaxLinearVelocity_2988;
    char _pad_2744[12];
    hkpCollisionDispatcher__DebugEntry m_debugAgent2Table_2968[32][32];
    hkpCollisionQualityInfo_c41be01b m_collisionQualityInfo_2750[8];
    hkpCollisionAgent*(*m_defaultCollisionAgent_10)(hkpCdBody_cce531ab* , hkpCdBody_cce531ab* , hkpCollisionInput* , hkpContactMgr* );
    unsigned int m_hasAlternateType_220[32];
    char _pad_218[8];
    hkpCollisionDispatcher__AgentFuncs m_agent2Func_AB0[64];
    hkpCollisionDispatcher__DebugEntry m_debugAgent2TablePred_2970[32][32];
    hkBool m_collisionAgentRegistered_2950;
    char m_collisionQualityTable_26E0[10][10];
    unsigned char m_agent3Types_14C0[32][32];
    unsigned char m_agent3TypesPred_18C0[32][32];
    hkpCollisionDispatcher__DebugEntry m_debugAgent3TablePred_2980[32][32];
    unsigned short m_memSizeAndFlags_8;
    short m_referenceCount_A;
    char _pad_2A4[12];
    hkpCollisionDispatcher__VFTable* vftable_hkpCollisionDispatcher_0;
    char _pad_C[4];
    int m_numAgent2Types_2A0;
    char _pad_2954[4];
    unsigned char m_agent2Types_2B0[32][32];
    int m_numAgent3Types_14B0;
    hkBool m_agent3Registered_2951;
    float m_expectedMinPsiDeltaTime_298C;
    hkArray_hkpCollisionDispatcher__ShapeInheritance_hkContainerHeapAllocator m_shapeInheritance_2958;
    hkpCollisionDispatcher__Agent3FuncsIntern m_agent3Func_1CC0[18];
    hkpContactMgrFactory* m_contactMgrFactory_18[8][8];
    char _pad_14B4[12];
};
#pragma pack(pop)
static_assert(sizeof(hkpCollisionDispatcher) == 22896, "hkpCollisionDispatcher layout differs from the PDB");
