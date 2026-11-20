// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSCPCullingType
#pragma once
enum class BSCPCullingType : int {
    kNormal = 0,
    kAllPass = 1,
    kAllFail = 2,
    kIgnoreMultiBounds = 3,
    kForceMultiBoundsNoUpdate = 4,
};
