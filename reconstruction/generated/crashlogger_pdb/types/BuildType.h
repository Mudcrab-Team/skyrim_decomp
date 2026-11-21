// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BuildType
#pragma once
enum class BuildType : int {
    kBuildWithChunkSubdivision = 0,
    kBuildWithoutChunkSubdivision = 1,
    kBuildNotSet = 2,
};
