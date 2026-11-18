// Inferred names: GUESS(low)
// Origin: declarations adapted from CommonLibSSE-NG b93280e, MIT; body original reconstruction.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BGSScene, TESForm, BaseFormComponent, BSTArray, BSTArrayHeapAllocator, BSTArrayBase, TESCondition: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// sourceFiles, formFlags, formID, inGameFormFlags, formType, pad1B, pad1C, phases, actors, actorFlags, actorProgressionFlags, actions, parentQuest, flags, padA4, conditions, isPlaying, unkB1, unkB2, unkB3: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetScene, Function3a8a70: GUESS(low)
#pragma once
#include <cstdint>
class BGSScenePhase; class BGSSceneAction; class TESQuest; class TESConditionItem;
class BaseFormComponent { public: virtual ~BaseFormComponent(); };
class TESForm : public BaseFormComponent { public: void* sourceFiles; std::uint32_t formFlags; std::uint32_t formID; std::uint16_t inGameFormFlags; std::uint8_t formType; std::uint8_t pad1B; std::uint32_t pad1C; };
class BSTArrayHeapAllocator { public: void* _data; std::uint32_t _capacity; };
class BSTArrayBase { public: std::uint32_t _size; };
template <class T> class BSTArray : public BSTArrayHeapAllocator, public BSTArrayBase {};
class TESCondition { public: TESConditionItem* head; };
class BGSScene : public TESForm { public:
    void Function3a8a70(); BGSScene* GetScene();
    BSTArray<BGSScenePhase*> phases; BSTArray<std::uint32_t> actors; BSTArray<std::uint32_t> actorFlags; BSTArray<std::uint32_t> actorProgressionFlags; BSTArray<BGSSceneAction*> actions;
    TESQuest* parentQuest; std::uint32_t flags; std::uint32_t padA4; TESCondition conditions; bool isPlaying; std::uint8_t unkB1; std::uint8_t unkB2; std::uint8_t unkB3;
};
