// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpLinearCastCollisionInput; size 0x80
#pragma once
struct hkpLinearCastCollisionInput {
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
    unsigned char path[16];
    float maxExtraPenetration;
    float cachedPathLength;
    void* config;
};
static_assert(sizeof(hkpLinearCastCollisionInput) == 128, "hkpLinearCastCollisionInput layout differs from the PDB");
