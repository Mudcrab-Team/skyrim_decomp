// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Atoms; size 0xf0
#pragma once

#include "hkp2dAngConstraintAtom.h"
#include "hkpAngFrictionConstraintAtom.h"
#include "hkpAngLimitConstraintAtom.h"
#include "hkpAngMotorConstraintAtom.h"
#include "hkpSetLocalTransformsConstraintAtom.h"
#include "hkpSetupStabilizationAtom.h"
struct Atoms {
    hkpSetLocalTransformsConstraintAtom transforms;
    hkpSetupStabilizationAtom setupStabilization;
    hkpAngMotorConstraintAtom angMotor;
    hkpAngFrictionConstraintAtom angFriction;
    hkpAngLimitConstraintAtom angLimit;
    hkp2dAngConstraintAtom twoDAng;
    unsigned char ballSocket_raw[24];
};
static_assert(sizeof(Atoms) == 240, "Atoms layout differs from the PDB");
