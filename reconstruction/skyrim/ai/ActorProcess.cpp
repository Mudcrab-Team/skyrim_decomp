// Source exposure: mixed (pinned image listings and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// ActorProcess: EXE_RTTI
// GetEquippedLeftHand: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Code origin: existing project getter GetEquippedLeftHand; new methods from the pinned image and CommonLibSSE-NG field declarations.
// Adapted bodies: none
// 0x6eb4a0 ActorProcess::GetEquippedLeftHand
// 0x7265a0 ActorProcess::Function7265a0
// 0x726fa0 ActorProcess::Function726fa0
// 0x726fc0 ActorProcess::Function726fc0
// 0x727020 ActorProcess::Function727020
// 0x727060 ActorProcess::Function727060
// 0x727080 ActorProcess::Function727080
// 0x7270d0 ActorProcess::Function7270d0
// 0x7270f0 ActorProcess::Function7270f0
// 0x727110 ActorProcess::Function727110
// 0x7271e0 ActorProcess::Function7271e0
// 0x727200 ActorProcess::Function727200
// 0x727220 ActorProcess::Function727220
// 0x727240 ActorProcess::Function727240
// 0x727260 ActorProcess::Function727260
// 0x727280 ActorProcess::Function727280
// 0x7272a0 ActorProcess::Function7272a0
// 0x727420 ActorProcess::Function727420
// 0x727440 ActorProcess::Function727440
// 0x727460 ActorProcess::Function727460
// 0x7274a0 ActorProcess::Function7274a0
// 0x727ae0 ActorProcess::Function727ae0
// 0x727b00 ActorProcess::Function727b00
// 0x727cf0 ActorProcess::Function727cf0
// 0x727d10 ActorProcess::Function727d10
// 0x727d30 ActorProcess::Function727d30
// 0x727d50 ActorProcess::Function727d50
// 0x727d70 ActorProcess::Function727d70
// 0x727d90 ActorProcess::Function727d90
// 0x727db0 ActorProcess::Function727db0
// 0x727df0 ActorProcess::Function727df0
// 0x727e10 ActorProcess::Function727e10
// 0x727e30 ActorProcess::Function727e30
// 0x727e50 ActorProcess::Function727e50
// 0x727e70 ActorProcess::Function727e70
// 0x727e90 ActorProcess::Function727e90
// 0x727ee0 ActorProcess::Function727ee0
// 0x727f00 ActorProcess::Function727f00
// 0x727f20 ActorProcess::Function727f20
// 0x727f40 ActorProcess::Function727f40
// 0x727f60 ActorProcess::Function727f60
// 0x7284e0 ActorProcess::Function7284e0
// 0x728500 ActorProcess::Function728500
// 0x728520 ActorProcess::Function728520
// 0x728540 ActorProcess::Function728540
// 0x728560 ActorProcess::Function728560
// 0x728580 ActorProcess::Function728580
// 0x6f5220 ActorProcess::Function6f5220
// 0x6f64b0 ActorProcess::Function6f64b0
// 0x6f6de0 ActorProcess::Function6f6de0
// 0x6f6e10 ActorProcess::Function6f6e10
// 0x6f6f30 ActorProcess::Function6f6f30
// 0x6fe020 ActorProcess::Function6fe020
// 0x6fe5d0 ActorProcess::Function6fe5d0
// 0x6ff4b0 ActorProcess::Function6ff4b0
// 0x6ff500 ActorProcess::Function6ff500
// 0x6ffe80 ActorProcess::Function6ffe80
// 0x6ffef0 ActorProcess::Function6ffef0
// 0x720f60 ActorProcess::Function720f60
// 0x7216e0 ActorProcess::Function7216e0
// 0x7231e0 ActorProcess::HasRunOncePackage
// 0x726eb0 ActorProcess::Function726eb0
// 0x7270a0 ActorProcess::Function7270a0
// 0x727eb0 ActorProcess::Function727eb0
#include "ActorProcess.h"

