// Source exposure: mixed (pinned image listings and community declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: existing project getter GetEquippedLeftHand; new methods from the pinned image and CommonLibSSE-NG field declarations. Stamped as a twin of matched 0x7284e0 (skyrim/ai/ActorProcess): source copied, names replaced by placeholders.
// 0xaf37a0 Owneraf37a0::Functionaf37a0
#include "Owneraf37a0.h"

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
// Owneraf37a0::HasRunOncePackage: GUESS(low) STANDIN
// HighProcessData::unk3FA: GUESS(low); kNullHandle is named after the symbol map, the two floats are unnamed constants the bodies read
// pad188, pad240, pad250, pad2BC, pad2D0: STANDIN GUESS(low)
// pad31B, pad320, pad322, pad326, pad32B: STANDIN GUESS(low)
// Function733f00, Function736230, Function736a30, Function736c00: GUESS(low)
struct Owneraf37a0::ProcessData
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

struct Owneraf37a0::HighProcessData
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

// guess: same compiled code as matched 0x7284e0 apart from relocated fields; its role here is not established.
void Owneraf37a0::Functionaf37a0()
{
    if (middleHigh) {
        middleHigh->Function733f00();
    }
}
