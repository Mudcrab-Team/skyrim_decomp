// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image and community declarations.
// Adapted bodies: ActorState::IsUnconscious, from CharmedBaryon/CommonLibSSE-NG at b93280e (MIT), include/RE/A/ActorState.h; TESForm::GetFormType, from the same revision, include/RE/T/TESForm.h:289 (a one-line getter, the stand-in TESForm repeats it).
// Consulted (private, not in repo): decompiler control-flow hints.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Actor: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the bases, members and virtual slots the functions use
// TESObjectREFR MagicTarget ActorValueOwner: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); base subobjects at 0x00, 0xa0, 0xb8, sized only
// ActorState: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); base subobject at 0xc0; its own vftable pointer is modelled as a word
// BGSOutfit: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InventoryChanges: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// InventoryEntryData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ExtraDataList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSSimpleList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESNPC: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); bases at 0x00, 0x30, 0x88 and 0xa0 as in NG's TESActorBase, sized only
// TESBoundObject TESActorBaseData TESContainer TESSpellList: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESShout: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValue: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ACTOR_VALUE_MODIFIER: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG nests it in ACTOR_VALUE_MODIFIERS as a plain enum
// AIProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Modifiers Modifiers::modifiers: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorValueStorage: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); 0x20 bytes, members not modelled
// OBJ_REFR OBJ_REFR::objectReference TESObjectREFR::data: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); data at 0x40
// TESObjectREFR::IsDead TESObjectREFR::MakeInventoryChanges: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); IsDead is virtual slot 0x99 (byte offset 0x4c8)
// TESActorBaseData::GetLevel: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::HasOutfitItems: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::GetLevel Actor::IsAttacking Actor::HasShout: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::GetVoiceRecoveryTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::GetMoveDirectionRelativeToFacing: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG declares a double return, this build returns the callee's float (32-bit load)
// Actor::IsInRagdollState Actor::GetActorValueModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BGSOutfit::formID InventoryChanges::entryList InventoryEntryData::extraLists: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); offsets 0x14, 0, 8
// InventoryEntryData::object: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::BOOL_BITS Actor::BOOL_BITS::kParalyzed Actor::boolBits Actor::currentProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); boolBits at 0xe8, currentProcess at 0xf8
// Actor::avStorage Actor::exclusiveBranch: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); at 0x208 and 0x228
// Actor::healthModifiers Actor::magickaModifiers Actor::staminaModifiers Actor::voicePointsModifiers: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); at 0x230, 0x23c, 0x248, 0x254
// ActorState::ActorState1 ActorState::ActorState2 ActorState::actorState1 ActorState::actorState2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); words at 0xc8 and 0xcc of the actor
// ActorState1::lifeState ActorState1::knockState ActorState1::meleeAttackState ActorState2::reanimating: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); bits 21-24, 25-27, 28-31 and bit 4
// ACTOR_LIFE_STATE ACTOR_LIFE_STATE::kUnconcious KNOCK_STATE_ENUM KNOCK_STATE_ENUM::kNormal KNOCK_STATE_ENUM::kGetUp: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ATTACK_STATE_ENUM ATTACK_STATE_ENUM::kNone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorState::GetAttackState ActorState::GetKnockState ActorState::GetLifeState ActorState::IsUnconscious: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorState::IsReanimating: GUESS; accessor in the style of NG's IsSneaking for the reanimating bit, NG has none
// Actor::IsParalyzed: GUESS; accessor for the kParalyzed bit of boolBits, NG has none
// FindOutfitExtra OutfitExtra OutfitExtra::outfitID: GUESS; callee at RVA 0x1648b0 takes an ExtraDataList* and returns a record whose word at 0x10 is compared with the outfit form id
// TESSpellList::HasShout: GUESS; callee at RVA 0x1f20e0 reached through the TESSpellList base at 0xa0
// AIProcess::GetMoveDirectionRelativeToFacing: GUESS; callee at RVA 0x7233d0
// NiPoint3, NiPoint3::x, NiPoint3::y, NiPoint3::z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Actor::Function6b5820: GUESS(low); writes the rotation of the process at 0x38 into its out point, or the origin point when that pointer is null
// AIProcess::Function7233b0: GUESS(low); callee at RVA 0x7233b0 yields a pointer to the process rotation
// niPointZero: GUESS(low); the origin point constant the null-process fallback reads
// AIProcess::GetVoiceRecoveryTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) GUESS(medium); NG declares it with an inline body and no address; that the callee at RVA 0x700100 is it is the guess
// ActorValueStorage::GetModifiers: GUESS; callee at RVA 0x6e3500 that looks up the modifier block of one actor value
#pragma once

