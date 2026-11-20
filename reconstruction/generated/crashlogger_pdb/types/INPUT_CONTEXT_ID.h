// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: INPUT_CONTEXT_ID
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class INPUT_CONTEXT_ID : int {
    kGameplay = 0,
    kMenuMode = 1,
    kConsole = 2,
    kItemMenu = 3,
    kInventory = 4,
    kDebugText = 5,
    kFavorites = 6,
    kMap = 7,
    kStats = 8,
    kCursor = 9,
    kBook = 10,
    kDebugOverlay = 11,
    kJournal = 12,
    kTFCMode = 13,
    kMapDebug = 14,
    kLockpicking = 15,
    kMarketplace = 16,
    kFavor = 17,
    kTotal = 18,
    kNone = 19,
};
