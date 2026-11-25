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

class BGSAcousticSpace;
class BGSAction;
class BGSAssociationType;
class BGSBodyPartData;
class BGSCameraShot;
class BGSCollisionLayer;
class BGSColorForm;
class BGSEncounterZone;
class BGSEquipSlot;
class BGSFootstep;
class BGSFootstepSet;
class BGSHeadPart;
class BGSIdleMarker;
class BGSImpactData;
class BGSImpactDataSet;
class BGSLightingTemplate;
class BGSListForm;
class BGSMaterialObject;
class BGSMaterialType;
class BGSMenuIcon;
class BGSMessage;
class BGSMusicTrackFormWrapper;
class BGSMusicType;
class BGSReverbParameters;
class BGSSoundCategory;
class BGSSoundDescriptorForm;
class BGSSoundOutput;
class BGSTextureSet;
class Script;
class TESGlobal;
class TESLoadScreen;
class TESObjectSTAT;
class TESObjectTREE;
class TESObjectWEAP;
class TESShout;
class TESSoulGem;
class TESSound;
class TESWaterForm;
class TESWeather;
class TESWordOfPower;

extern template class ConcreteObjectFormFactory<TESObjectSTAT, 34, 8, 3>;
extern template class ConcreteObjectFormFactory<TESObjectTREE, 38, 10, 3>;
extern template class ConcreteObjectFormFactory<TESObjectWEAP, 41, 12, 1>;
extern template class ConcreteObjectFormFactory<TESSoulGem, 52, 97, 1>;
extern template class ConcreteObjectFormFactory<BGSEncounterZone, 103, 61, 7>;
extern template class ConcreteObjectFormFactory<BGSLightingTemplate, 108, 87, 7>;
extern template class ConcreteObjectFormFactory<TESWaterForm, 84, 29, 7>;
extern template class ConcreteObjectFormFactory<TESWeather, 54, 55, 7>;
extern template class ConcreteObjectFormFactory<BGSAcousticSpace, 16, 64, 8>;
extern template class ConcreteObjectFormFactory<BGSCameraShot, 96, 43, 6>;
extern template class ConcreteObjectFormFactory<BGSCollisionLayer, 132, 99, 4>;
extern template class ConcreteObjectFormFactory<BGSColorForm, 133, 101, 4>;
extern template class ConcreteObjectFormFactory<BGSFootstep, 110, 73, 6>;
extern template class ConcreteObjectFormFactory<BGSFootstepSet, 111, 74, 6>;
extern template class ConcreteObjectFormFactory<BGSImpactData, 100, 44, 6>;
extern template class ConcreteObjectFormFactory<BGSImpactDataSet, 101, 45, 6>;
extern template class ConcreteObjectFormFactory<BGSListForm, 91, 38, 4>;
extern template class ConcreteObjectFormFactory<BGSMaterialObject, 126, 85, 4>;
extern template class ConcreteObjectFormFactory<BGSMaterialType, 99, 75, 6>;
extern template class ConcreteObjectFormFactory<BGSMenuIcon, 8, 37, 9>;
extern template class ConcreteObjectFormFactory<BGSMessage, 105, 62, 4>;
extern template class ConcreteObjectFormFactory<BGSMusicTrackFormWrapper, 116, 77, 8>;
extern template class ConcreteObjectFormFactory<BGSMusicType, 109, 68, 8>;
extern template class ConcreteObjectFormFactory<BGSReverbParameters, 134, 102, 8>;
extern template class ConcreteObjectFormFactory<BGSSoundCategory, 130, 96, 8>;
extern template class ConcreteObjectFormFactory<BGSSoundDescriptorForm, 128, 94, 8>;
extern template class ConcreteObjectFormFactory<BGSSoundOutput, 131, 98, 8>;
extern template class ConcreteObjectFormFactory<BGSTextureSet, 7, 35, 4>;
extern template class ConcreteObjectFormFactory<TESGlobal, 9, 58, 4>;
extern template class ConcreteObjectFormFactory<TESLoadScreen, 81, 26, 4>;
extern template class ConcreteObjectFormFactory<Script, 19, 66, 9>;
extern template class ConcreteObjectFormFactory<TESShout, 119, 79, 2>;
extern template class ConcreteObjectFormFactory<TESSound, 15, 23, 8>;
extern template class ConcreteObjectFormFactory<TESWordOfPower, 118, 78, 2>;
extern template class ConcreteObjectFormFactory<BGSAction, 6, 76, 0>;
extern template class ConcreteObjectFormFactory<BGSAssociationType, 123, 82, 5>;
extern template class ConcreteObjectFormFactory<BGSBodyPartData, 93, 40, 0>;
extern template class ConcreteObjectFormFactory<BGSEquipSlot, 120, 81, 5>;
extern template class ConcreteObjectFormFactory<BGSHeadPart, 12, 52, 5>;
extern template class ConcreteObjectFormFactory<BGSIdleMarker, 47, 30, 4>;
