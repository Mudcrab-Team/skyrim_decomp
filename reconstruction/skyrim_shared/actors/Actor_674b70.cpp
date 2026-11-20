// Source exposure: mixed (pinned image and RTTI, project layouts, and CommonLib declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE names; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original bodies using the cited declarations and the observed receiver offsets.
// Adapted bodies: none
// 0x674b70 Actor::Function674b70
// 0x675310 Actor::Function675310
// 0x675540 Actor::Function675540
// 0x675560 Actor::Function675560
// 0x685900 Actor::GetBoundRadius
// 0x687ac0 Actor::IsMovementAnimationDriven
// 0x687c00 Actor::Function687c00
// 0x687f30 Actor::Function687f30
// 0x692320 Actor::Function692320
// 0x696a40 Actor::Function696a40
// 0x69f8c0 Actor::Function69f8c0
// 0x69fe50 ApplySoundEvent
// 0x6a15c0 Actor::Function6a15c0
// 0x6a51b0 Actor::Function6a51b0
// 0x6af0d0 Actor::Function6af0d0
// 0x6b1160 Actor::Function6b1160
// 0x6b5770 Actor::Function6b5770
// 0x6b57d0 Actor::Function6b57d0
// 0x6b5860 Actor::DoGetMovementSpeed
// 0x6b59f0 Actor::Function6b59f0
// 0x6b60b0 Actor::GetAnimationGraphManagerImpl
// 0x6bbd08 Actor::~Actor
// 0x6bbd14 Actor::~Actor
// 0x6bbd20 Actor::~Actor
// 0x6bbd2c Actor::~Actor
// 0x6bbd38 Actor::~Actor
// 0x6bbd44 Actor::~Actor
// 0x6bdd60 Actor::Function6bdd60
// 0x6bde50 Actor::Function6bde50
// 0x6bde70 Actor::Function6bde70
// 0x6bde80 Actor::Function6bde80
// 0x6bde90 Actor::GetTargetStatsObject
// 0x6c1170 Actor::Function6c1170
// 0x6c1180 Actor::Function6c1180
// 0x6c2b90 Actor::Function6c2b90
// 0x6c2d00 Actor::Function6c2d00
// 0x6c2d10 Actor::Function6c2d10
// 0x6c8a40 Actor::Function6c8a40
// 0x6c9f00 Actor::Function6c9f00
// 0x6ca270 Actor::Function6ca270
// 0x6cc8f0 Actor::Function6cc8f0
// 0x6d4d20 Actor::Function6d4d20
// 0x6d7070 Actor::Function6d7070
// 0x6d7090 Actor::Function6d7090
// 0x6d8dd0 Actor::InvalidateCommandedActorEffect
// 0x6d9250 Actor::Function6d9250
// 0x6d9270 Actor::Function6d9270
// 0x6d92d0 Actor::Function6d92d0
// 0x6d92f0 Actor::Function6d92f0
#include "Actor_674b70.h"

// CachedValues, cachedRadius, flags, cachedValues, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess::GetCurrentShout, MovementControllerNPC, IMovementControllerRegisterInterface: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MotionGate, MovementKey, animationMovementKey, FunctionSlot01, FunctionSlot02, FunctionSlot03: STANDIN GUESS(low)
// FunctionSlot04, FunctionSlot05, FunctionSlot06, defaultActorFloat, defaultActorWord: STANDIN GUESS(low)
// Function722110, Function6f5120, Function7231e0, Function7217e0, Function726ee0, Function1db3d0: GUESS(low)
// SetAlert, IsAlert, GetPackageThatIsRunning, GetCurrentMovementSpeed, GetAttackData: GUESS(low)
// GetVoiceState, SetCurrentShoutVariation, GetCurrentShoutVariation, emptyAttackData, initialActionTimer: GUESS(low)
struct CachedValues
{
    float cachedRadius;
    std::uint8_t padding[0x28];
    std::uint32_t flags;
};

