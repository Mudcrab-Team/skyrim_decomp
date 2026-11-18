// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// TESQuest: EXE_RTTI
// 0x3cdf10 TESQuest::sub

#include "TESQuest_3cdf10.h"
void TESQuest::sub(TESQuest* quest, std::uint32_t requestValue) { if (quest) { QuestRequest request{quest, requestValue}; quest->GetQueue()->Submit(request); } }
