// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ITEM_REMOVE_REASON
#pragma once
enum class ITEM_REMOVE_REASON : int {
    kRemove = 0,
    kSteal = 1,
    kSelling = 2,
    kDropping = 3,
    kStoreInContainer = 4,
    kStoreInTeammate = 5,
};
