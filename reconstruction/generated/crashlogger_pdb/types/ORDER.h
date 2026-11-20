// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ORDER
#pragma once
enum class ORDER : int {
    kKillOldParticles = 0,
    kBSLOD = 1,
    kEmitter = 1000,
    kSpawn = 2000,
    kGeneral = 3000,
    kForce = 4000,
    kCollider = 5000,
    kPosUpdate = 6000,
    kPostPosUpdate = 6500,
    kBoundUpdate = 7000,
    kBSStripUpdate = 8000,
};
