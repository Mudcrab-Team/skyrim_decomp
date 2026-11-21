// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: PACK_INTERRUPT_TARGET
#pragma once
enum class PACK_INTERRUPT_TARGET : int {
    kNone = -1,
    kSpectator = 0,
    kObserveDead = 1,
    kGuardWarn = 2,
    kCombat = 3,
};
