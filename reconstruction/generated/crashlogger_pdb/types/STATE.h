// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: STATE
#pragma once
enum class STATE : int {
    kNone = 0,
    kStarted = 1,
    kMoving = 2,
    kWaitingRepath = 3,
    kStopped = 4,
    kUnreachable = 5,
    kUnk6 = 6,
};
