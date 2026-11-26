// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and published community declarations).
// Factory types and template arguments: EXE_RTTI
// Plain destructor entry and size: OBSERVED
// IFormFactory, ConcreteFormFactory, CreateImpl, GetFormName, GetFormType, GetObjectName, GetObjectType, GetObjectCategory, _name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnregisterFormFactory and integral argument types: GUESS(low) STANDIN
// Code origin: original form-factory destructor template. Adapted bodies: none.
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
// CI hash: 0x3aa480 ??1?$ConcreteFormFactory@VBGSScene@@$0HK@@@UEAA@XZ
// CI hash: 0x3aed70 ??1?$ConcreteFormFactory@VBGSVoiceType@@$0GC@@@UEAA@XZ
// CI hash: 0x3b2bc0 ??1?$ConcreteFormFactory@VTESClass@@$09@@UEAA@XZ
// CI hash: 0x3b3260 ??1?$ConcreteFormFactory@VTESEyes@@$0N@@@UEAA@XZ
// CI hash: 0x3b6140 ??1?$ConcreteFormFactory@VTESFaction@@$0L@@@UEAA@XZ
// CI hash: 0x3b81c0 ??1?$ConcreteFormFactory@VTESIdleForm@@$0EO@@@UEAA@XZ
// CI hash: 0x3cb600 ??1?$ConcreteFormFactory@VTESNPC@@$0CL@@@UEAA@XZ
// CI hash: 0x3de780 ??1?$ConcreteFormFactory@VTESQuest@@$0EN@@@UEAA@XZ
// CI hash: 0x3eb5f0 ??1?$ConcreteFormFactory@VTESRace@@$0O@@@UEAA@XZ
// CI hash: 0x3f0840 ??1?$ConcreteFormFactory@VTESTopic@@$0EL@@@UEAA@XZ
// CI hash: 0x3f4460 ??1?$ConcreteFormFactory@VTESTopicInfo@@$0EM@@@UEAA@XZ
// CI hash: 0x4c0110 ??1?$ConcreteFormFactory@VNavMesh@@$0EJ@@@UEAA@XZ
// CI hash: 0x535a60 ??1?$ConcreteFormFactory@VBGSStoryManagerBranchNode@@$0HA@@@UEAA@XZ
// CI hash: 0x535fe0 ??1?$ConcreteFormFactory@VBGSStoryManagerEventNode@@$0HC@@@UEAA@XZ
// CI hash: 0x5397b0 ??1?$ConcreteFormFactory@VBGSStoryManagerQuestNode@@$0HB@@@UEAA@XZ
// 0x3aa480 ConcreteFormFactory<BGSScene, 122>::~ConcreteFormFactory
// 0x3aed70 ConcreteFormFactory<BGSVoiceType, 98>::~ConcreteFormFactory
// 0x3b2bc0 ConcreteFormFactory<TESClass, 10>::~ConcreteFormFactory
// 0x3b3260 ConcreteFormFactory<TESEyes, 13>::~ConcreteFormFactory
// 0x3b6140 ConcreteFormFactory<TESFaction, 11>::~ConcreteFormFactory
// 0x3b81c0 ConcreteFormFactory<TESIdleForm, 78>::~ConcreteFormFactory
// 0x3cb600 ConcreteFormFactory<TESNPC, 43>::~ConcreteFormFactory
// 0x3de780 ConcreteFormFactory<TESQuest, 77>::~ConcreteFormFactory
// 0x3eb5f0 ConcreteFormFactory<TESRace, 14>::~ConcreteFormFactory
// 0x3f0840 ConcreteFormFactory<TESTopic, 75>::~ConcreteFormFactory
// 0x3f4460 ConcreteFormFactory<TESTopicInfo, 76>::~ConcreteFormFactory
// 0x4c0110 ConcreteFormFactory<NavMesh, 73>::~ConcreteFormFactory
// 0x535a60 ConcreteFormFactory<BGSStoryManagerBranchNode, 112>::~ConcreteFormFactory
// 0x535fe0 ConcreteFormFactory<BGSStoryManagerEventNode, 114>::~ConcreteFormFactory
// 0x5397b0 ConcreteFormFactory<BGSStoryManagerQuestNode, 113>::~ConcreteFormFactory
#include "ConcreteFormFactory_3aa480.h"

// These entries are plain destructors (??1), not deleting wrappers (??_G).
// PDB note: community ctor annotations conflict with the destructor table transitions and type-unregistration call.
// The compiler emits the complete destructor and exception cleanup from the approved factory template.

template class ConcreteFormFactory<BGSScene, 122>;
template class ConcreteFormFactory<BGSVoiceType, 98>;
template class ConcreteFormFactory<TESClass, 10>;
template class ConcreteFormFactory<TESEyes, 13>;
template class ConcreteFormFactory<TESFaction, 11>;
template class ConcreteFormFactory<TESIdleForm, 78>;
template class ConcreteFormFactory<TESNPC, 43>;
template class ConcreteFormFactory<TESQuest, 77>;
template class ConcreteFormFactory<TESRace, 14>;
template class ConcreteFormFactory<TESTopic, 75>;
template class ConcreteFormFactory<TESTopicInfo, 76>;
template class ConcreteFormFactory<NavMesh, 73>;
template class ConcreteFormFactory<BGSStoryManagerBranchNode, 112>;
template class ConcreteFormFactory<BGSStoryManagerEventNode, 114>;
template class ConcreteFormFactory<BGSStoryManagerQuestNode, 113>;
