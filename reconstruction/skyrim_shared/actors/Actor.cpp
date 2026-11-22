// Source exposure: mixed. Existing bodies were drafted by claude-sonnet-5-5 from the pinned image.
// Code origin: original reconstruction from the pinned image and community declarations; GetMountInteraction from the listing and the CrashLogger PDB name.
// Consulted (private, not in repo): decompiler control-flow hints.
// Adapted bodies: none in this change.
// 0x6d5e30 Actor::Function6d5e30
// 0x7cf670 Actor::Function7cf670
// 0x6d6690 Actor::Function6d6690
// 0x6b5820 Actor::Function6b5820
// 0x6b5bf0 Actor::Function6b5bf0
// 0x6b21b0 Actor::ProcessEvent
// 0x2e7fc0 Actor::HasOutfitItems
// 0x6797a0 Actor::GetLevel
// 0x6cb920 Actor::IsAttacking
// 0x6d7750 Actor::HasShout
// 0x6af1b0 Actor::GetMoveDirectionRelativeToFacing
// 0x6d92b0 Actor::GetVoiceRecoveryTime
// 0x687c20 Actor::IsInRagdollState
// 0x6c5440 Actor::GetActorValueModifier
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2e6710 Actor::GetMountInteraction
#include "Actor.h"

// Actor::Function6d5e30: GUESS(low); the compared form type is Armor, whose enchantment is applied through the instant magic caster.
void Actor::Function6d5e30(TESForm* a_item, TESObjectREFR* a_target)
{
    if (a_item->GetFormType() != FormType::Armor) {
        return;
    }
    EnchantmentItem* enchantment = GetFormEnchantment(a_item, a_target);
    if (!enchantment) {
        return;
    }
    GetMagicCaster(MagicSystem::CastingSource::kInstant)->CastEnchantment(enchantment, a_item, false);
}

// Actor::Function7cf670: GUESS(low); dispatch of one actor update through the task queue or directly.
void Actor::Function7cf670(bool a_flag)
{
    if (Function6e49e0(a_flag)) {
        taskQueue->Function668780(this, a_flag);
        return;
    }
    Function6a4a10(a_flag);
}

// Actor::Function6d6690: GUESS(low); interrupts every non-null magic caster slot with the argument.
void Actor::Function6d6690(bool a_refund)
{
    MagicCaster** slot = magicCasters;
    for (std::size_t remaining = 4; remaining != 0; --remaining) {
        if (*slot) {
            (*slot)->InterruptCast(a_refund);
        }
        ++slot;
    }
}

// Actor::Function6b5820: GUESS(low); the process rotation, or the origin point when the process is absent.
void Actor::Function6b5820(NiPoint3& a_out) const
{
    const NiPoint3& rotation = unknown38 ? unknown38->Function7233b0() : niPointZero;
    a_out.x = rotation.x;
    a_out.y = rotation.y;
    a_out.z = rotation.z;
}

// Actor::Function6b5bf0: GUESS(low); the character controller's context state, 0 when either link is absent.
hkpCharacterStateType Actor::Function6b5bf0()
{
    AIProcess* process = unknown38;
    if (!process) {
        return static_cast<hkpCharacterStateType>(0);
    }
    bhkCharacterController* controller = process->Function722110();
    if (!controller) {
        return static_cast<hkpCharacterStateType>(0);
    }
    return controller->context.Functionb97880();
}

bool Actor::GetMountInteraction(MountInteraction*& a_out)
{
    extraList.GetMountInteraction(a_out);
    return a_out != nullptr;
}

std::uint16_t Actor::GetLevel() const
{
    return static_cast<TESNPC*>(data.objectReference)->GetLevel();
}

bool Actor::IsAttacking() const
{
    return GetAttackState() != ATTACK_STATE_ENUM::kNone;
}

bool Actor::HasShout(TESShout* a_shout) const
{
    return static_cast<TESNPC*>(data.objectReference)->HasShout(a_shout);
}

float Actor::GetMoveDirectionRelativeToFacing()
{
    return currentProcess ? currentProcess->GetMoveDirectionRelativeToFacing() : 0.0f;
}

float Actor::GetVoiceRecoveryTime()
{
    return currentProcess ? currentProcess->GetVoiceRecoveryTime() : 0.0f;
}

void Actor::SetAvoidanceDisabled(bool)
{
}

void Actor::UseSkill(ActorValue, float, TESForm*)
{
}

void Actor::AddPerk(BGSPerk*, std::uint32_t)
{
}

bool Actor::IsInRagdollState() const
{
    if (IsParalyzed()) {
        return true;
    }
    if (IsDead() && !IsReanimating()) {
        return true;
    }
    const auto knock = GetKnockState();
    if (knock != KNOCK_STATE_ENUM::kNormal && knock != KNOCK_STATE_ENUM::kGetUp) {
        return true;
    }
    if (IsUnconscious()) {
        return true;
    }
    return false;
}

float Actor::GetActorValueModifier(ACTOR_VALUE_MODIFIER a_modifier, ActorValue a_value) const
{
    const Modifiers* mods;
    switch (a_value) {
    case ActorValue::kHealth:
        mods = &healthModifiers;
        break;
    case ActorValue::kMagicka:
        mods = &magickaModifiers;
        break;
    case ActorValue::kStamina:
        mods = &staminaModifiers;
        break;
    case ActorValue::kVoicePoints:
        mods = &voicePointsModifiers;
        break;
    default:
        mods = avStorage.GetModifiers(a_value);
        break;
    }
    return mods ? mods->modifiers[static_cast<int>(a_modifier)] : 0.0f;
}

