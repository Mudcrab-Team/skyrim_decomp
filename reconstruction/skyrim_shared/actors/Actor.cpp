// Source exposure: mixed. Existing bodies were drafted by claude-sonnet-5-5 from the pinned image.
// Code origin: original reconstruction from the pinned image and community declarations.
// Consulted (private, not in repo): decompiler control-flow hints.
// Adapted bodies: none in this change.
// FindOutfitExtra: GUESS(low); callee of HasOutfitItems.
// 0x6b21b0 Actor::ProcessEvent
// 0x2e7fc0 Actor::HasOutfitItems
// 0x6797a0 Actor::GetLevel
// 0x6cb920 Actor::IsAttacking
// 0x6d7750 Actor::HasShout
// 0x6af1b0 Actor::GetMoveDirectionRelativeToFacing
// 0x6d92b0 Actor::GetVoiceRecoveryTime
// 0x687c20 Actor::IsInRagdollState
// 0x6c5440 Actor::GetActorValueModifier
#include "Actor.h"

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

// playerActor, defaultFallScale, landingSoundThreshold, heavyLandingSound, lightLandingSound: GUESS(low); fall-damage and audio inputs.
// HasLandingFlag: GUESS(low); common bit extraction for two flag types.
extern Actor* playerActor;
extern const float defaultFallScale;
extern float landingSoundThreshold;
extern const char heavyLandingSound[];
extern const char lightLandingSound[];

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
