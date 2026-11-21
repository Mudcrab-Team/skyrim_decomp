// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeapType
#pragma once
enum class HeapType : int {
    kGlobal = 0,
    kLocal = 1,
    kDynamic = 2,
    kMask = 3,
};