#include <cstddef>
#include <cstdint>

class AIProcess;
class BGSPerk;
// EnchantmentItem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the pointer type of the callee result
class EnchantmentItem;
class MagicCaster;
class TESForm;
// bhkCharacterController, bhkCharacterMoveFinishEvent, TESObjectCELL, TESRace, NiAVObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// bhkCharacterController, hkpCharacterContext, hkpCharacterStateType, kSwimming, CHARACTER_FLAGS, kHitDamage, hkVector4, BSBound, hkpSurfaceInfo, hkStepInfo, collisionBound, bumperCollisionBound, forwardVec, stepInfo, outVelocity, initialVelocity, velocityMod, direction, rotCenter, pushDelta, fakeSupportStart, up, supportNorm, orientationCtrl, surfaceInfo, context, flags, GetPositionImpl, SetPositionImpl, GetTransformImpl, SetTransformImpl, GetLinearVelocityImpl, SetLinearVelocityImpl, GetCollisionFilterInfo, CheckSupportImpl, Unk_09, Unk_0A, Unk_0B, Unk_0C, Unk_0E, Unk_0F: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a prefix of NG's layout up to flags at 0x218; the members after flags are not declared
// GetFallDistance, SetJumpHeight, Unk_01, unknown008 to unknown068, unknown180, unknown188, unknown198, hkTransform: GUESS(low); unresolved words at their offsets and the two calls the compared code makes
// GetFallDistance and SetJumpHeight are calls of the compared code; Unk_0F is NG's void slot, declared with the result the compared code tests.
class bhkCharacterController;
struct bhkCharacterMoveFinishEvent;
class TESObjectCELL;
class TESRace;
class NiAVObject;

// TESForm::sourceFiles, TESForm::formFlags, TESForm::formID, TESForm::inGameFormFlags, TESForm::formType, TESForm::GetFormType, FormType, FormType::Armor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
enum class FormType : std::uint8_t { Armor = 26 };

class TESForm {
public:
    virtual ~TESForm();
    void*         sourceFiles;      // 0x08, TESFileContainer in NG
    std::uint32_t formFlags;        // 0x10
    std::uint32_t formID;           // 0x14
    std::uint16_t inGameFormFlags;  // 0x18
    FormType      formType;         // 0x1A

    FormType GetFormType() const noexcept { return formType; }
};
static_assert(offsetof(TESForm, formType) == 0x1a, "TESForm::formType offset");

// MagicSystem: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the casting-source enum the compared code passes
struct MagicSystem {
    enum class CastingSource : std::uint32_t { kInstant = 3 };
};

enum class hkpCharacterStateType : std::uint32_t { kSwimming = 5 };

enum class CHARACTER_FLAGS : std::uint32_t { kHitDamage = 1u << 7 };

struct hkVector4 {
    float x;
    float y;
    float z;
    float w;
};

struct NiPoint3 {
    float x;
    float y;
    float z;
};
static_assert(sizeof(NiPoint3) == 0xc, "NiPoint3 size");

struct hkTransform;

struct hkStepInfo {
    std::uint64_t unknown00;  // 00
    std::uint64_t unknown08;  // 08
};

struct BSBound {
    std::uint64_t unknown00;  // 00
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
};
static_assert(sizeof(BSBound) == 0x30, "BSBound size");

struct hkpSurfaceInfo {
    std::uint64_t unknown00;  // 00
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
};
static_assert(sizeof(hkpSurfaceInfo) == 0x40, "hkpSurfaceInfo size");

