// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpSolverInfo; size 0x130
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "hkVector4.h"
struct hkpSolverInfo {
    float one;
    float tau;
    float damping;
    float frictionTau;
    hkVector4 globalAccelerationPerSubStep;
    hkVector4 globalAccelerationPerStep;
    hkVector4 integrateVelocityFactor;
    hkVector4 invIntegrateVelocityFactor;
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
static_assert(sizeof(hkpSolverInfo) == 304, "hkpSolverInfo layout differs from the PDB");
