// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (pinned image and published community declarations).
// Factory types and template arguments: EXE_RTTI
// Plain destructor entry and size: OBSERVED
// IFormFactory, ConcreteFormFactory, CreateImpl, GetFormName, GetFormType, GetObjectName, GetObjectType, GetObjectCategory, _name: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// UnregisterFormFactory and integral argument types: GUESS(low) STANDIN
// Code origin: original form-factory destructor template. Adapted bodies: none.
// Boundary source: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once
#include "IFormFactory.h"

class BGSShaderParticleGeometryData;
class TESClimate;
class TESImageSpace;
class TESImageSpaceModifier;
class TESObjectLAND;
class TESLandTexture;
class TESObjectCELL;
class TESWaterForm;
class TESWeather;
class TESWorldSpace;
class BGSAcousticSpace;
class BGSCameraPath;
class BGSCameraShot;
class BGSCollisionLayer;
class BGSColorForm;
class BGSFootstep;
class BGSFootstepSet;
class BGSImpactData;
class BGSImpactDataSet;
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
class TESGlobal;
class TESLoadScreen;
class Script;
class TESShout;
class TESSound;
class TESWordOfPower;
class BGSAction;
class BGSAssociationType;
class BGSBodyPartData;
class BGSDialogueBranch;
class BGSEquipSlot;
class BGSHeadPart;
class BGSIdleMarker;
class BGSKeyword;
class BGSMovementType;
class BGSNote;
class BGSPerk;
class BGSRagdoll;
class BGSRelationship;

template<class T, unsigned char FormType>
class ConcreteFormFactory : public IFormFactory
{
public:
    ~ConcreteFormFactory() override { UnregisterFormFactory(FormType); }
    TESForm* CreateImpl() override;
    const char* GetFormName() const override;
    unsigned char GetFormType() const override;

protected:
    const char* _name;
};