class hkpCharacterContext {
public:
    virtual ~hkpCharacterContext();
    hkpCharacterStateType GetState() const;
    // hkpCharacterContext::Functionb97880: GUESS(low); callee at RVA 0xb97880 returns the state word at 0x08.
    hkpCharacterStateType Functionb97880() const;

    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
};
static_assert(sizeof(hkpCharacterContext) == 0x38, "hkpCharacterContext size");

class bhkICharOrientationController;

class bhkCharacterController {
public:
    virtual ~bhkCharacterController();                                                       // 00
    virtual void  Unk_01();                                                                  // 01
    virtual void  GetPositionImpl(hkVector4& a_pos, bool a_applyCenterOffset) const;         // 02
    virtual void  SetPositionImpl(const hkVector4& a_pos, bool a_applyCenterOffset, bool a_forceWarp);  // 03
    virtual void  GetTransformImpl(hkTransform& a_transform) const;                          // 04
    virtual void  SetTransformImpl(const hkTransform& a_transform);                          // 05
    virtual void  GetLinearVelocityImpl(hkVector4& a_velocity) const;                        // 06
    virtual void  SetLinearVelocityImpl(const hkVector4& a_velocity);                        // 07
    virtual void  GetCollisionFilterInfo(std::uint32_t& a_collisionFilterInfo) const;        // 08
    virtual void  Unk_09();                                                                  // 09
    virtual void  Unk_0A();                                                                  // 0A
    virtual void  Unk_0B();                                                                  // 0B
    virtual void  Unk_0C();                                                                  // 0C
    virtual void  CheckSupportImpl();                                                        // 0D
    virtual void  Unk_0E();                                                                  // 0E
    virtual void* Unk_0F();                                                                  // 0F

    float GetFallDistance() const;
    void  SetJumpHeight(float a_height);

    std::uint64_t unknown008;  // 008
    std::uint64_t unknown010;  // 010
    std::uint64_t unknown018;  // 018
    std::uint64_t unknown020;  // 020
    std::uint64_t unknown028;  // 028
    std::uint64_t unknown030;  // 030
    std::uint64_t unknown038;  // 038
    std::uint64_t unknown040;  // 040
    std::uint64_t unknown048;  // 048
    std::uint64_t unknown050;  // 050
    std::uint64_t unknown058;  // 058
    std::uint64_t unknown060;  // 060
    std::uint64_t unknown068;  // 068
    hkVector4                      forwardVec;        // 070
    hkStepInfo                     stepInfo;          // 080
    hkVector4                      outVelocity;       // 090
    hkVector4                      initialVelocity;   // 0A0
    hkVector4                      velocityMod;       // 0B0
    hkVector4                      direction;         // 0C0
    hkVector4                      rotCenter;         // 0D0
    hkVector4                      pushDelta;         // 0E0
    hkVector4                      fakeSupportStart;  // 0F0
    hkVector4                      up;                // 100
    hkVector4                      supportNorm;       // 110
    BSBound                        collisionBound;    // 120
    BSBound                        bumperCollisionBound;  // 150
    std::uint64_t                  unknown180;        // 180
    std::uint64_t                  unknown188;        // 188
    bhkICharOrientationController* orientationCtrl;   // 190
    std::uint64_t                  unknown198;        // 198
    hkpSurfaceInfo                 surfaceInfo;       // 1A0
    hkpCharacterContext            context;           // 1E0
    CHARACTER_FLAGS                flags;             // 218
};
static_assert(offsetof(bhkCharacterController, context) == 0x1e0, "bhkCharacterController::context offset");
static_assert(offsetof(bhkCharacterController, flags) == 0x218, "bhkCharacterController::flags offset");

template <class T>
struct BSSimpleList {
    T             item;  // 0x00
    BSSimpleList* next;  // 0x08
};

class MountInteraction;

// ExtraDataList::GetMountInteraction: CRASHLOGGER_PDB(59818@2026.10.24); 0x18 bytes as in NG, members not modelled
// MountInteraction: GUESS(low); the out parameter is modelled as a plain pointer
class ExtraDataList {
public:
    void GetMountInteraction(MountInteraction*& a_out);

    std::uint8_t unk00[0x18];
};

