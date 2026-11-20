// Actor: GUESS(low) STANDIN
/*
 * Actor: original reconstruction; signatures and layout are inferred.
 * Build: sse-steam-1-7-104. Compared: RVA 0x6b1560 20 bytes; RVA 0x6c8a60 20 bytes; RVA 0xa0d530 20 bytes; RVA 0x6a6940 21 bytes; RVA 0x6a69a0 21 bytes; RVA 0x6a69e0 21 bytes; RVA 0x6a6bc0 21 bytes; RVA 0x6a5b30 30 bytes; RVA 0x6a5b60 30 bytes; RVA 0x6a5b90 30 bytes; RVA 0x6a6ff0 30 bytes; RVA 0x6d3d30 31 bytes.
 * Origin: original reconstruction.
 * Source exposure: binary-analysis, community-headers.
 * Drafted by: gpt-6.1-terra.
 * Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
 * Evidence: findings/ghidra-import.md
 * Labels: v2
 * Compared bodies alone claim byte matches; declarations and signatures remain inferred.
 * Types adapted from CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a (MIT); unverified against this build.
 * No external body adapted. Stand-ins are unverified.
 */
#pragma once
#include <cstdint>

// Actor, Actor::Function6c8a60, Actor::StateCode: GUESS(low) STANDIN
// Actor::Subobject, ActorSubobject: GUESS(low) STANDIN
// Actor::Forward6a6940, Actor::Forward6a69a0, Actor::Forward6a69e0, Actor::Forward6a6bc0: GUESS(low) STANDIN
// Actor::Forward6a5b30, Actor::Forward6a5b60, Actor::Forward6a5b90, Actor::Forward6a6ff0: GUESS(low) STANDIN
// ActorSubobject::Call791800, ActorSubobject::Call791cb0, ActorSubobject::Call791750, ActorSubobject::Call790a90: GUESS(low) STANDIN
// ActorSubobject::Call792510, ActorSubobject::Call7924b0, ActorSubobject::Call792570, ActorSubobject::Call791e60: GUESS(low) STANDIN
// Actor::LevelValue, papyrus::Actor::LevelValue: GUESS(low) STANDIN
class ActorSubobject {
public:
    void Call791800();
    void Call791cb0();
    void Call791750();
    void Call790a90();
    void Call792510(void*);
    void Call7924b0(void*);
    void Call792570(void*);
    void Call791e60(void*);
};
class BSFixedString;
class ActorRelated;
class Actor {
public:
    const BSFixedString& GetResponseString() const;
    ActorRelated* Related();
    void* Forward6d3d30();
    int StateCode();
    ActorSubobject* Subobject();
    std::uint16_t LevelValue();
    bool Function6c8a60();
    void Forward6a6940();
    void Forward6a69a0();
    void Forward6a69e0();
    void Forward6a6bc0();
    void Forward6a5b30(void*);
    void Forward6a5b60(void*);
    void Forward6a5b90(void*);
    void Forward6a6ff0(void*);
};
namespace papyrus { namespace Actor {
std::uint32_t LevelValue(void*, void*, ::Actor*);
} }
// ActorRelated, Actor::Related, Actor::Forward6d3d30, ActorRelated::Call237e10: GUESS(low) STANDIN
class ActorRelated { public: void* Call237e10(); };

/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

