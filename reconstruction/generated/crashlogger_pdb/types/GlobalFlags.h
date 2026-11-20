// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: GlobalFlags
#pragma once
enum class GlobalFlags : int {
    kGlobalAllowChanges = 1,
    kSaveGameLoading = 2,
    kSaveGameSaving = 4,
    kInitingForms = 8,
    kDeferInitForms = 16,
    kPositioningPlayerCharacter = 32,
    kPlayerLocationInvalid = 64,
};
