// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QuestFlag
#pragma once
enum class QuestFlag : int {
    kStopStart = -1,
    kNone = 0,
    kEnabled = 1,
    kCompleted = 2,
    kAddIdleToHello = 4,
    kAllowRepeatStages = 8,
    kStartsEnabled = 16,
    kDisplayedInHUD = 32,
    kFailed = 64,
    kStageWait = 128,
    kRunOnce = 256,
    kExcludeFromExport = 512,
    kWarnOnAliasFillFailure = 1024,
    kActive = 2048,
    kRepeatsConditions = 4096,
    kKeepInstance = 8192,
    kWantDormant = 16384,
};
