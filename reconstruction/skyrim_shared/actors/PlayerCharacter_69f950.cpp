// Source exposure: mixed (pinned image and RTTI, project receiver layouts, and CommonLibSSE-NG).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies using the cited declarations and the observed receiver offsets.
// Adapted bodies: none
// 0x69f950 Actor::Function69f950
// 0x6af230 Actor::Function6af230
// 0x6cba10 Actor::Function6cba10
// 0x741350 PlayerCharacter::Function741350
// 0x741580 PlayerCharacter::Function741580
// 0x747b70 PlayerCharacter::Function747b70
// 0x7481c0 PlayerCharacter::Function7481c0
// 0x748cd0 PlayerCharacter::Function748cd0
// 0x748cf0 PlayerCharacter::Function748cf0
// 0x749170 PlayerCharacter::Function749170
// 0x749a20 PlayerCharacter::Function749a20
// 0x749e90 PlayerCharacter::Function749e90
// 0x749eb0 PlayerCharacter::Function749eb0
// 0x74a4d0 PlayerCharacter::Function74a4d0
// 0x74a4e0 PlayerCharacter::Function74a4e0
// 0x74a4f0 PlayerCharacter::Function74a4f0
// 0x74c2f0 PlayerCharacter::Function74c2f0
// 0x74c4e0 PlayerCharacter::Function74c4e0
// 0x7517a0 PlayerCharacter::Function7517a0
// 0x7517d0 PlayerCharacter::Function7517d0
// 0x756b80 PlayerCharacter::Function756b80
// 0x756bf0 PlayerCharacter::Function756bf0
// 0x756c90 PlayerCharacter::Function756c90
// 0x757410 PlayerCharacter::Function757410
// 0x757420 PlayerCharacter::Function757420
// 0x757da0 PlayerCharacter::Function757da0
// 0x75a640 PlayerCharacter::Function75a640
// 0x75bc20 PlayerCharacter::Function75bc20
// 0x75bd50 PlayerCharacter::Function75bd50
// 0x75d060 PlayerCharacter::GetNumTints
// 0x75e140 PlayerCharacter::Function75e140
// 0x75e150 PlayerCharacter::Function75e150
// 0x761470 PlayerCharacter::Function761470
// 0x7692c0 PlayerCharacter::~PlayerCharacter
// 0x7692cc PlayerCharacter::~PlayerCharacter
// 0x7692d8 PlayerCharacter::~PlayerCharacter
// 0x7692e4 PlayerCharacter::~PlayerCharacter
// 0x7692f0 PlayerCharacter::~PlayerCharacter
// 0x769314 PlayerCharacter::~PlayerCharacter
// 0x769320 PlayerCharacter::~PlayerCharacter
// 0x76932c PlayerCharacter::~PlayerCharacter
// 0x769338 PlayerCharacter::~PlayerCharacter
// 0x769344 PlayerCharacter::~PlayerCharacter
// 0x769350 PlayerCharacter::~PlayerCharacter
// 0x76acd0 PlayerCharacter::Function76acd0
// 0x76b0b0 PlayerCharacter::Function76b0b0
// 0x76b0c0 PlayerCharacter::Function76b0c0
// 0x76e8c0 PlayerCharacter::Function76e8c0
// 0x76f6f0 PlayerCharacter::Function76f6f0
// 0x772b10 PlayerCharacter::Function772b10
// 0x772b20 PlayerCharacter::Function772b20
// 0x7731a0 PlayerCharacter::Function7731a0
// 0x776890 PlayerCharacter::Function776890
// 0x776fa0 PlayerCharacter::Function776fa0
// 0x778cb0 PlayerCharacter::Function778cb0
// 0x778d60 PlayerCharacter::Function778d60
#include "PlayerCharacter_69f950.h"

// BSTArray, data, capacity, size, BSTSmartPointer, CombatTarget, CombatGroup::targets, TintMask::type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AIProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// PlayerCharacter::singleton: GUESS(low)
// PlayerEventManager, playerEventManager, transitionFlag, globalFlagA, globalFlagB: STANDIN GUESS(low)
// globalFlagC, globalObject, globalFlagD, Function669480, Function818bd0: STANDIN GUESS(low)
// Function728120, Function723560, Function6f6720, Function6f35d0, Function6f35b0, Function78e0a0: GUESS(low)
class AIProcess
{
public:
    void Function728120();
    bool Function723560() const;
    void Function6f6720(Actor* actor);
    void Function6f35d0();
    void Function6f35b0();
};

class PlayerSkills
{
public:
    void Function78e0a0(std::uint32_t skill, std::uint32_t count);
};

class PlayerEventManager
{
public:
    void Function669480(Actor* actor, bool enabled);
};

class TintMask
{
public:
    std::uint8_t padding[0x10];
    std::uint32_t type;
};

struct CombatTarget;

class CombatGroup
{
public:
    void Function818bd0();

    std::uint8_t padding[0x8];
    BSTArray<CombatTarget> targets;
};

extern bool transitionFlag;
extern std::uint8_t globalFlagA;
extern std::uint8_t globalFlagB;
extern bool globalFlagC;
extern void* globalObject;
extern const std::uint8_t globalFlagD;
extern PlayerEventManager* playerEventManager;

PlayerCharacter::PlayerCharacter()
{
}

void Actor::Function69f950()
{
    if (currentProcess) {
        return currentProcess->Function728120();
    }
}

bool Actor::Function6af230() const
{
    if (currentProcess) {
        return currentProcess->Function723560();
    }
    return false;
}