// FindOutfitExtra: GUESS(low); callee of HasOutfitItems.
bool Actor::HasOutfitItems(BGSOutfit* a_outfit)
{
    if (a_outfit) {
        InventoryChanges* changes = MakeInventoryChanges();
        std::uint32_t     id      = a_outfit->formID;
        for (auto* entries = changes->entryList; entries && entries->item; entries = entries->next) {
            for (auto* lists = entries->item->extraLists; lists && (lists->next || lists->item);
                 lists       = lists->next) {
                OutfitExtra* extra = FindOutfitExtra(lists->item);
                if (extra && (id == 0 || extra->outfitID == id)) {
                    return true;
                }
            }
        }
    }
    return false;
}

// RACE_DATA, RACE_DATA::Flag, kFlies, TESRace::data, RACE_DATA::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown20 to unknown100: GUESS(low); the race bases and members before data, as unresolved words at their offsets.
struct RACE_DATA {
    enum Flag : std::uint32_t { kFlies = 1u << 7 };
    Flag flags;
};
class TESRace {
public:
    virtual ~TESRace();
    std::uint64_t unknown08;  // 08
    std::uint64_t unknown10;  // 10
    std::uint64_t unknown18;  // 18
    std::uint64_t unknown20;  // 20
    std::uint64_t unknown28;  // 28
    std::uint64_t unknown30;  // 30
    std::uint64_t unknown38;  // 38
    std::uint64_t unknown40;  // 40
    std::uint64_t unknown48;  // 48
    std::uint64_t unknown50;  // 50
    std::uint64_t unknown58;  // 58
    std::uint64_t unknown60;  // 60
    std::uint64_t unknown68;  // 68
    std::uint64_t unknown70;  // 70
    std::uint64_t unknown78;  // 78
    std::uint64_t unknown80;  // 80
    std::uint64_t unknown88;  // 88
    std::uint64_t unknown90;  // 90
    std::uint64_t unknown98;  // 98
    std::uint64_t unknownA0;  // A0
    std::uint64_t unknownA8;  // A8
    std::uint64_t unknownB0;  // B0
    std::uint64_t unknownB8;  // B8
    std::uint64_t unknownC0;  // C0
    std::uint64_t unknownC8;  // C8
    std::uint64_t unknownD0;  // D0
    std::uint64_t unknownD8;  // D8
    std::uint64_t unknownE0;  // E0
    std::uint64_t unknownE8;  // E8
    std::uint64_t unknownF0;  // F0
    std::uint64_t unknownF8;  // F8
    std::uint64_t unknown100;  // 100
    RACE_DATA data;  // 108
};
static_assert(offsetof(TESRace, data) == 0x108, "race data offset");

// BSSoundHandle, kInvalidID, soundID, assumeSuccess, AssumedState, kInitialized, state, Play: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSAudioManager, GetSingleton, BuildSoundDataFromEditorID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
struct BSSoundHandle {
    enum : std::uint32_t { kInvalidID = static_cast<std::uint32_t>(-1) };
    enum class AssumedState { kInitialized };
    bool Play();

    std::uint32_t soundID = kInvalidID;
    bool assumeSuccess = false;
    AssumedState state = AssumedState::kInitialized;
};
static_assert(sizeof(BSSoundHandle) == 0xc, "sound handle layout");

class BSAudioManager {
public:
    static BSAudioManager* GetSingleton();
    void BuildSoundDataFromEditorID(BSSoundHandle& a_sound, const char* a_name, std::uint32_t a_flags);
};

// HasLandingFlag: GUESS(low); common bit extraction for two flag types.
static bool HasLandingFlag(std::uint32_t a_flags)
{
    return ((a_flags >> 7) & 1) != 0;
}

int Actor::ProcessEvent(MoveFinishSink* a_sink, const bhkCharacterMoveFinishEvent* a_event)
{
    auto* sinkAddress = reinterpret_cast<char*>(a_sink);
    auto* actor = reinterpret_cast<Actor*>(sinkAddress - offsetof(Actor, moveFinishSink));
    auto& parentCell = *reinterpret_cast<TESObjectCELL**>(
        sinkAddress + (static_cast<std::ptrdiff_t>(offsetof(TESObjectREFR, parentCell)) -
                       static_cast<std::ptrdiff_t>(offsetof(Actor, moveFinishSink))));
    if (actor->Get3D2() && parentCell) {
        actor->HandleMoveFinish(a_event);
        auto* process = *reinterpret_cast<AIProcess**>(
            sinkAddress + (offsetof(Actor, currentProcess) - offsetof(Actor, moveFinishSink)));
        auto* controller = process ? process->GetCharController() : nullptr;
        if (controller && HasLandingFlag(static_cast<std::uint32_t>(controller->flags))) {
            const auto* race = *reinterpret_cast<TESRace* const*>(
                sinkAddress + (offsetof(Actor, race) - offsetof(Actor, moveFinishSink)));
            if (!HasLandingFlag(race->data.flags)) {
                const float damage = actor->Function6bd530(controller->GetFallDistance(), defaultFallScale);
                if (damage > 0.0f) {
                    actor->ApplyFallDamage(damage, nullptr, true);
                    if (actor == playerActor) {
                        BSSoundHandle sound;
                        const char* soundName = !(damage > landingSoundThreshold) ? lightLandingSound : heavyLandingSound;
                        BSAudioManager::GetSingleton()->BuildSoundDataFromEditorID(sound, soundName, 0x12);
                        sound.Play();
                    }
                    actor->SetFallDamageState(true, true);
                }
            }
            controller->flags = static_cast<CHARACTER_FLAGS>(
                static_cast<std::uint32_t>(controller->flags) &
                ~static_cast<std::uint32_t>(CHARACTER_FLAGS::kHitDamage));
        }
        actor->Unk_68();
    }
    return 0;
}
