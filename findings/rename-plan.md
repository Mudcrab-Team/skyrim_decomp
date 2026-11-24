# Finding: CrashLogger and 2013-map names for matched functions that carry a guess

Status: HYPOTHESIS
Author / human operator: awarebayes
AI assistance / model: Claude Code (claude-sonnet-5-5), run locally on the operator's machine
Date (UTC): 2026-11-24
Target build id / image SHA-256: `sse-steam-1-7-104` /
`846efccf0c1374d71f892907f46549560f2fcb0a75cb87a3eed438baa0f1402f`
Function RVA / size (if applicable): not applicable (per-row table below)
Source exposure: mixed (this repository's tracked CrashLogger tables and unit sources; the 2013 linker map
held by the operator, read locally; the model saw class and member names, no code, no bytes and no address)
Sources and immutable revisions / licenses: `reconstruction/generated/crashlogger_pdb` (59818@2026.10.24);
the linker map identified by SHA-256 `fed7f0b964ea752f-e677f4c413c37c97-b5cad21541755c69-c701a66423b288b2` (grouped); no licence grant
Name provenance: CRASHLOGGER_PDB, SYMBOLS(tesv-2013-map)
Confidence: high for the counts; low to medium for any single name as a name in the pinned image

## Question and method

Which matched functions that still carry a guessed name can take the CrashLogger community name at their RVA,
with that name's class and member also present in the 2013 map? `tools/rename_planner.py plan` joined the
inventory, the CrashLogger names, boundaries and prototypes, the unit's own header lines and the map's
class and member membership (a static, local analysis; the map reader returns booleans and fold-group sizes,
never an address). Each row got one verdict, and the first failing conflict check decides an ambiguous row.

## Result

- matched GUESS entries with a CrashLogger name: 7798
- class and member present in the map: 390 (288 with a prototype)
- verdicts: ambiguous 224, label-source 18, rename 7, sync-inventory 141
- `rename` rows change a placeholder method name in the unit's own files; `label-source` rows add the labels to a
  name the unit already uses; `sync-inventory` rows only update the inventory name, origin and source.

## Ambiguous rows by reason

- `alias-or-overload`: 26
- `generated-family`: 112
- `namespace-differs`: 7
- `no-class-claim`: 3
- `no-source-name`: 24
- `ownership-conflict`: 16
- `placeholder-name`: 3
- `prototype-arity`: 17
- `source-name-differs`: 7
- `this-differs`: 9

## Limitations

- Class and member membership is not overload or signature identity, and the map is another build; a name
  from either table is a community hypothesis, never evidence of identity. A byte match is the only acceptance.
- Folded bodies carry the name of one of their original owners; `generated-family`, `this-differs` and
  `alias-or-overload` rows are the visible cases and every one is left unnamed here.
- The prototype checks use the CrashLogger signature only to refuse a rename; no signature is adopted.
- A negative result here (ambiguous) says the name was not adopted, not that it is wrong.

## Ambiguous rows

