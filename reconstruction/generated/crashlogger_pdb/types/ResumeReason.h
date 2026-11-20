// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ResumeReason
#pragma once
enum class ResumeReason : int {
    kNotResuming = 0,
    kNotResumingNoIncrement = 1,
    kInitialStart = 2,
    kFunctionReturn = 3,
    kRetryInstruction = 4,
    kFunctionCall = 5,
};
