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

class AlchemyItem;
class BGSDualCastData;
class EffectSetting;
class EnchantmentItem;
class IngredientItem;
class ScrollItem;
class SpellItem;
class TESRegion;
class BGSAddonNode;
class BGSApparatus;
class BGSArtObject;
class BGSConstructibleObject;
class BGSDebris;
class BGSExplosion;
class BGSHazard;
class BGSLensFlare;
class BGSVolumetricLighting;
class BGSMovableStatic;
class BGSOutfit;
class BGSProjectile;
class BGSStaticCollection;
class BGSTalkingActivator;
class TESAmmo;
class TESCombatStyle;
class TESEffectShader;
class TESFlora;
class TESFurniture;
class TESGrass;
class TESKey;
class TESLevCharacter;
class TESLevItem;
class TESLevSpell;
class TESObjectLIGH;
class TESObjectACTI;
class TESObjectANIO;
class TESObjectARMA;
class TESObjectARMO;
class TESObjectBOOK;
class TESObjectCONT;
class TESObjectDOOR;
class TESObjectMISC;
class TESObjectSTAT;
class TESObjectTREE;
class TESObjectWEAP;
class TESSoulGem;
class BGSEncounterZone;
class BGSLightingTemplate;
class BGSLocation;
class BGSLocationRefType;
class BGSReferenceEffect;

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
