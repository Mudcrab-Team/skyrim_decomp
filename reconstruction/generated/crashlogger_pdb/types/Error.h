// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: Error
#pragma once
enum class Error : int {
    kUnkFlag = -2147483648,
    kNone = 0,
    kNotFound = 1,
    kFileNotFound = 2,
    kAlreadyExists = 3,
    kNoChunk = 4,
    kNoID = 5,
    kBadFile = 6,
    kBadID = 7,
    kFormOpen = 8,
    kFileOpen = 9,
    kWriteFailure = 10,
    kInvalidFile = 11,
    kFileInUse = 12,
    kCreateFailure = 13,
    kErrorMask = 2147483647,
};