// MiddleHighProcessData::unk328, MiddleHighProcessData::unk248, MiddleHighProcessData::unk31E, MiddleHighProcessData::unk31F, MiddleHighProcessData::alphaMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MiddleHighProcessData::scriptRefractPower, MiddleHighProcessData::unk31A, MiddleHighProcessData::unk180, MiddleHighProcessData::forceNextUpdate, MiddleHighProcessData::summonedCreature: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MiddleHighProcessData::damageRootNode, MiddleHighProcessData::headNode, MiddleHighProcessData::torsoNode, MiddleHighProcessData::unk321, MiddleHighProcessData::faceNodeSkinned: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MiddleHighProcessData::alwaysHit, MiddleHighProcessData::doNoDamage, MiddleHighProcessData::preventCombat, MiddleHighProcessData::faceAnimationData, MiddleHighProcessData::bleedoutRate: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MiddleHighProcessData::unk2B0, MiddleHighProcessData::unk2B8, MiddleHighProcessData::bleedoutAttacker, MiddleHighProcessData::unk32A, MiddleHighProcessData::killQueued: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MiddleHighProcessData::wardState, MiddleHighProcessData::soulTrapped: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pad000, pad0F4, pad148, pad168, pad178: STANDIN GUESS(low)
// pad068, pad190, pad21C, pad319, unknown000, unknown0DC, unknown134, unknown13C: STANDIN GUESS(low)
// ProcessData::unk60, ProcessData::unk188, ProcessData::commandedActor: GUESS(low); the pointer members read by the compared bodies
// HighProcessData::lastExtDoorActivated, HighProcessData::fadeState, HighProcessData::fadeAlpha, HighProcessData::headTrackTarget, HighProcessData::headTracked: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HighProcessData::pathLookAtTarget, HighProcessData::unk2D0, HighProcessData::animAction, HighProcessData::breathTimer, HighProcessData::detectionModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// HighProcessData::detectionModifierTimer, HighProcessData::doorActivated, HighProcessData::unk3F8, MiddleHighProcessData::unk317, MiddleHighProcessData::unk318, ObjectRefHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ActorProcess::HasRunOncePackage: CRASHLOGGER_PDB(59818@2026.10.24)
// HighProcessData::unk3FA, kNullHandle, defaultBreathTimer, defaultDetectionModifierTimer: GUESS(low); kNullHandle is named after the symbol map, the two floats are unnamed constants the bodies read
// pad188, pad240, pad250, pad2BC, pad2D0: STANDIN GUESS(low)
// pad31B, pad320, pad322, pad326, pad32B: STANDIN GUESS(low)
// Function733f00, Function736230, Function736a30, Function736c00: GUESS(low)
struct ActorProcess::ProcessData
{
    std::uint8_t pad000[0x60];
    void* unk60;
    std::uint8_t pad068[0x84];
    std::uint32_t bleedoutAttacker;
    MagicSystem::WardState wardState;
    std::uint8_t pad0F4[0x24];
    NiNode* damageRootNode[6];
    std::uint8_t pad148[0x10];
    NiAVObject* headNode;
    NiAVObject* torsoNode;
    std::uint8_t pad168[0x8];
    BSFaceGenNiNode* faceNodeSkinned;
    std::uint8_t pad178[0x8];
    std::uint64_t unk180;
    void* unk188;
    std::uint8_t pad190[0x88];
    ObjectRefHandle commandedActor;
    std::uint8_t pad21C[0x1c];
    BSFaceGenAnimationData* faceAnimationData;
    std::uint8_t pad240[0x8];
    std::uint64_t unk248;
    std::uint8_t pad250[0x60];
    float unk2B0;
    float bleedoutRate;
    float unk2B8;
    std::uint8_t pad2BC[0xc];
    float alphaMult;
    float scriptRefractPower;
    std::uint8_t pad2D0[0x47];
    bool unk317;
    bool unk318;
    std::uint8_t pad319[0x1];
    bool unk31A;
    std::uint8_t pad31B[0x1];
    bool summonedCreature;
    bool forceNextUpdate;
    bool unk31E;
    bool unk31F;
    std::uint8_t pad320[0x1];
    bool unk321;
    std::uint8_t pad322[0x1];
    bool alwaysHit;
    bool doNoDamage;
    bool soulTrapped;
    std::uint8_t pad326[0x2];
    bool unk328;
    bool preventCombat;
    bool unk32A;
    std::uint8_t pad32B[0x6];
    bool killQueued;

    void Function733f00();
    void Function736230();
    void Function736a30();
    void Function736c00();
};

struct ActorProcess::HighProcessData
{
    std::uint8_t unknown000[0xd8];
    ObjectRefHandle lastExtDoorActivated;
    std::uint8_t unknown0DC[0x54];
    std::uint32_t fadeState;
    float fadeAlpha;
    std::uint8_t unknown138[0x8];
    ObjectRefHandle headTrackTarget[6];
    bool headTracked[6];
    std::uint8_t unknown15E[0x1e];
    ObjectRefHandle pathLookAtTarget;
    std::uint8_t unknown180[0x150];
    std::uint64_t unk2D0;
    std::uint16_t animAction;
    std::uint8_t unknown2DA[0x4a];
    float breathTimer;
    std::uint8_t unknown328[0x78];
    float detectionModifier;
    float detectionModifierTimer;
    std::uint8_t unknown3A8[0x50];
    std::int16_t unk3F8;
    std::int16_t unk3FA;
    std::uint8_t unknown3FC[0x74];
    bool doorActivated;

};

