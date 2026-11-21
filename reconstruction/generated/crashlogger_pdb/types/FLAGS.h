// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: FLAGS
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class FLAGS : int {
    kCreateIn = -2147483648,
    kNone = 0,
    kFamily = 1,
    kOptional = 2,
    kQuestObject = 4,
    kAllowReuse = 8,
    kAllowDead = 16,
    kLoadedOnly = 32,
    kEssential = 64,
    kAllowDisabled = 128,
    kStoreName = 256,
    kAllowReserved = 512,
    kProtected = 1024,
    kForcedFromAlias = 2048,
    kAllowDestroyed = 4096,
    kFindPlayerClosest = 8192,
    kUsesNames = 16384,
    kInitiallyDisabled = 32768,
    kAllowCleared = 65536,
    kClearNameOnRemove = 131072,
    kActorsOnly = 262144,
    kTransient = 524288,
    kExternalLink = 1048576,
    kNoPickpocket = 2097152,
    kDataAlias = 4194304,
    kSceneOptional = 16777216,
};