class AIProcess
{
public:
    std::uint32_t Function722110() const;
    void SetAlert(bool value);
    bool IsAlert() const;
    bool Function6f5120() const;
    void SetWeaponBone(NiNode* value);
    std::uint32_t Function7231e0() const;
    TESPackage* GetPackageThatIsRunning() const;
    float GetCurrentMovementSpeed() const;
    bool Function7217e0(BSTSmartPointer<BSAnimationGraphManager>& output) const;
    const AttackDataPointer& GetAttackData() const;
    void Function726ee0(ActiveEffect* effect);
    VOICE_STATE GetVoiceState() const;
    TESShout* GetCurrentShout() const;
    void SetCurrentShoutVariation(TESShoutVariation value);
    TESShoutVariation GetCurrentShoutVariation() const;

    std::uint8_t padding[0x50];
    CachedValues* cachedValues;
};

struct MovementKey;

class MotionGate
{
public:
    virtual ~MotionGate();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual void FunctionSlot04();
    virtual void FunctionSlot05();
    virtual bool FunctionSlot06() const;
};

class IMovementControllerRegisterInterface
{
public:
    virtual ~IMovementControllerRegisterInterface();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual MotionGate* FunctionSlot03(const MovementKey& key);
};

class MovementControllerNPC : public IMovementControllerRegisterInterface
{
};

class BGSPerkRankArray
{
public:
    void* Function1db3d0() const;
};

class TESNPC
{
public:
    std::uint8_t padding[0x138];
    BGSPerkRankArray perkRanks;
};

extern const MovementKey animationMovementKey;
extern const float initialActionTimer;
extern const float defaultActorFloat;
extern const std::uint32_t defaultActorWord;
extern const AttackDataPointer emptyAttackData;

Actor::Actor()
{
}

void* Actor::Function674b70() const
{
    const auto flags = static_cast<std::uint8_t>(boolBits >> 3);
    if (flags & 1u) {
        return Function2e6a90();
    }
    return nullptr;
}

std::uint32_t Actor::Function675310() const
{
    if (currentProcess) {
        return currentProcess->Function722110();
    }
    return 0;
}

void Actor::Function675540(bool value)
{
    if (currentProcess) {
        return currentProcess->SetAlert(value);
    }
}

bool Actor::Function675560() const
{
    if (currentProcess) {
        return currentProcess->IsAlert();
    }
    return false;
}

float Actor::GetBoundRadius() const
{
    if (const auto* process = currentProcess) {
        if (const auto* cache = process->cachedValues) {
            const auto missing = static_cast<std::uint8_t>(~cache->flags);
            if (missing & 1u) {
                return Function6a7910();
            }
            return cache->cachedRadius;
        }
    }
    return Function6a7910();
}

bool Actor::IsMovementAnimationDriven() const
{
    if (movementController) {
        auto* gate = movementController->FunctionSlot03(animationMovementKey);
        if (gate && !gate->FunctionSlot06()) {
            return true;
        }
    }
    return false;
}

void Actor::Function687c00(bool value)
{
    return Function693200(static_cast<std::uint32_t>(value) << 2);
}

bool Actor::Function687f30() const
{
    if (currentProcess) {
        return currentProcess->Function6f5120();
    }
    return false;
}

void Actor::Function692320(NiNode* value)
{
    if (currentProcess) {
        return currentProcess->SetWeaponBone(value);
    }
}

std::uint32_t Actor::Function696a40() const
{
    return currentProcess->Function7231e0();
}

void* Actor::Function69f8c0() const
{
    return data.objectReference->perkRanks.Function1db3d0();
}

void ApplySoundEvent(Actor* actor, std::int32_t value)
{
    actor->actionValue = value;
    actor->timerOnAction = initialActionTimer;
}

TESPackage* Actor::Function6a15c0() const
{
    if (currentProcess) {
        return currentProcess->GetPackageThatIsRunning();
    }
    return nullptr;
}