class InventoryEntryData {
public:
    void*                         object;      // 0x00
    BSSimpleList<ExtraDataList*>* extraLists;  // 0x08
};

class InventoryChanges {
public:
    BSSimpleList<InventoryEntryData*>* entryList;  // 0x00
};

class BGSOutfit {
public:
    // unknown00 to unknown10: GUESS(low); unresolved words before formID, no compared body reads them.
    std::uint64_t unknown00;  // 0x00
    std::uint64_t unknown08;  // 0x08
    std::uint32_t unknown10;  // 0x10
    std::uint32_t formID;  // 0x14
};

struct OutfitExtra {
    // unknown00 unknown08: GUESS(low); unresolved words before outfitID, no compared body reads them.
    std::uint64_t unknown00;  // 0x00
    std::uint64_t unknown08;  // 0x08
    std::uint32_t outfitID;  // 0x10
};

// FindOutfitExtra: GUESS; bound to RVA 0x1648b0.
OutfitExtra* FindOutfitExtra(ExtraDataList* a_list);


enum class ActorValue : std::int32_t {
    kHealth      = 24,
    kMagicka     = 25,
    kStamina     = 26,
    kVoicePoints = 37,
};

enum class ACTOR_VALUE_MODIFIER : std::int32_t {
    kPermanent,
    kTemporary,
    kDamage,
};

struct Modifiers {
    float modifiers[3];
};

struct ActorValueStorage {
    // unknown00 to unknown18: GUESS(low); unresolved words before the modifier table, no compared body reads them.
    std::uint64_t unknown00;  // 0x00
    std::uint64_t unknown08;  // 0x08
    std::uint64_t unknown10;  // 0x10
    std::uint64_t unknown18;  // 0x18

    const Modifiers* GetModifiers(ActorValue a_value) const;
};

class TESBoundObject {
public:
    // unknown00 to unknown28: GUESS(low); unresolved words of the bound-object base, no compared body reads them.
    std::uint64_t unknown00;  // 0x00
    std::uint64_t unknown08;  // 0x08
    std::uint64_t unknown10;  // 0x10
    std::uint64_t unknown18;  // 0x18
    std::uint64_t unknown20;  // 0x20
    std::uint64_t unknown28;  // 0x28
};

class TESActorBaseData {
public:
    // unknown00 to unknown50: GUESS(low); unresolved words before the level accessor's own data.
    std::uint64_t unknown00;  // 0x00
    std::uint64_t unknown08;  // 0x08
    std::uint64_t unknown10;  // 0x10
    std::uint64_t unknown18;  // 0x18
    std::uint64_t unknown20;  // 0x20
    std::uint64_t unknown28;  // 0x28
    std::uint64_t unknown30;  // 0x30
    std::uint64_t unknown38;  // 0x38
    std::uint64_t unknown40;  // 0x40
    std::uint64_t unknown48;  // 0x48
    std::uint64_t unknown50;  // 0x50

    std::uint16_t GetLevel() const;
};

class TESContainer {
public:
    // unknown00 to unknown10: GUESS(low); unresolved words of the container base, no compared body reads them.
    std::uint64_t unknown00;  // 0x00
    std::uint64_t unknown08;  // 0x08
    std::uint64_t unknown10;  // 0x10
};

class TESShout;

class TESSpellList {
public:
    // unknown00 unknown08: GUESS(low); unresolved words before the shout table, no compared body reads them.
    std::uint64_t unknown00;  // 0x00
    std::uint64_t unknown08;  // 0x08

    bool HasShout(TESShout* a_shout) const;
};

class TESNPC : public TESBoundObject, public TESActorBaseData, public TESContainer, public TESSpellList {
};

class AIProcess {
public:
    float GetMoveDirectionRelativeToFacing();
    float GetVoiceRecoveryTime() const;
    // AIProcess::GetCharController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    bhkCharacterController* GetCharController();
    // AIProcess::Function722110: GUESS(low); callee at RVA 0x722110 returns the character controller.
    bhkCharacterController* Function722110();
    // AIProcess::Function7233b0: GUESS(low); callee at RVA 0x7233b0 returns a pointer to the process rotation.
    const NiPoint3& Function7233b0() const;
};

