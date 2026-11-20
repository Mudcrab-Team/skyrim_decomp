// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiMemEventType
#pragma once
enum class NiMemEventType : int {
    kUnknown = 0,
    kOperNew = 1,
    kOperNewArray = 2,
    kOperDelete = 3,
    kOperDeleteArray = 4,
    kMalloc = 5,
    kRealloc = 6,
    kAlignedMalloc = 7,
    kAlignedRealloc = 8,
    kFree = 9,
    kAlignedFree = 10,
    kExternalAlloc = 11,
    kExternalFree = 12,
};
