// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and published community declarations).
// Factory types and template arguments: EXE_RTTI
// Destructor slot and size: OBSERVED
// Virtual declarations and _name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnregisterFormFactory and integral argument types: GUESS(low) STANDIN
// Code origin: original form-factory destructor template. Adapted bodies: none.
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include "ConcreteObjectFormFactory.h"

class BGSKeyword;
class BGSMovementType;
class BGSNote;
class BGSPerk;
class BGSRagdoll;
class BGSRelationship;
class BGSStoryManagerEventNode;
class BGSVoiceType;
class TESClass;
class TESEyes;
class TESFaction;
class TESNPC;
class TESQuest;
class TESRace;

extern template class ConcreteObjectFormFactory<BGSKeyword, 4, 70, 4>;
extern template class ConcreteObjectFormFactory<BGSMovementType, 127, 91, 5>;
extern template class ConcreteObjectFormFactory<BGSNote, 48, 54, 9>;
extern template class ConcreteObjectFormFactory<BGSPerk, 92, 39, 0>;
extern template class ConcreteObjectFormFactory<BGSRagdoll, 106, 65, 9>;
extern template class ConcreteObjectFormFactory<BGSRelationship, 121, 80, 5>;
extern template class ConcreteObjectFormFactory<BGSVoiceType, 98, 48, 5>;
extern template class ConcreteObjectFormFactory<TESClass, 10, 49, 5>;
extern template class ConcreteObjectFormFactory<TESEyes, 13, 51, 9>;
extern template class ConcreteObjectFormFactory<TESFaction, 11, 53, 5>;
extern template class ConcreteObjectFormFactory<TESNPC, 43, 13, 0>;
extern template class ConcreteObjectFormFactory<TESQuest, 77, 46, 5>;
extern template class ConcreteObjectFormFactory<TESRace, 14, 50, 5>;
extern template class ConcreteObjectFormFactory<BGSStoryManagerEventNode, 114, 93, 5>;