// BSFixedString, FixedStrings, FixedStrings::GetSingleton, Actor::GetResponseString: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::npcRoot, FixedStrings::npc, FixedStrings::npcHead, FixedStrings::npcPelvis_Pelv, FixedStrings::npcSpine, FixedStrings::npcSpine1, FixedStrings::npcSpine2, FixedStrings::npcLFoot, FixedStrings::npcRFoot, FixedStrings::npcLCalf: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::npcRCalf, FixedStrings::specialIdle_Cast, FixedStrings::specialIdle_AreaEffect, FixedStrings::attachSound, FixedStrings::soundMarker, FixedStrings::skinnedDecalNode, FixedStrings::decalNode, FixedStrings::modelSwapNode, FixedStrings::open, FixedStrings::close: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::dvpg, FixedStrings::prn, FixedStrings::weapon, FixedStrings::weaponSword, FixedStrings::weaponDagger, FixedStrings::weaponAxe, FixedStrings::weaponMace, FixedStrings::shield, FixedStrings::weaponBack, FixedStrings::weaponBow: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::quiver, FixedStrings::editorMarker, FixedStrings::editorMarker0, FixedStrings::editorMarker1, FixedStrings::editorMarker2, FixedStrings::arrowQuiver, FixedStrings::markerSource, FixedStrings::markerTarget, FixedStrings::attachLight, FixedStrings::skin: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::faceGenEars, FixedStrings::unequip, FixedStrings::laserSight, FixedStrings::aimSight, FixedStrings::decal, FixedStrings::permanentDecal, FixedStrings::grabLeft, FixedStrings::grabRight, FixedStrings::arrow0, FixedStrings::arrowBone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::bsFaceGenNiNodeSkinned, FixedStrings::entryPoint, FixedStrings::npcLUpperArm, FixedStrings::npcLForearm, FixedStrings::npcRUpperArm, FixedStrings::npcLookNode, FixedStrings::npcTail1, FixedStrings::npcTailHub, FixedStrings::npcPelvis, FixedStrings::talking: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::camera1st, FixedStrings::camera3rd, FixedStrings::headMeshForExport_FaceGenAndMorphs_0, FixedStrings::pinnedLimb, FixedStrings::backpack, FixedStrings::projectileNode, FixedStrings::blastRadiusNode, FixedStrings::torchFire, FixedStrings::lightOn, FixedStrings::npcCOM: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::skinAttachment, FixedStrings::npcNeck, FixedStrings::nifRound, FixedStrings::scb, FixedStrings::upperBody, FixedStrings::lightOff, FixedStrings::npcHeadMagicNode, FixedStrings::npcLMagicNode, FixedStrings::npcRMagicNode, FixedStrings::magicLeft: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::magicRight, FixedStrings::magicOther, FixedStrings::cameraControl, FixedStrings::npcRoot1, FixedStrings::saddleBone, FixedStrings::perchFireNode, FixedStrings::graphDeleting, FixedStrings::isBlocking, FixedStrings::isShouting, FixedStrings::isPlayer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::isnpc, FixedStrings::iIsPlayer, FixedStrings::fScale, FixedStrings::femaleOffset, FixedStrings::isFirstPerson, FixedStrings::i1stPerson, FixedStrings::fIsFirstPerson, FixedStrings::bHumanoidFootIKEnable, FixedStrings::iSyncIdleLocomotion, FixedStrings::iSyncTurnState: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::isAttackReady, FixedStrings::bVoiceReady, FixedStrings::bMLh_Ready, FixedStrings::bMRh_Ready, FixedStrings::bEquipOK, FixedStrings::hitFrame, FixedStrings::isSprinting, FixedStrings::iSyncSprintState, FixedStrings::weapAdj, FixedStrings::weaponSpeedMult: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::leftWeaponSpeedMult, FixedStrings::bowZoom, FixedStrings::bBowZoomed, FixedStrings::iLeftHandType, FixedStrings::iRightHandType, FixedStrings::iLeftHandEquipped, FixedStrings::iRightHandEquipped, FixedStrings::bLeftHand, FixedStrings::bRightHand, FixedStrings::fIdleTimer: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::injured, FixedStrings::land, FixedStrings::bCrashLand, FixedStrings::landTypeIndex, FixedStrings::actorResponse, FixedStrings::playerCharacterResponse, FixedStrings::tailPitchCurrent, FixedStrings::tailPitchMax, FixedStrings::tailYawCurrent, FixedStrings::tailYawMax: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::lookAtHeadingMaxAngle, FixedStrings::english, FixedStrings::russian, FixedStrings::polish, FixedStrings::mLh_SpellFire_Event, FixedStrings::mRh_SpellFire_Event, FixedStrings::voice_SpellFire_Event, FixedStrings::arrowRelease, FixedStrings::endAnim, FixedStrings::stopEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::tweenEntryDirection, FixedStrings::tweenPosition, FixedStrings::tweenRotation, FixedStrings::hasTweenSpeed, FixedStrings::tweenSpeed, FixedStrings::bTweenUpdate, FixedStrings::targetLocation, FixedStrings::movementDirection, FixedStrings::fCastStrength, FixedStrings::staggerMagnitude: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::staggerDirection, FixedStrings::isBusy, FixedStrings::imod, FixedStrings::rimod, FixedStrings::distToGoal, FixedStrings::preHitFrame, FixedStrings::weaponSwing, FixedStrings::weaponLeftSwing, FixedStrings::attackWinStart, FixedStrings::attackWinEnd: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::velocityZ, FixedStrings::speed, FixedStrings::turnDelta, FixedStrings::direction, FixedStrings::speedSampled, FixedStrings::horseSpeedSampled, FixedStrings::lookAtOutOfRange, FixedStrings::aimHeadingMax, FixedStrings::aimPitchMax, FixedStrings::aimHeadingCurrent: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::aimPitchCurrent, FixedStrings::iSyncForwardState, FixedStrings::iSyncStrafeState, FixedStrings::bAnimationDriven, FixedStrings::bAllowRotation, FixedStrings::bIsSynced, FixedStrings::bSpeedSynced, FixedStrings::bDisableInterp, FixedStrings::iGetUpType, FixedStrings::objectActivated: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// FixedStrings::fFlameProjectileLength, FixedStrings::pairedKillTarget, FixedStrings::bAimActive, FixedStrings::turnDynamic, FixedStrings::bForceIdleStop, FixedStrings::constraintOffset, FixedStrings::left, FixedStrings::pickup, FixedStrings::pathTweenerStart, FixedStrings::pathTweenerEnd: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
class BSFixedString { const char* data; };
class FixedStrings { public:
    static FixedStrings* GetSingleton();
    BSFixedString npcRoot;
    BSFixedString npc;
    BSFixedString npcHead;
    BSFixedString npcPelvis_Pelv;
    BSFixedString npcSpine;
    BSFixedString npcSpine1;
    BSFixedString npcSpine2;
    BSFixedString npcLFoot;
    BSFixedString npcRFoot;
    BSFixedString npcLCalf;
    BSFixedString npcRCalf;
    BSFixedString specialIdle_Cast;
    BSFixedString specialIdle_AreaEffect;
    BSFixedString attachSound;
    BSFixedString soundMarker;
    BSFixedString skinnedDecalNode;
    BSFixedString decalNode;
    BSFixedString modelSwapNode;
    BSFixedString open;
    BSFixedString close;
    BSFixedString dvpg;
    BSFixedString prn;
    BSFixedString weapon;
    BSFixedString weaponSword;
    BSFixedString weaponDagger;
    BSFixedString weaponAxe;
    BSFixedString weaponMace;
    BSFixedString shield;
    BSFixedString weaponBack;
    BSFixedString weaponBow;
    BSFixedString quiver;
    BSFixedString editorMarker;
    BSFixedString editorMarker0;
    BSFixedString editorMarker1;
    BSFixedString editorMarker2;
    BSFixedString arrowQuiver;
    BSFixedString markerSource;
    BSFixedString markerTarget;
    BSFixedString attachLight;
    BSFixedString skin;
    BSFixedString faceGenEars;
    BSFixedString unequip;
    BSFixedString laserSight;
    BSFixedString aimSight;
    BSFixedString decal;
    BSFixedString permanentDecal;
    BSFixedString grabLeft;
    BSFixedString grabRight;
    BSFixedString arrow0;
    BSFixedString arrowBone;
    BSFixedString bsFaceGenNiNodeSkinned;
    BSFixedString entryPoint;
    BSFixedString npcLUpperArm;
    BSFixedString npcLForearm;
    BSFixedString npcRUpperArm;
    BSFixedString npcLookNode;
    BSFixedString npcTail1;
    BSFixedString npcTailHub;
    BSFixedString npcPelvis;
    BSFixedString talking;
    BSFixedString camera1st;
    BSFixedString camera3rd;
    BSFixedString headMeshForExport_FaceGenAndMorphs_0;
    BSFixedString pinnedLimb;
    BSFixedString backpack;
    BSFixedString projectileNode;
    BSFixedString blastRadiusNode;
    BSFixedString torchFire;
    BSFixedString lightOn;
    BSFixedString npcCOM;
    BSFixedString skinAttachment;
    BSFixedString npcNeck;
    BSFixedString nifRound;
    BSFixedString scb;
    BSFixedString upperBody;
    BSFixedString lightOff;
    BSFixedString npcHeadMagicNode;
    BSFixedString npcLMagicNode;
    BSFixedString npcRMagicNode;
    BSFixedString magicLeft;
    BSFixedString magicRight;
    BSFixedString magicOther;
    BSFixedString cameraControl;
    BSFixedString npcRoot1;
    BSFixedString saddleBone;
    BSFixedString perchFireNode;
    BSFixedString graphDeleting;
    BSFixedString isBlocking;
    BSFixedString isShouting;
    BSFixedString isPlayer;
    BSFixedString isnpc;
    BSFixedString iIsPlayer;
    BSFixedString fScale;
    BSFixedString femaleOffset;
    BSFixedString isFirstPerson;
    BSFixedString i1stPerson;
    BSFixedString fIsFirstPerson;
    BSFixedString bHumanoidFootIKEnable;
    BSFixedString iSyncIdleLocomotion;
    BSFixedString iSyncTurnState;
    BSFixedString isAttackReady;
    BSFixedString bVoiceReady;
    BSFixedString bMLh_Ready;
    BSFixedString bMRh_Ready;
    BSFixedString bEquipOK;
    BSFixedString hitFrame;
    BSFixedString isSprinting;
    BSFixedString iSyncSprintState;
    BSFixedString weapAdj;
    BSFixedString weaponSpeedMult;
    BSFixedString leftWeaponSpeedMult;
    BSFixedString bowZoom;
    BSFixedString bBowZoomed;
    BSFixedString iLeftHandType;
    BSFixedString iRightHandType;
    BSFixedString iLeftHandEquipped;
    BSFixedString iRightHandEquipped;
    BSFixedString bLeftHand;
    BSFixedString bRightHand;
    BSFixedString fIdleTimer;
    BSFixedString injured;
    BSFixedString land;
    BSFixedString bCrashLand;
    BSFixedString landTypeIndex;
    BSFixedString actorResponse;
    BSFixedString playerCharacterResponse;
    BSFixedString tailPitchCurrent;
    BSFixedString tailPitchMax;
    BSFixedString tailYawCurrent;
    BSFixedString tailYawMax;
    BSFixedString lookAtHeadingMaxAngle;
    BSFixedString english;
    BSFixedString russian;
    BSFixedString polish;
    BSFixedString mLh_SpellFire_Event;
    BSFixedString mRh_SpellFire_Event;
    BSFixedString voice_SpellFire_Event;
    BSFixedString arrowRelease;
    BSFixedString endAnim;
    BSFixedString stopEffect;
    BSFixedString tweenEntryDirection;
    BSFixedString tweenPosition;
    BSFixedString tweenRotation;
    BSFixedString hasTweenSpeed;
    BSFixedString tweenSpeed;
    BSFixedString bTweenUpdate;
    BSFixedString targetLocation;
    BSFixedString movementDirection;
    BSFixedString fCastStrength;
    BSFixedString staggerMagnitude;
    BSFixedString staggerDirection;
    BSFixedString isBusy;
    BSFixedString imod;
    BSFixedString rimod;
    BSFixedString distToGoal;
    BSFixedString preHitFrame;
    BSFixedString weaponSwing;
    BSFixedString weaponLeftSwing;
    BSFixedString attackWinStart;
    BSFixedString attackWinEnd;
    BSFixedString velocityZ;
    BSFixedString speed;
    BSFixedString turnDelta;
    BSFixedString direction;
    BSFixedString speedSampled;
    BSFixedString horseSpeedSampled;
    BSFixedString lookAtOutOfRange;
    BSFixedString aimHeadingMax;
    BSFixedString aimPitchMax;
    BSFixedString aimHeadingCurrent;
    BSFixedString aimPitchCurrent;
    BSFixedString iSyncForwardState;
    BSFixedString iSyncStrafeState;
    BSFixedString bAnimationDriven;
    BSFixedString bAllowRotation;
    BSFixedString bIsSynced;
    BSFixedString bSpeedSynced;
    BSFixedString bDisableInterp;
    BSFixedString iGetUpType;
    BSFixedString objectActivated;
    BSFixedString fFlameProjectileLength;
    BSFixedString pairedKillTarget;
    BSFixedString bAimActive;
    BSFixedString turnDynamic;
    BSFixedString bForceIdleStop;
    BSFixedString constraintOffset;
    BSFixedString left;
    BSFixedString pickup;
    BSFixedString pathTweenerStart;
    BSFixedString pathTweenerEnd;
};
static_assert(sizeof(FixedStrings) == 0x5f0, "FixedStrings size");
