// ActorTargetPrefix: STANDIN GUESS(medium); typed partial receiver view, not a complete object.
// Origin: original declarations adapted from pinned community member declarations.
// Source exposure: mixed (target access/RTTI observations and community headers).
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-reconstruction.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstddef>
#include <cstdint>
#include "ActorTargetInterfaces.h"
namespace P206Target {
// P206Target: GUESS(low); namespace separates partial research views from complete classes.
// UnknownVTable, FormPrefix, HandleRefPrefix, InterfacePrefix, ExtraDataListPrefix: STANDIN GUESS(medium); descriptive names for represented prefixes.
// ReferencePrefix, ActorTargetPrefix, ReferenceData, MagicTargetPrefix, ActorStatePrefix: STANDIN GUESS(medium); composition views, not complete class definitions.
// TESFileArray, TESObjectCELL, LOADED_REF_DATA, TESBoundObject, TESForm, BGSLocation: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// BSExtraData, SpellDispelData, ActorMover, MovementControllerNPC, AIProcess: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// NiPoint3, ObjectRefHandle, ActorHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
struct UnknownVTable;
class TESFileArray;
class TESObjectCELL;
struct LOADED_REF_DATA;
class TESBoundObject;
class TESForm;
class BGSLocation;
class BSExtraData;
struct SpellDispelData;
class ActorMover;
class MovementControllerNPC;
class AIProcess;
struct NiPoint3 { float x, y, z; };
struct ObjectRefHandle { std::uint32_t nativeHandle; };
struct ActorHandle { std::uint32_t nativeHandle; };
// Field spellings below follow the pinned public declarations, except explicitly unknown storage.
// sourceFiles, formFlags, formID, inGameFormFlags, formType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
struct FormPrefix {
    const UnknownVTable* vtable;
    TESFileArray* sourceFiles;
    std::uint32_t formFlags;
    std::uint32_t formID;
    std::uint16_t inGameFormFlags;
    std::uint8_t formType;
    std::uint8_t pad1B;
    std::uint32_t pad1C;
};
// _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
struct HandleRefPrefix {
    const UnknownVTable* vtable;
    volatile std::uint32_t _refCount;
    std::uint32_t _pad0C;
};
struct InterfacePrefix { const UnknownVTable* vtable; };
// extraData, presence, lockThread, lockState: GUESS(medium); names for the target BaseExtraList pointer pair and lock words.
// ExtraDataList prefix: target GetByType (RVA 0x17e840) uses the presence pointer at 0x10 and lock at 0x18.
// Its data pointer and virtual-table word follow the later runtime public variant; their exact roles remain hypotheses.
struct ExtraDataListPrefix {
    const UnknownVTable* vtable;
    BSExtraData* extraData;
    const std::uint8_t* presence;
    std::uint32_t lockThread;
    std::uint32_t lockState;
};
// objectReference, angle, location: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
struct ReferenceData {
    TESBoundObject* objectReference;
    NiPoint3 angle;
    NiPoint3 location;
};
// data, parentCell, loadedData, extraList, refScale, modelState, preDestroyed: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Form, handle ref, animation sink and graph-holder boundaries follow this target's RTTI (0, 0x20, 0x30, 0x38).
// Opaque pointees are deliberate; this header supplies no allocation or deletion operations.
template <class ExtraList = ExtraDataListPrefix>
struct ReferencePrefix {
    FormPrefix form;
    HandleRefPrefix handleReference;
    InterfacePrefix animationEventSink;
    InterfacePrefix animationGraphHolder;
    ReferenceData data;
    TESObjectCELL* parentCell;
    LOADED_REF_DATA* loadedData;
    ExtraList extraList;
    std::uint64_t unknown90;
    std::uint16_t refScale;
    std::int8_t modelState;
    bool preDestroyed;
    std::uint32_t pad9C;
};
// postUpdateDispelList, flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
struct MagicTargetPrefix {
    const UnknownVTable* vtable;
    SpellDispelData* postUpdateDispelList;
    std::uint8_t flags;
    std::uint8_t pad11;
    std::uint16_t pad12;
    std::uint32_t pad14;
};
// actorState1, actorState2: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Bit meanings are not encoded here; the state words remain integer representations.
struct ActorStatePrefix {
    const UnknownVTable* vtable;
    std::uint32_t actorState1;
    std::uint32_t actorState2;
};
// boolBits, updateTargetTimer, criticalStage, currentProcess, dialogueItemTarget, currentCombatTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// myKiller, checkMyDeadBodyTimer, voiceTimer, underWaterTimer, thiefCrimeStamp, actionValue, timerOnAction: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// editorLocCoord, editorLocRot, editorLocForm, editorLocation, actorMover, movementController: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// Unaccessed fields are public hypotheses. currentProcess is observed at 0xf8 in several independent rows.
// movementController is a pointer representation only; no reference-count or ownership policy is inferred.
template <class ExtraList = ExtraDataListPrefix, class Process = AIProcess, class Movement = MovementControllerNPC>
struct ActorTargetPrefix {
    ReferencePrefix<ExtraList> reference;
    MagicTargetPrefix magicTarget;
    InterfacePrefix actorValueOwner;
    ActorStatePrefix actorState;
    InterfacePrefix transformDeltaSink;
    InterfacePrefix characterMoveFinishSink;
    InterfacePrefix postAnimationUpdate;
    std::uint32_t boolBits;
    float updateTargetTimer;
    std::uint32_t criticalStage;
    std::uint32_t padF4;
    Process* currentProcess;
    ObjectRefHandle dialogueItemTarget;
    ActorHandle currentCombatTarget;
    ActorHandle myKiller;
    float checkMyDeadBodyTimer;
    float voiceTimer;
    float underWaterTimer;
    std::int32_t thiefCrimeStamp;
    std::int32_t actionValue;
    float timerOnAction;
    std::uint32_t unknown124;
    NiPoint3 editorLocCoord;
    float editorLocRot;
    TESForm* editorLocForm;
    BGSLocation* editorLocation;
    ActorMover* actorMover;
    Movement* movementController;
};
static_assert(sizeof(FormPrefix) == 0x20, "represented public form prefix");
static_assert(sizeof(HandleRefPrefix) == 0x10, "represented handle-ref prefix");
static_assert(sizeof(ExtraDataListPrefix) == 0x20, "target variant extra-list representation");
static_assert(offsetof(ReferencePrefix<>, data) == 0x40, "target object-reference access anchor");
static_assert(offsetof(ReferencePrefix<>, extraList) == 0x70, "target extra-list receiver anchor");
static_assert(offsetof(ActorTargetPrefix<>, magicTarget) == 0xa0, "target secondary RTTI receiver");
static_assert(offsetof(ActorTargetPrefix<>, actorValueOwner) == 0xb8, "target secondary RTTI receiver");
static_assert(offsetof(ActorTargetPrefix<>, actorState) == 0xc0, "target secondary RTTI receiver");
static_assert(offsetof(ActorTargetPrefix<>, currentProcess) == 0xf8, "target process-pointer access anchor");
static_assert(offsetof(ActorTargetPrefix<>, actorMover) == 0x148, "target mover access anchor");
static_assert(offsetof(ActorTargetPrefix<>, movementController) == 0x150, "target movement-controller access anchor");
}