struct OBJ_REFR {
    TESBoundObject* objectReference;  // 0x00
    // unknown08 to unknown18: GUESS(low); unresolved words after the object pointer, no compared body reads them.
    std::uint64_t unknown08;  // 0x08
    std::uint64_t unknown10;  // 0x10
    std::uint64_t unknown18;  // 0x18
};

class TESObjectREFR {
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Unk_26();
    virtual void Unk_27();
    virtual void Unk_28();
    virtual void Unk_29();
    virtual void Unk_2A();
    virtual void Unk_2B();
    virtual void Unk_2C();
    virtual void Unk_2D();
    virtual void Unk_2E();
    virtual void Unk_2F();
    virtual void Unk_30();
    virtual void Unk_31();
    virtual void Unk_32();
    virtual void Unk_33();
    virtual void Unk_34();
    virtual void Unk_35();
    virtual void Unk_36();
    virtual void Unk_37();
    virtual void Unk_38();
    virtual void Unk_39();
    virtual void Unk_3A();
    virtual void Unk_3B();
    virtual void Unk_3C();
    virtual void Unk_3D();
    virtual void Unk_3E();
    virtual void Unk_3F();
    virtual void Unk_40();
    virtual void Unk_41();
    virtual void Unk_42();
    virtual void Unk_43();
    virtual void Unk_44();
    virtual void Unk_45();
    virtual void Unk_46();
    virtual void Unk_47();
    virtual void Unk_48();
    virtual void Unk_49();
    virtual void Unk_4A();
    virtual void Unk_4B();
    virtual void Unk_4C();
    virtual void Unk_4D();
    virtual void Unk_4E();
    virtual void Unk_4F();
    virtual void Unk_50();
    virtual void Unk_51();
    virtual void Unk_52();
    virtual void Unk_53();
    virtual void Unk_54();
    virtual void Unk_55();
    virtual void Unk_56();
    virtual void Unk_57();
    virtual void Unk_58();
    virtual void Unk_59();
    virtual void Unk_5A();
    virtual void Unk_5B();
    // MagicSystem::CastingSource, MagicSystem::CastingSource::kInstant, TESObjectREFR::GetMagicCaster: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 0x5c
    virtual MagicCaster* GetMagicCaster(MagicSystem::CastingSource a_source);  // 0x5C
    virtual void Unk_5D();
    virtual void Unk_5E();
    virtual void Unk_5F();
    virtual void Unk_60();
    virtual void Unk_61();
    virtual void Unk_62();
    virtual void Unk_63();
    virtual void Unk_64();
    virtual void Unk_65();
    virtual void Unk_66();
    virtual void Unk_67();
    virtual void Unk_68();
    virtual void Unk_69();
    virtual void Unk_6A();
    virtual void Unk_6B();
    virtual void Unk_6C();
    virtual void Unk_6D();
    virtual void Unk_6E();
    virtual void Unk_6F();
    // Get3D2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual NiAVObject* Get3D2() const;
    virtual void Unk_71();
    virtual void Unk_72();
    virtual void Unk_73();
    virtual void Unk_74();
    virtual void Unk_75();
    virtual void Unk_76();
    virtual void Unk_77();
    virtual void Unk_78();
    virtual void Unk_79();
    virtual void Unk_7A();
    virtual void Unk_7B();
    virtual void Unk_7C();
    virtual void Unk_7D();
    virtual void Unk_7E();
    virtual void Unk_7F();
    virtual void Unk_80();
    virtual void Unk_81();
    virtual void Unk_82();
    virtual void Unk_83();
    virtual void Unk_84();
    virtual void Unk_85();
    virtual void Unk_86();
    virtual void Unk_87();
    virtual void Unk_88();
    virtual void Unk_89();
    virtual void Unk_8A();
    virtual void Unk_8B();
    virtual void Unk_8C();
    virtual void Unk_8D();
    virtual void Unk_8E();
    virtual void Unk_8F();
    virtual void Unk_90();
    virtual void Unk_91();
    virtual void Unk_92();
    virtual void Unk_93();
    virtual void Unk_94();
    virtual void Unk_95();
    virtual void Unk_96();
    virtual void Unk_97();
    virtual void Unk_98();
    virtual bool IsDead(bool a_notEssential = true) const;  // 0x99

