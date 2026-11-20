// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MST
#pragma once
enum class MST : int {
    kNone = 0,
    kPlaysOnce = 1,
    kAbruptTransition = 2,
    kCycleTracks = 4,
    kUseTrackOrder = 8,
    kRemovalQueued = 16,
    kPlaysOver = 32,
    kDoesntQueue = 64,
};
