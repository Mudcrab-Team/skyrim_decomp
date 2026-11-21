// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DirtyFlag
#pragma once
enum class DirtyFlag : int {
    kMutable = 0,
    kVertex = 1,
    kNormal = 2,
    kColor = 4,
    kTexture = 8,
    kStatic = 16384,
    kVolatile = 32768,
};