    InventoryChanges* MakeInventoryChanges();

    // unknown08 to unknown30: GUESS(low); unresolved words before data, no compared body reads them.
    std::uint64_t unknown08;  // 0x08
    std::uint64_t unknown10;  // 0x10
    std::uint64_t unknown18;  // 0x18
    std::uint64_t unknown20;  // 0x20
    std::uint64_t unknown28;  // 0x28
    std::uint64_t unknown30;  // 0x30
    // unknown38: GUESS(low); AIProcess pointer at 0x38, its callee yields the character controller.
    AIProcess*    unknown38;  // 0x38
    OBJ_REFR     data;  // 0x40
    // parentCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    TESObjectCELL* parentCell;
    // extraList: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); at 0x70
    std::uint8_t unk68[0x8];
    ExtraDataList extraList;
    std::uint8_t unk88[0x18];

    // GetScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    float GetScale() const;

    // Function6bd530: GUESS(low)
    float Function6bd530(float a_distance, float a_scale);

};

class MagicTarget {
public:
    // unknown00 to unknown10: GUESS(low); unresolved words of the magic-target base, no compared body reads them.
    std::uint64_t unknown00;  // 0x00
    std::uint64_t unknown08;  // 0x08
    std::uint64_t unknown10;  // 0x10
};

// MagicCaster, MagicCaster::InterruptCast: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); InterruptCast is a non-virtual member in NG.
class MagicCaster {
public:
    // unknown00: GUESS(low); the leading word of the caster subobject, kept so InterruptCast's offsets are unchanged.
    std::uint64_t unknown00;  // 0x00
    void InterruptCast(bool a_refund);
    // MagicCaster::CastEnchantment: GUESS(low); callee at RVA 0x5ca5e0 takes the enchantment, the form and a flag.
    void CastEnchantment(EnchantmentItem* a_enchantment, TESForm* a_form, bool a_flag);
};

class ActorValueOwner {
public:
    // unknown00: GUESS(low); unresolved word of the value-owner base, no compared body reads it.
    std::uint64_t unknown00;  // 0x00
};

enum class ACTOR_LIFE_STATE : std::uint32_t {
    kUnconcious = 3,
};

enum class KNOCK_STATE_ENUM : std::uint32_t {
    kNormal = 0,
    kGetUp  = 6,
};

enum class ATTACK_STATE_ENUM : std::uint32_t {
    kNone = 0,
};

class ActorState {
public:
    struct ActorState1 {
        std::uint32_t     unk00 : 21;
        ACTOR_LIFE_STATE  lifeState : 4;         // bits 21-24
        KNOCK_STATE_ENUM  knockState : 3;        // bits 25-27
        ATTACK_STATE_ENUM meleeAttackState : 4;  // bits 28-31
    };

    struct ActorState2 {
        std::uint32_t unk00 : 4;
        std::uint32_t reanimating : 1;  // bit 4
        std::uint32_t unk05 : 27;
    };

    ATTACK_STATE_ENUM GetAttackState() const noexcept { return actorState1.meleeAttackState; }
    KNOCK_STATE_ENUM  GetKnockState() const noexcept { return actorState1.knockState; }
    ACTOR_LIFE_STATE  GetLifeState() const noexcept { return actorState1.lifeState; }
    bool              IsUnconscious() const noexcept { return GetLifeState() == ACTOR_LIFE_STATE::kUnconcious; }
    bool              IsReanimating() const noexcept { return static_cast<bool>(actorState2.reanimating); }

    std::uint64_t unk00;        // 0x00, the vftable pointer of NG's IMovementState base
    ActorState1   actorState1;  // 0x08
    ActorState2   actorState2;  // 0x0c
};


// GetFormEnchantment: GUESS(low); callee at RVA 0x1e1fd0 takes the form and the reference and returns the enchantment pointer.
EnchantmentItem* GetFormEnchantment(TESForm* a_form, TESObjectREFR* a_target);

