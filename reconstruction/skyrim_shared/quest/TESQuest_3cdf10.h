// Inferred names: GUESS(low)
// Origin: original reconstruction; no sibling source used.
// Source exposure: binary-analysis (local binary analysis).
// TESQuest: EXE_RTTI

#pragma once
#include <cstdint>
class TESQuest;
// QuestRequest, quest, requestValue, QuestQueue, Submit, GetQueue: GUESS(low) STANDIN
struct QuestRequest { TESQuest* quest; std::uint32_t requestValue; };
class QuestQueue { public: void Submit(QuestRequest& request); };
// sub: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class TESQuest { public: static void sub(TESQuest* quest, std::uint32_t requestValue); QuestQueue* GetQueue(); };