void* ActorProcess::GetEquippedLeftHand() const
{
    return member;
}

void ActorProcess::Function7265a0()
{
    if (middleHigh) {
        middleHigh->unk328 = true;
    }
}

void ActorProcess::Function726fa0(std::uint64_t a_value)
{
    if (middleHigh) {
        middleHigh->unk248 = a_value;
    }
}

std::uint64_t ActorProcess::Function726fc0() const
{
    return middleHigh ? middleHigh->unk248 : 0;
}

void ActorProcess::Function727020(bool a_value)
{
    if (middleHigh) {
        middleHigh->unk31E = a_value;
    }
}

void ActorProcess::Function727060(bool a_value)
{
    if (middleHigh) {
        middleHigh->unk31F = a_value;
    }
}

bool ActorProcess::Function727080() const
{
    return middleHigh && middleHigh->unk31F;
}

void ActorProcess::Function7270d0(float a_value)
{
    if (middleHigh) {
        middleHigh->alphaMult = a_value;
    }
}

float ActorProcess::Function7270f0() const
{
    return middleHigh ? middleHigh->scriptRefractPower : 0.0f;
}

void ActorProcess::Function727110(float a_value)
{
    if (middleHigh) {
        middleHigh->scriptRefractPower = a_value;
    }
}

void ActorProcess::Function7271e0()
{
    if (middleHigh) {
        middleHigh->unk31A = true;
    }
}

std::uint64_t ActorProcess::Function727200() const
{
    return middleHigh ? middleHigh->unk180 : 0;
}

void ActorProcess::Function727220(std::uint64_t a_value)
{
    if (middleHigh) {
        middleHigh->unk180 = a_value;
    }
}

void ActorProcess::Function727240(bool a_value)
{
    if (middleHigh) {
        middleHigh->forceNextUpdate = a_value;
    }
}

bool ActorProcess::Function727260() const
{
    return middleHigh && middleHigh->forceNextUpdate;
}

void ActorProcess::Function727280(bool a_value)
{
    if (middleHigh) {
        middleHigh->summonedCreature = a_value;
    }
}

bool ActorProcess::Function7272a0() const
{
    return middleHigh && middleHigh->summonedCreature;
}

NiNode* ActorProcess::Function727420(std::int32_t a_index) const
{
    return middleHigh ? middleHigh->damageRootNode[a_index] : nullptr;
}

NiAVObject* ActorProcess::Function727440() const
{
    return middleHigh ? middleHigh->headNode : nullptr;
}

NiAVObject* ActorProcess::Function727460() const
{
    return middleHigh ? middleHigh->torsoNode : nullptr;
}

void ActorProcess::Function7274a0(bool a_value)
{
    if (middleHigh) {
        middleHigh->unk321 = a_value;
    }
}

BSFaceGenNiNode* ActorProcess::Function727ae0() const
{
    return middleHigh ? middleHigh->faceNodeSkinned : nullptr;
}

void ActorProcess::Function727b00(BSFaceGenNiNode* a_value)
{
    if (middleHigh) {
        middleHigh->faceNodeSkinned = a_value;
    }
}

bool ActorProcess::Function727cf0() const
{
    return middleHigh && middleHigh->alwaysHit;
}

void ActorProcess::Function727d10(bool a_value)
{
    if (middleHigh) {
        middleHigh->alwaysHit = a_value;
    }
}

bool ActorProcess::Function727d30() const
{
    return middleHigh && middleHigh->doNoDamage;
}

void ActorProcess::Function727d50(bool a_value)
{
    if (middleHigh) {
        middleHigh->doNoDamage = a_value;
    }
}

bool ActorProcess::Function727d70() const
{
    return middleHigh && middleHigh->preventCombat;
}

void ActorProcess::Function727d90(bool a_value)
{
    if (middleHigh) {
        middleHigh->preventCombat = a_value;
    }
}

void ActorProcess::Function727db0(BSFaceGenAnimationData* a_value)
{
    if (middleHigh) {
        middleHigh->faceAnimationData = a_value;
    }
}

void ActorProcess::Function727df0(float a_value)
{
    if (middleHigh) {
        middleHigh->bleedoutRate = a_value;
    }
}

float ActorProcess::Function727e10() const
{
    return middleHigh ? middleHigh->unk2B0 : 0.0f;
}

void ActorProcess::Function727e30(float a_value)
{
    if (middleHigh) {
        middleHigh->unk2B0 = a_value;
    }
}

float ActorProcess::Function727e50() const
{
    return middleHigh ? middleHigh->unk2B8 : 0.0f;
}

void ActorProcess::Function727e70(float a_value)
{
    if (middleHigh) {
        middleHigh->unk2B8 = a_value;
    }
}

