// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: InterruptFlag
#pragma once
enum class InterruptFlag : int {
    kNone = 0,
    kHellosToPlayer = 1,
    kRandomConversations = 2,
    kObserveCombatBehaviour = 4,
    kGreetCorpseBehaviour = 8,
    kReactionToPlayerActions = 16,
    kFriendlyFireComments = 32,
    kAggroRadiusBehavior = 64,
    kAllowIdleChatter = 128,
    kWorldInteractions = 512,
};
