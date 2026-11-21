// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TEMPLATE_USE_FLAG
#pragma once
enum class TEMPLATE_USE_FLAG : int {
    kNone = 0,
    kTraits = 1,
    kStats = 2,
    kFactions = 4,
    kSpells = 8,
    kAIData = 16,
    kAIPackages = 32,
    kUnused = 64,
    kBaseData = 128,
    kInventory = 256,
    kScript = 512,
    kAIDefPackList = 1024,
    kAttackData = 2048,
    kKeywords = 4096,
    kCopiedTemplate = 32768,
};