class Actor : public TESObjectREFR, public MagicTarget, public ActorValueOwner, public ActorState {
public:
    enum class BOOL_BITS : std::uint32_t {
        kParalyzed = 1u << 31,
    };

    // BOOL_FLAGS, kIsAMount, boolFlags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    enum class BOOL_FLAGS : std::uint32_t {
        kIsAMount = 1u << 1,
    };

    bool IsParalyzed() const noexcept { return (boolBits & static_cast<std::uint32_t>(BOOL_BITS::kParalyzed)) != 0; }

    // MoveFinishSink, moveFinishSink: GUESS(low); event sink member view at the target offset
    // unkD0, unkE0, unk200: GUESS(low); unresolved fields adjacent to represented members.
    struct MoveFinishSink {
        virtual ~MoveFinishSink();
    };

    std::uint64_t     unkD0;
    MoveFinishSink    moveFinishSink;  // 0xd8
    std::uint64_t     unkE0;
    std::uint32_t     boolBits;  // 0xe8
    // unknownEC to unknownF4: GUESS(low); unresolved words between the flag word and the process pointer.
    std::uint32_t     unknownEC;  // 0xec
    std::uint32_t     unknownF0;  // 0xf0
    std::uint32_t     unknownF4;  // 0xf4
    AIProcess*        currentProcess;  // 0xf8
    // unknown100 to unknown1a0 and unknown1c8 to unknown1f0: GUESS(low); unresolved words around the caster pointers at their offsets.
    std::uint64_t     unknown100;  // 0x100
    std::uint64_t     unknown108;  // 0x108
    std::uint64_t     unknown110;  // 0x110
    std::uint64_t     unknown118;  // 0x118
    std::uint64_t     unknown120;  // 0x120
    std::uint64_t     unknown128;  // 0x128
    std::uint64_t     unknown130;  // 0x130
    std::uint64_t     unknown138;  // 0x138
    std::uint64_t     unknown140;  // 0x140
    std::uint64_t     unknown148;  // 0x148
    std::uint64_t     unknown150;  // 0x150
    std::uint64_t     unknown158;  // 0x158
    std::uint64_t     unknown160;  // 0x160
    std::uint64_t     unknown168;  // 0x168
    std::uint64_t     unknown170;  // 0x170
    std::uint64_t     unknown178;  // 0x178
    std::uint64_t     unknown180;  // 0x180
    std::uint64_t     unknown188;  // 0x188
    std::uint64_t     unknown190;  // 0x190
    std::uint64_t     unknown198;  // 0x198
    std::uint64_t     unknown1a0;  // 0x1a0
    // magicCasters: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); four caster pointers, at 0x1a8 in this build.
    MagicCaster*      magicCasters[4];  // 0x1a8
    std::uint64_t     unknown1c8;  // 0x1c8
    std::uint64_t     unknown1d0;  // 0x1d0
    std::uint64_t     unknown1d8;  // 0x1d8
    std::uint64_t     unknown1e0;  // 0x1e0
    std::uint64_t     unknown1e8;  // 0x1e8
    std::uint64_t     unknown1f0;  // 0x1f0
    // race: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    TESRace*          race;
    std::uint32_t     unk200;
    BOOL_FLAGS       boolFlags;       // 0x204
    ActorValueStorage avStorage;        // 0x208
    void*             exclusiveBranch;  // 0x228
    Modifiers         healthModifiers;       // 0x230
    Modifiers         magickaModifiers;      // 0x23c
    Modifiers         staminaModifiers;      // 0x248
    Modifiers         voicePointsModifiers;  // 0x254

    // ProcessEvent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); receiver model inferred from the adjusted entry.
    // HandleMoveFinish, ApplyFallDamage, SetFallDamageState: GUESS(low)
    static int ProcessEvent(MoveFinishSink* a_sink, const bhkCharacterMoveFinishEvent* a_event);
    void HandleMoveFinish(const bhkCharacterMoveFinishEvent* a_event);
    void ApplyFallDamage(float a_damage, Actor* a_attacker, bool a_falling);
    void SetFallDamageState(bool a_falling, bool a_notify);

    // GetCharController, IsOnMount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    bhkCharacterController* GetCharController() const;
    bool IsOnMount() const;
    // GetMountInteraction: CRASHLOGGER_PDB(59818@2026.10.24)
    bool GetMountInteraction(MountInteraction*& a_out);

    // Function6b5bf0: GUESS(low); the character controller's context state, 0 when either link is absent.
    hkpCharacterStateType Function6b5bf0();
    // Function6b5820: GUESS(low); writes the rotation of the process at 0x38, or the origin point when it is absent.
    void Function6b5820(NiPoint3& a_out) const;
    // Function6d6690: GUESS(low); interrupts every non-null magic caster slot with the argument.
    void Function6d6690(bool a_refund);
    // Function6d5e30: GUESS(low); an ingredient's enchantment is applied through the instant magic caster.
    void Function6d5e30(TESForm* a_item, TESObjectREFR* a_target);
    // Function6e49e0: GUESS(low); precondition tested before either update path of Function7cf670, taking the flag.
    bool Function6e49e0(bool a_flag);
    // Function6a4a10: GUESS(low); update path Function7cf670 takes when the precondition fails.
    void Function6a4a10(bool a_flag);
    // Function7cf670: GUESS(low); dispatch of one actor update through the task queue or directly.
    void Function7cf670(bool a_flag);

    bool          HasOutfitItems(BGSOutfit* a_outfit);
    std::uint16_t GetLevel() const;
    bool          IsAttacking() const;
    bool          HasShout(TESShout* a_shout) const;
    float         GetMoveDirectionRelativeToFacing();
    float         GetVoiceRecoveryTime();
    bool          IsInRagdollState() const;
    float         GetActorValueModifier(ACTOR_VALUE_MODIFIER a_modifier, ActorValue a_value) const;
    // Actor::SetAvoidanceDisabled, Actor::UseSkill, Actor::AddPerk: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0); compared at RVA 0x675350, 0x6990e0, 0x69f8e0
    void SetAvoidanceDisabled(bool a_set);  // compared: 0x675350
    void UseSkill(ActorValue a_av, float a_points, TESForm* a_arg3);  // compared: 0x6990e0
    void AddPerk(BGSPerk* a_perk, std::uint32_t a_rank = 0);  // compared: 0x69f8e0
};

