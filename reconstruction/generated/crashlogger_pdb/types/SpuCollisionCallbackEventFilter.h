// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpuCollisionCallbackEventFilter
#pragma once
enum class SpuCollisionCallbackEventFilter : int {
    kNone = 0,
    kContactPointAdded = 1,
    kContactPointProcess = 2,
    kContactPointAddedOrProcess = 3,
    kContactPointRemoved = 4,
};
