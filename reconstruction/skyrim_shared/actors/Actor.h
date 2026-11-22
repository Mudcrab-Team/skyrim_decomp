// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image and community declarations.
// Adapted bodies: ActorState::IsUnconscious, from CharmedBaryon/CommonLibSSE-NG at b93280e (MIT), include/RE/A/ActorState.h.
// Consulted (private, not in repo): decompiler control-flow hints.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
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
// AIProcess::GetVoiceRecoveryTime: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) GUESS(medium); NG declares it with an inline body and no address; that the callee at RVA 0x700100 is it is the guess
// ActorValueStorage::GetModifiers: GUESS; callee at RVA 0x6e3500 that looks up the modifier block of one actor value
// Licence: three member names come from powerof3/CommonLibSSE (GPL-3.0), so this file is GPL-3.0.
#pragma once

#include <cstddef>
#include <cstdint>

class BGSPerk;
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

enum class hkpCharacterStateType : std::uint32_t { kSwimming = 5 };

enum class CHARACTER_FLAGS : std::uint32_t { kHitDamage = 1u << 7 };

struct hkVector4 {
    float x;
    float y;
    float z;
    float w;
};

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
    std::uint8_t  unk00[0x14];
    std::uint32_t formID;  // 0x14
};

struct OutfitExtra {
    std::uint8_t  unk00[0x10];
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
    std::uint8_t unk00[0x20];

    const Modifiers* GetModifiers(ActorValue a_value) const;
};

class TESBoundObject {
public:
    std::uint8_t unk00[0x30];
};

class TESActorBaseData {
public:
    std::uint8_t unk00[0x58];

    std::uint16_t GetLevel() const;
};

class TESContainer {
public:
    std::uint8_t unk00[0x18];
};

class TESShout;

class TESSpellList {
public:
    std::uint8_t unk00[0x10];

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
};

struct OBJ_REFR {
    TESBoundObject* objectReference;  // 0x00
    std::uint8_t    unk08[0x18];
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
    virtual void Unk_5C();
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

    std::uint8_t unk08[0x38];
    OBJ_REFR     data;  // 0x40
    // parentCell: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    // unk68: GUESS(low); unresolved fields after the cell pointer.
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
    std::uint8_t unk00[0x18];
};

class ActorValueOwner {
public:
    std::uint8_t unk00[0x8];
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
    std::uint8_t      unkEC[0xc];
    AIProcess*        currentProcess;  // 0xf8
    std::uint8_t      unk100[0xf8];
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
