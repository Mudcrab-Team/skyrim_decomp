// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpCollisionInput; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct hkpCollisionInput {
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
};
static_assert(sizeof(hkpCollisionInput) == 96, "hkpCollisionInput layout differs from the PDB");
