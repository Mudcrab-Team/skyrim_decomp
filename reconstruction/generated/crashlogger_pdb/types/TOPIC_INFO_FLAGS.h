// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TOPIC_INFO_FLAGS
#pragma once
enum class TOPIC_INFO_FLAGS : int {
    kNone = 0,
    kStartSceneOnEnd = 1,
    kRandom = 2,
    kSayOnce = 4,
    kRequiresPlayerActivation = 8,
    kInfoRefusal = 16,
    kRandomEnd = 32,
    kEndRunningScene = 64,
    kIsForceGreet = 128,
    kPlayerAddress = 256,
    kForceSubtitle = 512,
    kCanMoveWhileGreeting = 1024,
    kNoLIPFile = 2048,
    kPostProcess = 4096,
    kCustomSoundOutput = 8192,
    kSpendsFavorPoints = 16384,
};
