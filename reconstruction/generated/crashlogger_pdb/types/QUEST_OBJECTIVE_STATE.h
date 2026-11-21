// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: QUEST_OBJECTIVE_STATE
// one of 2 different PDB types sharing this name; the fullest
#pragma once
enum class QUEST_OBJECTIVE_STATE : int {
    QUEST_OBJECTIVE_STATE__kDormant = 0,
    QUEST_OBJECTIVE_STATE__kDisplayed = 1,
    QUEST_OBJECTIVE_STATE__kCompleted = 2,
    QUEST_OBJECTIVE_STATE__kCompletedDisplayed = 3,
    QUEST_OBJECTIVE_STATE__kFailed = 4,
    QUEST_OBJECTIVE_STATE__kFailedDisplayed = 5,
};