void ActorProcess::Function727e90(const std::uint32_t& a_value)
{
    if (middleHigh) {
        middleHigh->bleedoutAttacker = a_value;
    }
}

bool ActorProcess::Function727ee0() const
{
    return middleHigh && middleHigh->unk32A;
}

void ActorProcess::Function727f00(bool a_value)
{
    if (middleHigh) {
        middleHigh->unk32A = a_value;
    }
}

bool ActorProcess::Function727f20() const
{
    return middleHigh && middleHigh->killQueued;
}

void ActorProcess::Function727f40(bool a_value)
{
    if (middleHigh) {
        middleHigh->killQueued = a_value;
    }
}

void ActorProcess::Function727f60(MagicSystem::WardState a_value)
{
    if (middleHigh) {
        middleHigh->wardState = a_value;
    }
}

void ActorProcess::Function7284e0()
{
    if (middleHigh) {
        middleHigh->Function733f00();
    }
}

void ActorProcess::Function728500()
{
    if (middleHigh) {
        middleHigh->Function736230();
    }
}

void ActorProcess::Function728520()
{
    if (middleHigh) {
        middleHigh->Function736a30();
    }
}

void ActorProcess::Function728540()
{
    if (middleHigh) {
        middleHigh->Function736c00();
    }
}

void ActorProcess::Function728560()
{
    if (middleHigh) {
        middleHigh->soulTrapped = true;
    }
}

bool ActorProcess::Function728580() const
{
    return middleHigh && middleHigh->soulTrapped;
}

float ActorProcess::Function6f5220() const
{
    return high ? high->breathTimer : defaultBreathTimer;
}

void ActorProcess::Function6f64b0(std::uint16_t a_action, std::uint64_t a_value)
{
    if (high) {
        high->animAction = a_action;
        high->unk2D0 = a_value;
    }
}

ObjectRefHandle& ActorProcess::Function6f6de0(ObjectRefHandle& a_handle) const
{
    a_handle = high ? high->lastExtDoorActivated : kNullHandle;
    return a_handle;
}

void ActorProcess::Function6f6e10(const ObjectRefHandle& a_handle, bool a_activated)
{
    if (high) {
        high->lastExtDoorActivated = a_handle;
        high->doorActivated = a_activated;
    }
}

void ActorProcess::Function6f6f30(float a_value)
{
    if (high) {
        high->detectionModifierTimer = defaultDetectionModifierTimer;
        high->detectionModifier = a_value;
    }
}

bool ActorProcess::Function6fe020() const
{
    bool result = false;
    if (high) {
        switch (high->fadeState) {
        case 3:
        case 4:
        case 5:
        case 6:
            result = true;
            break;
        default:
            break;
        }
    }

    return result;
}

float ActorProcess::Function6fe5d0() const
{
    return high ? high->fadeAlpha : 1.0f;
}

ObjectRefHandle& ActorProcess::Function6ff4b0(ObjectRefHandle& a_handle) const
{
    a_handle = high ? high->pathLookAtTarget : kNullHandle;
    return a_handle;
}

void ActorProcess::Function6ff500(const ObjectRefHandle& a_handle)
{
    if (high && high->pathLookAtTarget == a_handle) {
        high->pathLookAtTarget = kNullHandle;
    }
}

std::int32_t ActorProcess::Function6ffe80(std::int32_t a_index) const
{
    if (high) {
        if (a_index == 0) {
            return high->unk3F8;
        }

        if (a_index == 1) {
            return high->unk3FA;
        }
    }

    return -1;
}

void ActorProcess::Function6ffef0()
{
    if (high) {
        high->unk3F8 = -1;
        high->unk3FA = -1;
    }
}

bool ActorProcess::Function720f60() const
{
    return middleHigh && middleHigh->unk188;
}

bool ActorProcess::Function7216e0() const
{
    return middleHigh && (middleHigh->unk318 | middleHigh->unk317);
}

bool ActorProcess::HasRunOncePackage() const
{
    return (middleHigh ? middleHigh->unk60 : nullptr) != nullptr;
}

ObjectRefHandle& ActorProcess::Function726eb0(ObjectRefHandle& a_handle) const
{
    a_handle = middleHigh ? middleHigh->commandedActor : kNullHandle;
    return a_handle;
}

float ActorProcess::Function7270a0() const
{
    return middleHigh ? middleHigh->alphaMult : 1.0f;
}

ObjectRefHandle& ActorProcess::Function727eb0(ObjectRefHandle& a_handle) const
{
    const std::uint32_t& source = middleHigh ? middleHigh->bleedoutAttacker : kNullHandle.native_handle;
    a_handle.native_handle = source;
    return a_handle;
}
