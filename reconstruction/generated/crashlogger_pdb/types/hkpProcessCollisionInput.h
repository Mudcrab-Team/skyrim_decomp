// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProcessCollisionInput; size 0xa0
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkpProcessCollisionInput {
    void* m_dispatcher;
    int m_weldClosestPoints;
    int m_forceAcceptContactPoints;
    float m_tolerance;
    unsigned int pad14;
    void* m_filter;
    void* m_convexListFilter;
    int m_createPredictiveAgents;
    unsigned int pad2C;
    unsigned char aabb32Info[48];
    unsigned char m_stepInfo[16];
    void* m_collisionQualityInfo;
    void* m_spareAgentSector;
    void* m_dynamicsInfo;
    unsigned char m_enableDeprecatedWelding;
    unsigned char m_allowToSkipConfirmedCallbacks;
    unsigned char pad8A[6];
    void* m_config;
    unsigned char pad98[8];
};
static_assert(sizeof(hkpProcessCollisionInput) == 160, "hkpProcessCollisionInput layout differs from the PDB");
