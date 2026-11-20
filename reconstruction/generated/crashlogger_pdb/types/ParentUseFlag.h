// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ParentUseFlag
#pragma once
enum class ParentUseFlag : int {
    kNone = 0,
    kUseLandData = 1,
    kUseLODData = 2,
    kUseMapData = 4,
    kUseWaterData = 8,
    kUseClimateData = 16,
    kUseImageSpaceData = 32,
    kUseSkyCell = 64,
};