MovementControllerNPC* const& Actor::Function6a51b0() const
{
    return movementController;
}

float Actor::Function6af0d0() const
{
    if (currentProcess) {
        return currentProcess->GetCurrentMovementSpeed();
    }
    return 0.0f;
}

bool Actor::Function6b1160() const
{
    return (unk1CC >> 8) & 1u;
}

std::uint32_t Actor::Function6b5770() const
{
    return formID;
}

void Actor::Function6b57d0(NiPoint3& output) const
{
    output.x = data.location.x;
    output.y = data.location.y;
    output.z = data.location.z;
}

float Actor::DoGetMovementSpeed()
{
    if (currentProcess) {
        return currentProcess->GetCurrentMovementSpeed();
    }
    return 0.0f;
}

std::uint32_t Actor::Function6b59f0() const
{
    return Function685a30();
}

bool Actor::GetAnimationGraphManagerImpl(BSTSmartPointer<BSAnimationGraphManager>& output) const
{
    if (currentProcess) {
        return currentProcess->Function7217e0(output);
    }
    return false;
}

float Actor::Function6bdd60()
{
    return defaultActorFloat;
}

BGSDialogueBranch* Actor::Function6bde50() const
{
    return exclusiveBranch;
}

std::uint32_t Actor::Function6bde70() const
{
    return emotionType;
}

std::uint32_t Actor::Function6bde80() const
{
    return emotionValue;
}

TESObjectREFR* Actor::GetTargetStatsObject()
{
    return this;
}

std::uint32_t& Actor::Function6c1170(std::uint32_t& output) const
{
    output = defaultActorWord;
    return output;
}

bool Actor::Function6c1180() const
{
    return ~(boolBits >> 5) & 1u;
}

void Actor::Function6c2b90(BGSDialogueBranch* value)
{
    exclusiveBranch = value;
}

void Actor::Function6c2d00(std::uint32_t value)
{
    emotionType = value;
}

void Actor::Function6c2d10(std::uint32_t value)
{
    emotionValue = value;
}

bool Actor::Function6c8a40(const void* value) const
{
    return value == nullptr;
}

float Actor::Function6c9f00()
{
    return GetActorValue(ActorValue::kDamageResist);
}

const AttackDataPointer& Actor::Function6ca270() const
{
    if (currentProcess) {
        return currentProcess->GetAttackData();
    }
    return emptyAttackData;
}

bool Actor::Function6cc8f0() const
{
    return (boolFlags >> 14) & 1u;
}

ActorMagicCaster* Actor::Function6d4d20(std::int32_t index) const
{
    if (index != 4) {
        return magicCasters[index];
    }
    return nullptr;
}

TESForm* Actor::Function6d7070() const
{
    return selectedPower && selectedPower->formType == FormType::Shout ? selectedPower : nullptr;
}

TESForm* Actor::Function6d7090() const
{
    return selectedPower && selectedPower->formType == FormType::Spell ? selectedPower : nullptr;
}

void Actor::InvalidateCommandedActorEffect(ActiveEffect* effect)
{
    if (currentProcess) {
        return currentProcess->Function726ee0(effect);
    }
}

VOICE_STATE Actor::Function6d9250() const
{
    if (currentProcess) {
        return currentProcess->GetVoiceState();
    }
    return static_cast<VOICE_STATE>(0);
}

TESShout* Actor::Function6d9270() const
{
    if (currentProcess) {
        return currentProcess->GetCurrentShout();
    }
    return nullptr;
}

void Actor::Function6d92d0(TESShoutVariation value)
{
    if (currentProcess) {
        return currentProcess->SetCurrentShoutVariation(value);
    }
}

TESShoutVariation Actor::Function6d92f0() const
{
    if (currentProcess) {
        return currentProcess->GetCurrentShoutVariation();
    }
    return static_cast<TESShoutVariation>(-1);
}