| RVA | unit | name in unit | CrashLogger name | reason |
|---|---|---|---|---|
| `0xc3e80` | `unmapped/static/Staticc3e80` | `Staticc3e80::initializer` | `TESShout::Load` | `generated-family` |
| `0xc43b0` | `unmapped/static/Staticc43b0` | `Staticc43b0::initializer` | `TESShout::GetKnown` | `generated-family` |
| `0xc60f0` | `unmapped/static/StringStaticc60f0` | `StringStaticc60f0::initializer` | `TESSound::InitializeData` | `generated-family` |
| `0xc61b0` | `unmapped/static/StringStaticc61b0` | `StringStaticc61b0::initializer` | `TESSound::Load` | `generated-family` |
| `0xc6c60` | `unmapped/static/StringStaticc6c60` | `StringStaticc6c60::initializer` | `TESSound::GetFormEditorID` | `generated-family` |
| `0xc6ce0` | `unmapped/static/StringStaticc6ce0` | `StringStaticc6ce0::initializer` | `TESSound::SetFormEditorID` | `generated-family` |
| `0xc6fd0` | `unmapped/static/StringStaticc6fd0` | `StringStaticc6fd0::initializer` | `TESSound::Clone3D` | `generated-family` |
| `0xc7050` | `unmapped/static/StringStaticc7050` | `StringStaticc7050::initializer` | `TESSound::UnClone3D` | `generated-family` |
| `0xc8430` | `unmapped/static/StringStaticc8430` | `StringStaticc8430::initializer` | `TESWordOfPower::Load` | `generated-family` |
| `0xcc760` | `leaves/ClassDescriptorInitializers1` | `ClassDescriptorInitializers1::Initcc760` | `BGSAssociationType::Load` | `this-differs` |
| `0xd2820` | `leaves/ClassDescriptorInitializers4` | `ClassDescriptorInitializers4::Initd2820` | `BGSBodyPartData::ClearData` | `this-differs` |
| `0xd2910` | `unmapped/static/TypeInfoDescriptorInitializers3` | `TypeInfoDescriptorInitializers3::Initd2910` | `BGSBodyPartData::Load` | `alias-or-overload` |
| `0xd6270` | `leaves/ClassDescriptorInitializers6` | `ClassDescriptorInitializers6::Initd6270` | `BGSDialogueBranch::Load` | `alias-or-overload` |
| `0xd63b0` | `leaves/ClassDescriptorInitializers6` | `ClassDescriptorInitializers6::Initd63b0` | `BGSDialogueBranch::ClearData` | `alias-or-overload` |
| `0xdcfa0` | `leaves/ClassDescriptorInitializers9` | `ClassDescriptorInitializers9::Initdcfa0` | `BGSEntryPointFunctionDataSpellItem::InitItem` | `alias-or-overload` |
| `0xe17d0` | `leaves/ClassDescriptorInitializers11` | `ClassDescriptorInitializers11::Inite17d0` | `BGSEntryPointFunctionData::GetID` | `alias-or-overload` |
| `0xe18b0` | `leaves/ClassDescriptorInitializers11` | `ClassDescriptorInitializers11::Inite18b0` | `BGSEntryPointFunctionData::GetParentPerk` | `alias-or-overload` |
| `0xe1980` | `leaves/ClassDescriptorInitializers11` | `ClassDescriptorInitializers11::Inite1980` | `BGSEntryPointFunctionDataOneValue::GetType` | `alias-or-overload` |
| `0xe1cd0` | `leaves/ClassDescriptorInitializers11` | `ClassDescriptorInitializers11::Inite1cd0` | `BGSEntryPointFunctionDataText::GetType` | `alias-or-overload` |
| `0xe2000` | `leaves/ClassDescriptorInitializers11` | `ClassDescriptorInitializers11::Inite2000` | `BGSEntryPointFunctionDataActivateChoice::SetParentPerk` | `alias-or-overload` |
| `0xe2530` | `leaves/ClassDescriptorInitializers12` | `ClassDescriptorInitializers12::Inite2530` | `BGSEntryPointFunctionDataSpellItem::InitItem` | `alias-or-overload` |
| `0xe35b0` | `leaves/ClassDescriptorInitializers12` | `ClassDescriptorInitializers12::Inite35b0` | `BGSEntryPointFunctionDataActivateChoice::GetType` | `alias-or-overload` |
| `0xe3680` | `leaves/ClassDescriptorInitializers12` | `ClassDescriptorInitializers12::Inite3680` | `BGSEntryPointFunctionDataActivateChoice::InitItem` | `this-differs` |
| `0xe4c00` | `unmapped/static/Statice4c00` | `Statice4c00::initializer` | `BGSEquipSlot::Load` | `generated-family` |
| `0xe8ff0` | `unmapped/static/Statice8ff0` | `Statice8ff0::initializer` | `BGSIdleMarker::UnClone3D` | `generated-family` |
| `0xebea0` | `unmapped/static/Staticebea0` | `Staticebea0::initializer` | `BGSKeyword::SetFormEditorID` | `generated-family` |
| `0xebf20` | `unmapped/static/Staticebf20` | `Staticebf20::initializer` | `BGSKeyword::GetFormEditorID` | `generated-family` |
| `0xf1360` | `unmapped/static/Staticf1360` | `Staticf1360::initializer` | `BGSNote::Load` | `generated-family` |
| `0xf13e0` | `unmapped/static/Staticf13e0` | `Staticf13e0::initializer` | `BGSNote::ClearData` | `generated-family` |
| `0xf1560` | `unmapped/static/Staticf1560` | `Staticf1560::initializer` | `BGSNote::InitializeData` | `generated-family` |
| `0xf1840` | `unmapped/static/Staticf1840` | `Staticf1840::initializer` | `BGSNote::LoadGame` | `generated-family` |
| `0xf2990` | `unmapped/static/Staticf2990` | `Staticf2990::initializer` | `BGSNote::Activate` | `generated-family` |
| `0x100d80` | `unmapped/static/Static100d80` | `Static100d80::initializer` | `BGSRagdoll::Load` | `generated-family` |
| `0x100e40` | `unmapped/static/Static100e40` | `Static100e40::initializer` | `BGSRagdoll::ClearData` | `generated-family` |
| `0x100f30` | `unmapped/static/Static100f30` | `Static100f30::initializer` | `BGSRagdoll::InitializeData` | `generated-family` |
| `0x103820` | `unmapped/static/Static103820` | `Static103820::initializer` | `BGSRefAlias::Load` | `generated-family` |
| `0x103890` | `unmapped/static/Static103890` | `Static103890::initializer` | `BGSRefAlias::QType` | `generated-family` |
| `0x103900` | `unmapped/static/Static103900` | `Static103900::initializer` | `BGSRefAlias::InitItem` | `generated-family` |
| `0x106fb0` | `unmapped/static/Static106fb0` | `Static106fb0::initializer` | `BGSRelationship::SaveGame` | `generated-family` |
| `0x107110` | `unmapped/static/Static107110` | `Static107110::initializer` | `BGSRelationship::InitializeData` | `generated-family` |
| `0x107190` | `unmapped/static/Static107190` | `Static107190::initializer` | `BGSRelationship::Load` | `generated-family` |
| `0x107210` | `unmapped/static/Static107210` | `Static107210::initializer` | `BGSRelationship::LoadGame` | `generated-family` |
| `0x107290` | `unmapped/static/Static107290` | `Static107290::initializer` | `BGSRelationship::InitLoadGame` | `generated-family` |
| `0x14e7f0` | `skyrim_shared/magic/MagicItem_14e7f0` | `MagicItem::IsValidEnchantmentForWeapon` | `EnchantmentItem::IsValidEnchantmentForWeapon` | `ownership-conflict` |
| `0x17c3a0` | `unmapped/leaves/DeletingLeaf17c3a0` | `DeletingLeaf17c3a0::~DeletingLeaf17c3a0` | `TESTopicInfo::BelongsInGroup` | `generated-family` |
| `0x17cb90` | `skyrim_shared/extradata/ExtraGlobalStorageLayout` | `DeletingLeaf17cb90::~DeletingLeaf17cb90` | `TESTopicInfo::InitializeData` | `generated-family` |
| `0x17ee20` | `unmapped/storage/FieldRecoveryStorageLayout` | `represented typed field operation` | `NonActorMagicTarget::GetTargetStatsObject` | `no-source-name` |
| `0x180eb0` | `skyrim_shared/extradata/ExtraLock_180eb0` | `ExtraLock::~ExtraLock` | `ExtraLock::~ExtraLock` | `generated-family` |
| `0x181060` | `skyrim_shared/extradata/ExtraTeleport_181060` | `ExtraTeleport::~ExtraTeleport` | `ExtraTeleport::~ExtraTeleport` | `generated-family` |
| `0x1860c0` | `skyrim_shared/extradata/ExtraPatrolRefData_1860c0` | `ExtraPatrolRefData::~ExtraPatrolRefData` | `ExtraPatrolRefData::~ExtraPatrolRefData` | `generated-family` |
| `0x1863d0` | `skyrim_shared/extradata/ExtraPortalRefData_1863d0` | `ExtraPortalRefData::~ExtraPortalRefData` | `ExtraPortalRefData::~ExtraPortalRefData` | `generated-family` |
| `0x1865e0` | `skyrim_shared/extradata/ExtraPackageData_1865e0` | `ExtraPackageData::~ExtraPackageData` | `ExtraPackageData::~ExtraPackageData` | `generated-family` |
| `0x186630` | `skyrim_shared/extradata/ExtraCollisionData_186630` | `ExtraCollisionData::~ExtraCollisionData` | `ExtraCollisionData::~ExtraCollisionData` | `generated-family` |
| `0x1a6f80` | `bsmain/TES_1a6f80` | `TES::ResolveCellQueryNode` | `TES::Pick` | `source-name-differs` |
| `0x226c40` | `skyrim_shared/world/GridCellArray_226c40` | `GridCellArray::ResetCenter` | `GridArray::Init` | `this-differs` |
| `0x266090` | `skyrim_shared/refs/BGSProjectile` | `Function266090` | `BGSProjectile::GetRelaunchInterval` | `prototype-arity` |
| `0x29b350` | `skyrim_shared/refs/TESObjectREFR_29b350` | `FindNodeValue` | `BGSLocation::GetUnreportedCrimeFactionForRef` | `prototype-arity` |
| `0x2b2600` | `skyrim_shared/world/TESObjectLAND_2b2600` | `ReconstructedTESObjectLAND::TESObjectLAND::Function2b2600` | `TESObjectLAND::IsLoaded` | `namespace-differs` |
| `0x2e6ab0` | `skyrim_shared/actors/SceneActor` | `P2071::SceneActor::UpdateScene` | `TESObjectREFR::SetCurrentSceneActionComplete` | `prototype-arity` |
| `0x2fa140` | `unmapped/leaves/LeafAddress2fa140` | `LeafAddress2fa140::Address` | `TESObjectREFR::SetOwner` | `generated-family` |
| `0x2fcb40` | `skyrim_shared/refs/TESObjectREFR_2fcb40` | `PrepareUpdate` | `TESObjectREFR::SetupAnimationUpdateDataForReference` | `prototype-arity` |
| `0x3202d0` | `skyrim_shared/forms/BGSListForm` | `BGSListForm::Function3202d0` | `BGSListForm::GetItemAtFormListIndex` | `prototype-arity` |
| `0x390a20` | `skyrim_shared/actors/BGSHeadPart_390a20` | `BGSHeadPart::sub` | `BGSHeadPart::GetIsValidForRace` | `source-name-differs` |
| `0x3ac550` | `skyrim_shared/quest/BGSSceneActionPackage_3ac550` | `BGSSceneActionPackage::LoadBuffer` | `BGSSceneActionPackage::LoadGame` | `this-differs` |
| `0x3cdee0` | `unmapped/leaves/RelayLeaf3cdee0` | `RelayLeaf3cdee0::Relay` | `TESQuest::ForceRefIntoAlias` | `alias-or-overload` |
| `0x3e82c0` | `skyrim_shared/actors/TESRace_3e82c0` | `ReconstructedTESRace::TESRace::Function3e82c0` | `TESRace::QCanUseWeaponType` | `alias-or-overload` |
| `0x3f2e60` | `skyrim_shared/dialogue/TESTopicInfo_3f2e60` | `ReconstructedTESTopicInfo::TESTopicInfo::Function3f2e60` | `TESTopicInfo::ResetSaidOnceFlags` | `namespace-differs` |
| `0x4726a0` | `unmapped/leaves/CommunityLeafStorageLayout` | `DeletingLeaf4726a0::~DeletingLeaf4726a0` | `CombatMagicCasterOffensive::CheckStopCast` | `no-source-name` |
| `0x4745f0` | `unmapped/leaves/DeletingLeaf4745f0` | `DeletingLeaf4745f0::~DeletingLeaf4745f0` | `CombatMagicCasterLight::CheckStartCast` | `generated-family` |
| `0x474660` | `unmapped/leaves/DeletingLeaf474660` | `DeletingLeaf474660::~DeletingLeaf474660` | `CombatMagicCasterLight::GetObjectType` | `generated-family` |
| `0x4a6e20` | `skyrim_shared/conditions/TESCondition` | `TESCondition::IsTrue` | `TESCondition::IsTrue` | `no-source-name` |
| `0x553560` | `gamebryo/nianimation/IAnimationGraphManagerHolder_553560` | `IAnimationGraphManagerHolder::SetGraphVariableBool` | `IAnimationGraphManagerHolder::SetGraphVariable` | `alias-or-overload` |
| `0x553580` | `gamebryo/nianimation/IAnimationGraphManagerHolder_553560` | `IAnimationGraphManagerHolder::SetGraphVariableInt` | `IAnimationGraphManagerHolder::SetGraphVariable` | `no-source-name` |
| `0x5535a0` | `gamebryo/nianimation/IAnimationGraphManagerHolder_553560` | `IAnimationGraphManagerHolder::SetGraphVariableFloat` | `IAnimationGraphManagerHolder::SetGraphVariable` | `no-source-name` |
| `0x5bad70` | `skyrim/magic/ActiveEffect_5bad70` | `ActiveEffect::ShouldApply` | `ActiveEffect::CheckTargetActorsOnly` | `prototype-arity` |
| `0x5bcba0` | `skyrim/magic/ValueModifierEffect` | `ValueModifierEffect::Function5bcba0` | `ActiveEffect::SetExplosionLocation` | `prototype-arity` |
| `0x5d0d60` | `skyrim_shared/magic/MagicTarget_5d0d60` | `MagicTarget::~MagicTarget` | `MagicTarget::~MagicTarget` | `generated-family` |
| `0x5d2ec0` | `unmapped/leaves/Leaf5d2ec0` | `Leaf5d2ec0::Invoke` | `MagicTarget::InvalidateCommandedActorEffect` | `generated-family` |
| `0x5d2fc0` | `unmapped/leaves/Leaf5d2fc0` | `Leaf5d2fc0::Invoke` | `MagicTarget::EffectAdded` | `generated-family` |
| `0x5d2fd0` | `unmapped/leaves/Leaf5d2fd0` | `Leaf5d2fd0::Invoke` | `MagicTarget::EffectRemoved` | `generated-family` |
| `0x5d2fe0` | `skyrim_shared/magic/MagicTarget_5d2fe0` | `MagicTarget::CheckResistance` | `MagicTarget::CheckResistance` | `alias-or-overload` |
| `0x5d2ff0` | `unmapped/leaves/ReturnLeaf5d2ff0` | `ReturnLeaf5d2ff0::Invoke` | `MagicTarget::CheckAbsorb` | `generated-family` |
| `0x5d98e0` | `unmapped/leaves/ReturnLeaf5d98e0` | `ReturnLeaf5d98e0::Invoke` | `NonActorMagicTarget::CanAddActiveEffect` | `generated-family` |
| `0x5d98f0` | `unmapped/storage/FieldRecoveryStorageLayout` | `represented typed field operation` | `NonActorMagicTarget::GetActiveEffectList` | `no-source-name` |
| `0x5dbe70` | `unmapped/leaves/TableStoreLeaf5dbe70` | `TableStoreLeaf5dbe70::~TableStoreLeaf5dbe70` | `ReferenceEffectController::~ReferenceEffectController` | `generated-family` |
| `0x66ec80` | `bscore/EventCaptureDeleteLayout` | `DeletingLeaf66ec80::~DeletingLeaf66ec80` | `IGiftMenuScriptCallback::~IGiftMenuScriptCallback` | `no-source-name` |
| `0x673ac0` | `skyrim_shared/actors/Character_673ac0` | `Character::SwimsOnly` | `Actor::SwimsOnly` | `ownership-conflict` |
| `0x673b60` | `skyrim_shared/actors/Character_673b60` | `Character::FightsInWater` | `Actor::FightsInWater` | `ownership-conflict` |
| `0x674000` | `skyrim_shared/actors/Character_674000` | `Character::GetEssential` | `Actor::GetEssential` | `prototype-arity` |
| `0x67d8c0` | `skyrim_shared/actors/Character_67d8c0` | `Character::ShouldSaveAnimationData` | `Actor::ShouldSaveAnimationData` | `ownership-conflict` |
| `0x67f580` | `skyrim_shared/actors/Character_67f580` | `Character::GetCurrentPackageTarget` | `Actor::GetCurrentPackageTarget` | `prototype-arity` |
| `0x685930` | `skyrim_shared/actors/Character_685930` | `Character::GetFlightRadius` | `Actor::GetFlightRadius` | `ownership-conflict` |
| `0x6a6a00` | `skyrim_shared/refs/ForwardTarget` | `P2071::ActorForwardPredicate` | `Actor::HasActivePath` | `prototype-arity` |
| `0x6a6c20` | `skyrim_shared/actors/Character_6a6c20` | `Character::GetLookAtTarget` | `Actor::GetLookAtTarget` | `prototype-arity` |
| `0x6be2e0` | `unmapped/leaves/ReturnLeaf6be2e0` | `ReturnLeaf6be2e0::Invoke` | `Actor::MagicTargetIsActor` | `generated-family` |
| `0x6c9870` | `skyrim/ai/combat/CombatActor` | `P2071::CombatActor::EngagingInCombat` | `Actor::IsInActiveCombat` | `ownership-conflict` |
| `0x6d6ad0` | `skyrim_shared/actors/Character_6d6ad0` | `Character::SetDualCasting` | `Actor::SetDualCasting` | `prototype-arity` |
| `0x6d6d00` | `skyrim_shared/actors/Actor_6d6d00` | `HasSelectedSpell` | `Actor::HasCastableSpell` | `prototype-arity` |
| `0x6e0fe0` | `unmapped/leaves/TableStoreLeaf6e0fe0` | `TableStoreLeaf6e0fe0::~TableStoreLeaf6e0fe0` | `ActorPackageData::~ActorPackageData` | `generated-family` |
| `0x74a6f0` | `skyrim/magic/ActiveEffect_74a6f0` | `ActiveEffect::AllowHitEffects` | `PlayerCharacter::AllowHitEffects` | `ownership-conflict` |
| `0x74e5c0` | `skyrim_shared/actors/PlayerCharacter_74e5c0` | `ProcessComponent` | `BSSegmentedTriShape::CopyMembers` | `this-differs` |
| `0x75ac10` | `skyrim_shared/actors/PlayerCharacter_75ac10` | `ScaledCrime` | `PlayerCharacter::CalculateDaysInJail` | `prototype-arity` |
| `0x77a070` | `unmapped/leaves/TableStoreLeaf77a070` | `TableStoreLeaf77a070::~TableStoreLeaf77a070` | `IMovementControllerNPCFunctor::~IMovementControllerNPCFunctor` | `generated-family` |
| `0x7e3530` | `unmapped/leaves/TableStoreLeaf7e3530` | `TableStoreLeaf7e3530::~TableStoreLeaf7e3530` | `IExplosionFactory::~IExplosionFactory` | `generated-family` |
| `0x85e2a0` | `unmapped/leaves/DeletingLeaf85e2a0` | `DeletingLeaf85e2a0::~DeletingLeaf85e2a0` | `CombatBehaviorThread::SetAborted` | `generated-family` |
| `0x8d7460` | `unmapped/leaves/ClassTypeLeaf8d7460` | `ClassTypeLeaf8d7460::QClassType` | `hkpShapeContainer::~hkpShapeContainer` | `placeholder-name` |
| `0xa2a7f0` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `BSAudio::GetReceiver` | `no-source-name` |
| `0xa2ef90` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `BSXAudio2GameSound::SetAttenuationCurve` | `no-source-name` |
| `0xa33860` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `AbstractHeap::GetMemoryStats` | `no-source-name` |
| `0xa55190` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiSwitchNode::AttachChild` | `no-source-name` |
| `0xa55350` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiPointLight::SaveBinary` | `no-source-name` |
| `0xa55390` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiStream::LoadHeader` | `no-source-name` |
| `0xa55690` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiTimeController::SetTarget` | `no-source-name` |
| `0xa55890` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiSkinInstance::RegisterStreamables` | `no-source-name` |
| `0xa559d0` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiSkinInstance::GetRTTI` | `no-source-name` |
| `0xa55c10` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiGeometryData::GetRTTI` | `no-source-name` |
| `0xa560d0` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiGeometryData::RegisterStreamables` | `no-source-name` |
| `0xa61610` | `skyrim/papyrus/NativeFunctionLayout` | `NativeFunctionLayout::~NativeFunctionLayout` | `NiGeometry::LoadBinary` | `no-source-name` |
| `0xbaf0e0` | `unmapped/leaves/TableStoreLeafbaf0e0` | `TableStoreLeafbaf0e0::~TableStoreLeafbaf0e0` | `BSLimbIKModifierCastInfo::~BSLimbIKModifierCastInfo` | `generated-family` |
| `0xbaf120` | `unmapped/leaves/TableStoreLeafbaf120` | `TableStoreLeafbaf120::~TableStoreLeafbaf120` | `BSILimbIKModifierSingleton::~BSILimbIKModifierSingleton` | `generated-family` |
| `0xbb1b90` | `unmapped/leaves/TableStoreLeafbb1b90` | `TableStoreLeafbb1b90::~TableStoreLeafbb1b90` | `BSIDirectAtModifierSingleton::~BSIDirectAtModifierSingleton` | `generated-family` |
| `0xbb1c00` | `unmapped/leaves/TableStoreLeafbb1c00` | `TableStoreLeafbb1c00::~TableStoreLeafbb1c00` | `BSIPassByTargetTriggerModifierSingleton::~BSIPassByTargetTriggerModifierSingleton` | `generated-family` |
| `0xbb1cb0` | `unmapped/leaves/TableStoreLeafbb1cb0` | `TableStoreLeafbb1cb0::~TableStoreLeafbb1cb0` | `BSIRagdollContactListenerModifierSingleton::~BSIRagdollContactListenerModifierSingleton` | `generated-family` |
| `0xbc1b00` | `unmapped/leaves/TableStoreLeafbc1b00` | `TableStoreLeafbc1b00::~TableStoreLeafbc1b00` | `IPostAnimationChannelUpdateFunctor::~IPostAnimationChannelUpdateFunctor` | `generated-family` |
| `0xcca620` | `bsaudio/BSAudioManager` | `BSAudioManager::QPlatformInstance` | `BSAudioManager::QPlatformInstance` | `alias-or-overload` |
| `0xcddda0` | `unmapped/support/MemoryManager_cddda0` | `f3m_0086b820::Task0905::MemoryManager::GetHeapForPhysicalPointer` | `MemoryManager::GetHeapForPhysicalPointer` | `namespace-differs` |
| `0xcde9c0` | `unmapped/leaves/TableStoreLeafcde9c0` | `TableStoreLeafcde9c0::~TableStoreLeafcde9c0` | `IMemoryManagerFile::~IMemoryManagerFile` | `generated-family` |
| `0xcebe10` | `unmapped/wrappers/TableTailCleanups` | `TableTailCleanups::Cleanupcebe10` | `IMemoryHeap::~IMemoryHeap` | `placeholder-name` |
| `0xe25560` | `unmapped/wrappers/HeapCleanupDeallocators3` | `HeapCleanupDeallocators3::Deletee25560` | `BSLightingShaderMaterialSnow::LoadBinary` | `alias-or-overload` |
| `0xebeb50` | `bssystem/BSFile_ebeb50` | `BSFile::~BSFile` | `BSFile::~BSFile` | `generated-family` |
| `0xec3ce0` | `unmapped/leaves/TableStoreLeafec3ce0` | `TableStoreLeafec3ce0::~TableStoreLeafec3ce0` | `BSTasklet::~BSTasklet` | `generated-family` |
| `0xec3d00` | `unmapped/leaves/TableStoreLeafec3d00` | `TableStoreLeafec3d00::~TableStoreLeafec3d00` | `BSTaskletData::~BSTaskletData` | `generated-family` |
| `0xeeb7a0` | `gamebryo/nimain/NiAVObject_eeb7a0` | `NiAVObject::GetController` | `NiObjectNET::GetController` | `prototype-arity` |
| `0xefa170` | `gamebryo/nimain/NiGeometryData_efa170` | `NiGeometryData::RegisterStreamables` | `NiGeometryData::RegisterStreamables` | `alias-or-overload` |
| `0xf07f70` | `unmapped/support/Partition_f07f70` | `f3m_0084d0b0::Partition::IsEqual` | `Partition::IsEqual` | `namespace-differs` |
| `0xf172f0` | `gamebryo/nimain/NiTriShapeData_f172f0` | `f3m_00845ee0::NiTriShapeData::IsEqual` | `NiTriShapeData::IsEqual` | `namespace-differs` |
| `0xfab6e0` | `unmapped/leaves/LeafAddressfab6e0` | `LeafAddressfab6e0::Address` | `GFxValue::ObjectInterface::GetElement` | `generated-family` |
| `0xfd8fa0` | `gamebryo/nimain/NiNode` | `BSTempNodeManager::~BSTempNodeManager` | `BSTempNodeManager::~BSTempNodeManager` | `generated-family` |
| `0xfe4f80` | `gamebryo/nimain/BSMultiBoundAABB_fe4f80` | `BSMultiBoundAABB::sub` | `BSMultiBoundShape::CopyMembers` | `this-differs` |
| `0xfe5250` | `gamebryo/nimain/BSMultiBoundAABB_fe5250` | `BSMultiBoundAABB::CopyMembers` | `BSMultiBoundSphere::CopyMembers` | `this-differs` |
| `0xfe8e40` | `gamebryo/nimain/BSOcclusionPlane_fe8e40` | `BSOcclusionPlane::GetFrustum` | `BSOcclusionPlane::GetFrustumPlanes` | `source-name-differs` |
| `0x1002480` | `gamebryo/nimain/BSMultiBoundAABB_1002480` | `BSMultiBoundAABB::CopyMembers` | `BSMultiBoundCapsule::CopyMembers` | `this-differs` |
| `0x1082e30` | `unmapped/support/Globals_1082e30` | `f3m_0090ac60::dtor_0090ac60::bhkShape::~bhkShape` | `bhkShape::~bhkShape` | `generated-family` |
| `0x1082fd0` | `skyrim_shared/forms/Globals_1082fd0` | `bhkEntity::~bhkEntity` | `bhkEntity::~bhkEntity` | `generated-family` |
| `0x1083220` | `unmapped/support/Globals_1083220` | `f3m_0090ac60::dtor_0090ac60::bhkPhantom::~bhkPhantom` | `bhkPhantom::~bhkPhantom` | `generated-family` |
| `0x10832a0` | `unmapped/support/Globals_10832a0` | `f3m_0090ac60::dtor_0090ac60::bhkAabbPhantom::~bhkAabbPhantom` | `bhkAabbPhantom::~bhkAabbPhantom` | `generated-family` |
| `0x1083b90` | `unmapped/support/Globals_1083b90` | `f3m_0090ac60::dtor_0090ac60::bhkSphereRepShape::~bhkSphereRepShape` | `bhkSphereRepShape::~bhkSphereRepShape` | `generated-family` |
| `0x1083bd0` | `unmapped/support/Globals_1083bd0` | `f3m_0090ac60::dtor_0090ac60::bhkConvexShape::~bhkConvexShape` | `bhkConvexShape::~bhkConvexShape` | `generated-family` |
| `0x10873b0` | `unmapped/support/Globals_10873b0` | `f3m_0090ac60::dtor_0090ac60::bhkShapePhantom::~bhkShapePhantom` | `bhkShapePhantom::~bhkShapePhantom` | `generated-family` |
| `0x1087820` | `unmapped/support/Globals_1087820` | `f3m_0090ac60::dtor_0090ac60::bhkSimpleShapePhantom::~bhkSimpleShapePhantom` | `bhkSimpleShapePhantom::~bhkSimpleShapePhantom` | `generated-family` |
| `0x10891e0` | `unmapped/support/Globals_10891e0` | `f3m_0090ac60::dtor_0090ac60::bhkBoxShape::~bhkBoxShape` | `bhkBoxShape::~bhkBoxShape` | `generated-family` |
| `0x1089970` | `unmapped/support/Globals_1089970` | `f3m_0090ac60::dtor_0090ac60::bhkSphereShape::~bhkSphereShape` | `bhkSphereShape::~bhkSphereShape` | `generated-family` |
| `0x108a0a0` | `unmapped/support/Globals_108a0a0` | `f3m_0090ac60::dtor_0090ac60::bhkBvTreeShape::~bhkBvTreeShape` | `bhkBvTreeShape::~bhkBvTreeShape` | `generated-family` |
| `0x108f840` | `unmapped/support/Globals_108f840` | `f3m_0090ac60::dtor_0090ac60::bhkLimitedHingeConstraint::~bhkLimitedHingeConstraint` | `bhkLimitedHingeConstraint::~bhkLimitedHingeConstraint` | `generated-family` |
| `0x1090bb0` | `unmapped/support/Globals_1090bb0` | `f3m_0090ac60::dtor_0090ac60::bhkUnaryAction::~bhkUnaryAction` | `bhkUnaryAction::~bhkUnaryAction` | `generated-family` |
| `0x1091830` | `unmapped/support/Globals_1091830` | `f3m_0090ac60::dtor_0090ac60::bhkConstraint::~bhkConstraint` | `bhkConstraint::~bhkConstraint` | `generated-family` |
| `0x1092c20` | `unmapped/support/Globals_1092c20` | `f3m_0090ac60::dtor_0090ac60::bhkPrismaticConstraint::~bhkPrismaticConstraint` | `bhkPrismaticConstraint::~bhkPrismaticConstraint` | `generated-family` |
| `0x1093160` | `unmapped/support/Globals_1093160` | `f3m_0090ac60::dtor_0090ac60::bhkAction::~bhkAction` | `bhkAction::~bhkAction` | `generated-family` |
| `0x1093430` | `unmapped/support/Globals_1093430` | `f3m_0090ac60::dtor_0090ac60::bhkTriSampledHeightFieldBvTreeShape::~bhkTriSampledHeightFieldBvTreeShape` | `bhkTriSampledHeightFieldBvTreeShape::~bhkTriSampledHeightFieldBvTreeShape` | `generated-family` |
| `0x109f160` | `unmapped/support/Globals_109f160` | `f3m_0090ac60::dtor_0090ac60::bhkMouseSpringAction::~bhkMouseSpringAction` | `bhkMouseSpringAction::~bhkMouseSpringAction` | `generated-family` |
| `0x109fe60` | `unmapped/support/Globals_109fe60` | `f3m_0090ac60::dtor_0090ac60::bhkHingeConstraint::~bhkHingeConstraint` | `bhkHingeConstraint::~bhkHingeConstraint` | `generated-family` |
| `0x10b4ac0` | `unmapped/support/Globals_10b4ac0` | `f3m_0090ac60::dtor_0090ac60::bhkListShape::~bhkListShape` | `bhkListShape::~bhkListShape` | `generated-family` |
| `0x10b5dd0` | `unmapped/support/Globals_10b5dd0` | `f3m_0090ac60::dtor_0090ac60::bhkBallAndSocketConstraint::~bhkBallAndSocketConstraint` | `bhkBallAndSocketConstraint::~bhkBallAndSocketConstraint` | `generated-family` |
| `0x10b9800` | `unmapped/support/Globals_10b9800` | `f3m_0090ac60::dtor_0090ac60::bhkRagdollConstraint::~bhkRagdollConstraint` | `bhkRagdollConstraint::~bhkRagdollConstraint` | `generated-family` |
| `0x10bac70` | `unmapped/support/Globals_10bac70` | `f3m_0090ac60::dtor_0090ac60::bhkStiffSpringConstraint::~bhkStiffSpringConstraint` | `bhkStiffSpringConstraint::~bhkStiffSpringConstraint` | `generated-family` |
| `0x10c3770` | `unmapped/support/Globals_10c3770` | `f3m_0090ac60::dtor_0090ac60::bhkGenericConstraint::~bhkGenericConstraint` | `bhkGenericConstraint::~bhkGenericConstraint` | `generated-family` |
| `0x10c9b50` | `unmapped/support/Globals_10c9b50` | `f3m_0090ac60::dtor_0090ac60::bhkShapeCollection::~bhkShapeCollection` | `bhkShapeCollection::~bhkShapeCollection` | `generated-family` |
| `0x10ec530` | `unmapped/support/Globals_10ec530` | `f3m_0090ac60::dtor_0090ac60::bhkHeightFieldShape::~bhkHeightFieldShape` | `bhkHeightFieldShape::~bhkHeightFieldShape` | `generated-family` |
| `0x10ece70` | `unmapped/support/Globals_10ece70` | `f3m_0090ac60::dtor_0090ac60::bhkConstraintChain::~bhkConstraintChain` | `bhkConstraintChain::~bhkConstraintChain` | `generated-family` |
| `0x10eda80` | `unmapped/support/Globals_10eda80` | `f3m_0090ac60::dtor_0090ac60::bhkBinaryAction::~bhkBinaryAction` | `bhkBinaryAction::~bhkBinaryAction` | `generated-family` |
| `0x1187dc0` | `unmapped/wrappers/HeapCleanupDeallocators3` | `HeapCleanupDeallocators3::Delete1187dc0` | `BSLightingShaderMaterialSnow::LoadBinary` | `alias-or-overload` |
| `0x11cc6c0` | `unmapped/wrappers/TableTailCleanups` | `TableTailCleanups::Cleanup11cc6c0` | `IMovementSelectIdle::~IMovementSelectIdle` | `placeholder-name` |
| `0x11e70c0` | `skyrim_shared/pathfinding/BSNavmesh` | `BSNavmesh::Function11e70c0` | `BSNavmesh::GetTrianglesForGridCell` | `prototype-arity` |
| `0x1204410` | `unmapped/leaves/TableStoreLeaf1204410` | `TableStoreLeaf1204410::~TableStoreLeaf1204410` | `IPathBuilder::~IPathBuilder` | `generated-family` |
| `0x1204430` | `unmapped/leaves/TableStoreLeaf1204430` | `TableStoreLeaf1204430::~TableStoreLeaf1204430` | `IPathBuilderTracker::~IPathBuilderTracker` | `generated-family` |
| `0x120aa60` | `unmapped/leaves/TableStoreLeaf120aa60` | `TableStoreLeaf120aa60::~TableStoreLeaf120aa60` | `IPathSmootherRayCast::~IPathSmootherRayCast` | `generated-family` |
| `0x1215fa0` | `unmapped/leaves/TableStoreLeaf1215fa0` | `TableStoreLeaf1215fa0::~TableStoreLeaf1215fa0` | `IMovementInterface::~IMovementInterface` | `generated-family` |
| `0x1215fc0` | `unmapped/leaves/TableStoreLeaf1215fc0` | `TableStoreLeaf1215fc0::~TableStoreLeaf1215fc0` | `IPipelineStageInterface::~IPipelineStageInterface` | `generated-family` |
| `0x1234b30` | `unmapped/leaves/TableStoreLeaf1234b30` | `TableStoreLeaf1234b30::~TableStoreLeaf1234b30` | `IMovementPlayIdleResult::~IMovementPlayIdleResult` | `generated-family` |
| `0x1234b70` | `unmapped/leaves/TableStoreLeaf1234b70` | `TableStoreLeaf1234b70::~TableStoreLeaf1234b70` | `ISelectIdleFilter::~ISelectIdleFilter` | `generated-family` |
| `0x1236d50` | `unmapped/leaves/TableStoreLeaf1236d50` | `TableStoreLeaf1236d50::~TableStoreLeaf1236d50` | `MovementMessage::~MovementMessage` | `generated-family` |
| `0x12456c0` | `unmapped/leaves/TableStoreLeaf12456c0` | `TableStoreLeaf12456c0::~TableStoreLeaf12456c0` | `ICheckEndReachedFunctorMapper::~ICheckEndReachedFunctorMapper` | `generated-family` |
| `0x14e7f40` | `bsshader/BSEffectShaderProperty_14e7f40` | `BSEffectShaderProperty::SetAlpha` | `BSShaderProperty::SetAlpha` | `prototype-arity` |
| `0x152a210` | `bsshader/BSEffectShaderProperty_152a210` | `BSEffectShaderProperty::ForEachTexture` | `BSEffectShaderProperty::ForEachTexture` | `alias-or-overload` |
| `0x155dbb0` | `unmapped/leaves/ReturnLeaf155dbb0` | `ReturnLeaf155dbb0::Invoke` | `BSShadowLight::GetIsFrustumLight` | `generated-family` |
| `0x155dbc0` | `unmapped/leaves/ReturnLeaf155dbc0` | `ReturnLeaf155dbc0::Invoke` | `BSShadowLight::GetIsParabolicLight` | `generated-family` |
| `0x155dbe0` | `unmapped/leaves/ReturnLeaf155dbe0` | `ReturnLeaf155dbe0::Invoke` | `BSShadowLight::GetNeedsClipPlanes` | `generated-family` |
| `0x155dbf0` | `unmapped/leaves/ReturnLeaf155dbf0` | `ReturnLeaf155dbf0::Invoke` | `BSShadowLight::GetPassExtraParam` | `generated-family` |
| `0x155dd20` | `unmapped/leaves/Leaf155dd20` | `Leaf155dd20::Invoke` | `BSShadowLight::TransformClipSpacePlanes` | `generated-family` |
| `0x1571920` | `unmapped/leaves/TableStoreLeaf1571920` | `TableStoreLeaf1571920::~TableStoreLeaf1571920` | `BSStreamParserData::~BSStreamParserData` | `generated-family` |
| `0x1572270` | `bssystem/BSResourceStreamParser_1572270` | `f3m_004a5c10::BSResourceStreamParser::~BSResourceStreamParser` | `BSResourceStreamParser::~BSResourceStreamParser` | `generated-family` |
| `0x158fb70` | `unmapped/leaves/TableStoreLeaf158fb70` | `TableStoreLeaf158fb70::~TableStoreLeaf158fb70` | `BSShapeConstructor::~BSShapeConstructor` | `generated-family` |
| `0x184a80` | `skyrim_shared/extradata/ExtraLevCreaModifier_184a80` | `ExtraLevCreaModifier::GetMultiplier` | `ExtraLevCreaModifier::GetMultiplier` | `alias-or-overload` |
| `0x190b80` | `skyrim_shared/forms/TESFullName_190a90` | `TESFullName::Function190b80` | `MapMarkerData::GetHidden` | `ownership-conflict` |
| `0x1c3680` | `skyrim/controls/TESDataHandler_1c3680` | `TESDataHandler::IsTemporaryFormID` | `TESDataHandler::IsFormIDCreated` | `source-name-differs` |
| `0x1df590` | `skyrim_shared/forms/TESBoundObject_1df590` | `TESBoundObject::GetFormAsBipedModel` | `TESBipedModelForm::GetFormAsBipedModel` | `ownership-conflict` |
| `0x227120` | `skyrim_shared/world/GridCellArray_226c40` | `GridCellArray::GetCellSlot` | `GridCellArray::Get` | `source-name-differs` |
| `0x259640` | `unmapped/support/Globals_259640` | `Func004a23f0` | `TESRegionPoint::XIntercept` | `no-class-claim` |
| `0x38de50` | `skyrim_shared/perks/BGSEntryPointPerkEntry_38de50` | `BGSEntryPointPerkEntry::SelectSpellFunction` | `BGSEntryPointFunction::SelectSpellFunction` | `ownership-conflict` |
| `0x3e0030` | `skyrim_shared/forms/BGSRefAlias` | `BGSRefAlias::GetForcedRefType` | `BGSRefAlias::QForcedRefType` | `source-name-differs` |
| `0x3ecb00` | `skyrim_shared/dialogue/ResponseDataPrefixLayout` | `ResponseDataPrefixLayout represented member` | `TESTopicInfo::TESResponse::LoadResponseText` | `no-source-name` |
| `0x41d530` | `skyrim_shared/actors/Character_41d530` | `Character::GetFollowRadiusMatchSpeed` | `AiFormulas::GetFollowRadiusMatchSpeed` | `ownership-conflict` |
| `0x44e080` | `skyrim/ai/BGSPackageDataLocation_44e080` | `BGSPackageDataLocation::Unk_0C` | `BGSPackageDataLocation::QIsCurrLoc` | `no-source-name` |
| `0x4c3b10` | `skyrim_shared/pathfinding/NavMeshInfoMap_4c3b10` | `NavMeshInfoMap::~NavMeshInfoMap` | `NavMeshInfoMap::~NavMeshInfoMap` | `generated-family` |
| `0x4e04b0` | `skyrim_shared/pathfinding/PathingCell_4e04b0` | `PathingCell::Func8` | `PathingCell::QAttached` | `source-name-differs` |
| `0x4e3260` | `unmapped/leaves/CtorLeaf4e3260` | `CtorLeaf4e3260::CtorLeaf4e3260` | `PathingRequest::PathingRequest` | `ownership-conflict` |
| `0x675350` | `skyrim_shared/actors/Actor` | `Leaf675350::Invoke` | `Actor::SetAvoidanceDisabled` | `no-source-name` |
| `0x6b1560` | `skyrim_shared/actors/Actor_6a5b30` | `Actor::GetResponseString` | `Actor::GetResponseString` | `no-source-name` |
| `0x6e98f0` | `skyrim/ai/ActorProcess_6e98f0` | `ActorProcess::IsPackageDone` | `AIProcess::IsPackageDone` | `ownership-conflict` |
| `0x6f5f90` | `skyrim/ai/ActorProcess_6f5f90` | `ActorProcess::GetWaitingforLipFile` | `AIProcess::GetWaitingforLipFile` | `ownership-conflict` |
| `0x758450` | `skyrim_shared/actors/PlayerCharacter_758450` | `PlayerCharacter::UnlockWord` | `PlayerCharacter::UnlockWord` | `no-source-name` |
| `0x867870` | `skyrim_shared/actors/Actor_867870` | `CombatUtilities_ComputeProjectileTime` | `CombatUtilities::ComputeProjectileTime` | `no-class-claim` |
| `0x8f1b70` | `skyrim_shared/actors/Character_8f1b70` | `Character::Interpolate` | `CombatAIFormulas::Interpolate` | `alias-or-overload` |
| `0x8f1bd0` | `skyrim_shared/actors/Character_8f1bd0` | `Character::Interpolate` | `CombatAIFormulas::Interpolate` | `alias-or-overload` |
| `0xab27d0` | `unmapped/leaves/LeafForwardab27d0` | `LeafForwardab27d0::Forward` | `thunk_hkStackTracer::CallTree::quit` | `generated-family` |
| `0xc65710` | `bshavok/Globals_c65710` | `fnv_00dbb940::hkDataClassNative::getParent` | `hkDataClassNative::getParent` | `namespace-differs` |
| `0xee5930` | `unmapped/support/Globals_ee5930` | `Func00a632b0` | `NiStream::_SDMShutdown` | `no-class-claim` |
| `0xf80490` | `gamebryo/nianimation/NiLookAtInterpolator_f80490` | `NiLookAtInterpolator::~NiLookAtInterpolator` | `NiLookAtInterpolator::~NiLookAtInterpolator` | `generated-family` |
| `0xfcea20` | `gamebryo/nimain/BSMultiBoundAABB_fcea20` | `BSMultiBoundAABB::Ctor` | `BSMultiBoundAABB::BSMultiBoundAABB` | `alias-or-overload` |
| `0xfe54d0` | `gamebryo/nimain/BSMultiBoundSphere_fe54d0` | `BSMultiBoundSphere::Functionfe54d0` | `DoorTeleportData::SetTeleportRotation` | `alias-or-overload` |
| `0xfe8120` | `gamebryo/nimain/BSOcclusionBox_fe8120` | `BSOcclusionBox::BSOcclusionBox` | `BSMultiBoundAABB::BSMultiBoundAABB` | `alias-or-overload` |
| `0x11b42e0` | `unmapped/support/MoviePlayer_11b42e0` | `f3m_007fb000::MoviePlayer::CalculateScale` | `MoviePlayer::CalculateScale` | `namespace-differs` |
| `0x11cbed0` | `skyrim_shared/pathfinding/PathingRequestStopMoving` | `PathingRequestStopMoving::Function11cbed0` | `BSPathingRequest::SetActorAvoidanceParametersNoActor` | `ownership-conflict` |
| `0x152a290` | `gamebryo/nimain/NiNode_14e7f80` | `NiNode::sub` | `BSEffectShaderProperty::SetBaseColorAlphaRecurse` | `ownership-conflict` |