bool Actor::Function6cba10() const
{
    return (actorState1 & 0xF0000000u) == 0x60000000u;
}

bool PlayerCharacter::Function741350() const
{
    return unk8F4 != 0;
}

void PlayerCharacter::Function741580()
{
    transitionFlag = true;
    return Function7415a0(true);
}

NiNode* PlayerCharacter::Function747b70(bool firstPerson) const
{
    return firstPerson ? firstPerson3D : TESObjectREFR::Function2ebce0();
}

void PlayerCharacter::Function7481c0()
{
    return currentProcess->Function6f6720(this);
}

const BSTSmartPointer<BipedAnim>& PlayerCharacter::Function748cd0(bool firstPerson) const
{
    return firstPerson ? firstPersonBiped : Character::GetBiped2();
}

bool PlayerCharacter::Function748cf0(const BSTSmartPointer<BipedAnim>& biped) const
{
    return firstPersonBiped.pointer && firstPersonBiped.pointer == biped.pointer;
}

void PlayerCharacter::Function749170()
{
    playerFlags[3] &= ~0xCu;
    return Actor::Function6d3d30();
}

void PlayerCharacter::Function749a20(std::uint32_t skill, std::uint32_t count)
{
    return skills->Function78e0a0(skill, count < 1 ? 1 : count);
}

void PlayerCharacter::Function749e90()
{
    return currentProcess->Function6f35d0();
}

void PlayerCharacter::Function749eb0()
{
    return currentProcess->Function6f35b0();
}

std::uint8_t PlayerCharacter::Function74a4d0()
{
    return globalFlagA;
}

void PlayerCharacter::Function74a4e0(std::uint8_t value)
{
    globalFlagB = value;
}

std::uint8_t PlayerCharacter::Function74a4f0()
{
    return globalFlagB;
}

void PlayerCharacter::Function74c2f0()
{
    playerFlags[1] &= ~0x40u;
    unk90C = 0;
}

bool PlayerCharacter::Function74c4e0() const
{
    return unkB10 != 0;
}

void* PlayerCharacter::Function7517a0() const
{
    return unk948;
}

bool PlayerCharacter::Function7517d0() const
{
    return (playerFlags[2] & 0xEu) != 0;
}

bool PlayerCharacter::Function756b80() const
{
    return (playerFlags[2] >> 1) & 1u;
}

bool PlayerCharacter::Function756bf0() const
{
    return (playerFlags[2] >> 2) & 1u;
}

std::int32_t PlayerCharacter::Function756c90() const
{
    return unk8A0 < 15 ? unk8A0 : 0;
}

void PlayerCharacter::Function757410()
{
    globalFlagC = false;
}

void PlayerCharacter::Function757420()
{
    globalObject = nullptr;
}

void PlayerCharacter::Function757da0()
{
    singleton->playerFlags[1] &= ~2u;
}

bool PlayerCharacter::Function75a640() const
{
    return (playerFlags[5] >> 4) & 1u;
}

void PlayerCharacter::Function75bc20(Actor* actor)
{
    if (actor) {
        return playerEventManager->Function669480(actor, false);
    }
}

void PlayerCharacter::Function75bd50(Actor* actor)
{
    if (actor) {
        return playerEventManager->Function669480(actor, true);
    }
}

std::uint32_t PlayerCharacter::GetNumTints(std::uint32_t tintType)
{
    std::uint32_t count = 0;
    std::uint64_t remaining = tintMasks.size;
    if (static_cast<std::uint32_t>(remaining)) {
        TintMask* const* entry = tintMasks.data;
        do {
            if ((*entry)->type == tintType) {
                ++count;
            }
            ++entry;
        } while (--remaining);
    }
    return count;
}

std::uint8_t PlayerCharacter::Function75e140()
{
    return globalFlagD;
}

bool PlayerCharacter::Function75e150() const
{
    return ~(boolFlags >> 3) & 1u;
}

std::uint8_t* PlayerCharacter::Function761470()
{
    return &Function1544f0()->runtimeData;
}

CombatGroup* PlayerCharacter::Function76acd0() const
{
    return combatGroup;
}

bool PlayerCharacter::Function76b0b0() const
{
    return playerFlags[3] & 1u;
}

bool PlayerCharacter::Function76b0c0() const
{
    return (playerFlags[3] >> 5) & 1u;
}

bool PlayerCharacter::Function76e8c0() const
{
    return ~playerFlags[4] & 1u;
}

std::uint32_t& PlayerCharacter::Function76f6f0(std::uint32_t& value) const
{
    value = unk924;
    return value;
}

void PlayerCharacter::Function772b10(CombatGroup* group)
{
    combatGroup = group;
}

void PlayerCharacter::Function772b20(const std::uint32_t& value)
{
    unk924 = value;
}

bool PlayerCharacter::Function7731a0() const
{
    return ~static_cast<std::uint8_t>(playerFlags[0] >> 5) & 1u;
}

void PlayerCharacter::Function776890()
{
    if (combatGroup) {
        return combatGroup->Function818bd0();
    }
}

std::uint32_t PlayerCharacter::Function776fa0() const
{
    return combatGroup ? combatGroup->targets.size : 0;
}

void PlayerCharacter::Function778cb0()
{
    trackedItems[0] = nullptr;
    trackedItems[1] = nullptr;
}

TESBoundObject* PlayerCharacter::Function778d60(std::int32_t index) const
{
    return trackedItems[index];
}
