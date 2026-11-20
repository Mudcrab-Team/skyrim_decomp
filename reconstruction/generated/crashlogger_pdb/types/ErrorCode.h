// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ErrorCode
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class ErrorCode : int {
    kNone = 0,
    kNotExist = 1,
    kInvalidPath = 2,
    kFileError = 3,
    kInvalidType = 4,
    kMemoryError = 5,
    kBusy = 6,
    kInvalidParam = 7,
    kUnsupported = 8,
};