static_assert(offsetof(TESObjectREFR, extraList) == 0x70, "TESObjectREFR::extraList offset");
static_assert(offsetof(Actor, moveFinishSink) == 0xd8, "Actor::moveFinishSink offset");
static_assert(offsetof(Actor, race) == 0x1f8, "Actor::race offset");
static_assert(offsetof(Actor, boolBits) == 0xe8, "Actor::boolBits offset");
static_assert(offsetof(Actor, currentProcess) == 0xf8, "Actor::currentProcess offset");
static_assert(offsetof(Actor, boolFlags) == 0x204, "Actor::boolFlags offset");
static_assert(offsetof(Actor, avStorage) == 0x208, "Actor::avStorage offset");
static_assert(offsetof(Actor, voicePointsModifiers) == 0x254, "Actor::voicePointsModifiers offset");
static_assert(offsetof(Actor, magicCasters) == 0x1a8, "Actor::magicCasters offset");

// TaskQueueInterface: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the one slot Function7cf670 reaches.
class TaskQueueInterface {
public:
    // Function668780: GUESS(low); queued form of the actor update, taking the actor and the flag.
    void Function668780(Actor* a_actor, bool a_flag);
};

// taskQueue: GUESS(low); the singleton pointer Function7cf670 loads before it queues the update.
extern TaskQueueInterface* taskQueue;

// playerActor, defaultFallScale, landingSoundThreshold, heavyLandingSound, lightLandingSound: GUESS(low); fall-damage and audio inputs.
// niPointZero: GUESS(low); origin point constant read when the process pointer is null.
extern NiPoint3 niPointZero;
extern Actor* playerActor;
extern const float defaultFallScale;
extern float landingSoundThreshold;
extern const char heavyLandingSound[];
extern const char lightLandingSound[];
