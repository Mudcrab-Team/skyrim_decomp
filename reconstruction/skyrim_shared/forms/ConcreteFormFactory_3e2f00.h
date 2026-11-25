// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and published community declarations).
// Factory types and template arguments: EXE_RTTI
// Destructor slot and size: OBSERVED
// Virtual declarations and _name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnregisterFormFactory and integral argument types: GUESS(low) STANDIN
// Code origin: original form-factory destructor template. Adapted bodies: none.
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include "ConcreteFormFactory.h"

class BGSStoryManagerBranchNode;
class BGSStoryManagerEventNode;
class BGSStoryManagerQuestNode;
class NavMesh;
class TESRace;
class TESTopic;
class TESTopicInfo;

extern template class ConcreteFormFactory<TESRace, 14>;
extern template class ConcreteFormFactory<TESTopic, 75>;
extern template class ConcreteFormFactory<TESTopicInfo, 76>;
extern template class ConcreteFormFactory<NavMesh, 73>;
extern template class ConcreteFormFactory<BGSStoryManagerBranchNode, 112>;
extern template class ConcreteFormFactory<BGSStoryManagerEventNode, 114>;
extern template class ConcreteFormFactory<BGSStoryManagerQuestNode, 113>;
