// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original implementations based on the pinned game build.
// 0x5c0700 ActorMagicCaster::Function5c0700
// 0x5c0860 ActorMagicCaster::Function5c0860
// 0x5c08b0 ActorMagicCaster::Function5c08b0
// 0x5c1060 ActorMagicCaster::Function5c1060
// 0x5c10c0 ActorMagicCaster::Function5c10c0
// 0x5c1270 ActorMagicCaster::Function5c1270
// 0x5c17e0 ActorMagicCaster::Function5c17e0
// 0x5cd900 ActorMagicCaster::Function5cd900
// 0x5cdb10 ActorMagicCaster::Function5cdb10
// 0x5cdc00 ActorMagicCaster::Function5cdc00
#include "ActorMagicCaster_5c0700.h"

// CastingDefaultObject, castingDefaultObjects, BGSDefaultObjectManager, TaskQueueInterface, taskQueue, playerCharacter, playerEffectState, saveLoadState: GUESS(low)
struct CastingDefaultObject
{
    std::uint32_t id;
    std::uint8_t padding04[0xC];
};
extern const CastingDefaultObject castingDefaultObjects[];

class BGSDefaultObjectManager
{
public:
    static TESForm* GetDefaultObject(std::uint32_t id);
};

class TaskReference;
class TaskQueueInterface
{
public:
    void Function669050(TaskReference* actor, std::uint32_t source, std::uint8_t mode, std::uint8_t fromCaster);
};

struct PlayerEffectState
{
    std::uint8_t padding000[0x160];
    std::uint32_t count;
};
struct SaveLoadState
{
    std::uint8_t padding000[0x340];
    std::uint32_t flags;
};

extern TaskQueueInterface* taskQueue;
extern Actor* playerCharacter;
extern PlayerEffectState* playerEffectState;
extern SaveLoadState* saveLoadState;

// TestBit: GUESS(low)
inline bool TestBit(std::uint32_t word, std::uint32_t bit)
{
    return ((word >> bit) & 1u) != 0;
}

void ActorMagicCaster::Function5c0700()
{
    if (actor && actor->Function6d9250() && currentSpell &&
        currentSpell->GetSpellType() == MagicSystem::SpellType::kVoicePower) {
        nextTargetUpdate = 0.0f;
        castingTimer = 0.0f;
        return;
    }
    return Function5cd380();
}

bool ActorMagicCaster::Function5c0860() const
{
    return actor && actor->Function6d9250() && currentSpell &&
           currentSpell->GetSpellType() == MagicSystem::SpellType::kVoicePower;
}

void ActorMagicCaster::Function5c08b0(BGSArtObject* art)
{
    const auto currentFlags = flags;
    if (!TestBit(currentFlags, 3)) {
        castingArt = art;
        flags = currentFlags | 4u;
        return Function5c0cd0();
    }
}

void ActorMagicCaster::Function5c1060()
{
    if ((actor->actorState2 & 0xE0u) >= 0x60u &&
        !(actor == playerCharacter && playerEffectState->count > 0)) {
        taskQueue->Function669050(reinterpret_cast<TaskReference*>(actor),
                                  static_cast<std::uint32_t>(castingSource), 1, 1);
    }
}

void ActorMagicCaster::Function5c10c0()
{
    auto source = castingSource;
    auto* currentActor = actor;
    if (!TestBit(saveLoadState->flags, 1)) {
        taskQueue->Function669050(reinterpret_cast<TaskReference*>(currentActor), static_cast<std::uint32_t>(source), 0, 1);
        return;
    }
    return currentActor->Function6d7770(source, false, true);
}

TESForm* ActorMagicCaster::Function5c1270() const
{
    const auto id = castingDefaultObjects[static_cast<std::int32_t>(castingSource)].id;
    if (id != 0x174) {
        return BGSDefaultObjectManager::GetDefaultObject(id);
    }
    return nullptr;
}

LightPointer& ActorMagicCaster::Function5c17e0(LightPointer& output) const
{
    if (light) {
        return output.Function150cb10(light);
    }
    return output;
}

void ActorMagicCaster::Function5cd900(MagicItem* spell)
{
    for (std::int32_t sound = 0; sound <= 4; ++sound) {
        PrepareSound(static_cast<MagicSystem::SoundID>(sound), spell);
    }
}

void ActorMagicCaster::Function5cdb10(std::uint32_t index)
{
    if (sounds.data[index].Functioncc9730()) {
        sounds.data[index].Functioncc9dd0();
    }
}

void ActorMagicCaster::Function5cdc00()
{
    state = State::kUnk04;
    if (currentSpell->GetCastingType() == MagicSystem::CastingType::kConcentration) {
        projectileTimer = 0.0f;
    }
    return StartCastImpl();
}
