// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSolverInfo; size 0x130
// one of 2 different PDB types sharing this name
#pragma once

#include "hkVector4_f554a678.h"
struct hkpSolverInfo_c7ce47cf {
    float one;
    float tau;
    float damping;
    float frictionTau;
    hkVector4_f554a678 globalAccelerationPerSubStep;
    hkVector4_f554a678 globalAccelerationPerStep;
    hkVector4_f554a678 integrateVelocityFactor;
    hkVector4_f554a678 invIntegrateVelocityFactor;
    float dampDivTau;
    float tauDivDamp;
    float dampDivFrictionTau;
    float frictionTauDivDamp;
    float contactRestingVelocity;
    unsigned char deactivationInfo_raw[168];
    float deltaTime;
    float invDeltaTime;
    int numSteps;
    int numMicroSteps;
    float invNumMicroSteps;
    float invNumSteps;
    bool forceCoherentConstraintOrderingInSolver;
    unsigned char deactivationNumInactiveFramesSelectFlag[2];
    unsigned char deactivationIntegrateCounter;
    float maxConstraintViolationSqrd;
    unsigned int pad12C;
};
static_assert(sizeof(hkpSolverInfo_c7ce47cf) == 304, "hkpSolverInfo_c7ce47cf layout differs from the PDB");
