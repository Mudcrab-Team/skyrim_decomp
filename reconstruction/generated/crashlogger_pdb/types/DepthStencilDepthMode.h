// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DepthStencilDepthMode
#pragma once
enum class DepthStencilDepthMode : int {
    kDisabled = 0,
    kTest = 1,
    kWrite = 2,
    kTestWrite = 3,
    kTestEqual = 4,
    kTestGreaterEqual = 5,
    kTestGreater = 6,
};
