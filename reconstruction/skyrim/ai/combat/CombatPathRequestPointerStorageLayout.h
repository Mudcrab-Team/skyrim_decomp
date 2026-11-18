// Source exposure: mixed (public data declarations, authorized game-code sibling role hints and independent target RTTI/field-load evidence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: public data declaration adaptation and original narrowed prefix composition; no external implementation body reused.
// Declaration source: powerof3/CommonLibSSE@654e55f7979c1733033d5dbef176e43827bac944 include/RE/{C/CombatPath.h,C/CombatObject.h,A/AITimer.h}; GPL-3.0.
// Declaration source: CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a include/RE/{N/NiRefObject.h,B/BSPointerHandle.h}; MIT, retained in included public storage.
// CombatPath, CombatObject, AITimer: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// NiRefObject, ActorHandle: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetRequest, spRequest, CombatPathingRequest: SIBLING(fo4-private@1b765c70, author-permission)
// CombatPathRequestPointerStorageLayout, CombatPathDataStorageLayout, CombatPathTimerStorageLayout, CombatPathActorHandleStorageLayout, CombatPathRequestPointeeLayout, requestPointer: GUESS(medium) STANDIN
#pragma once
#include <cstddef>
#include <cstdint>
#include "../../../gamebryo/nimain/NiRefObjectStorageLayout.h"
namespace ResearchLayouts {
struct CombatPathActorHandleStorageLayout { std::uint32_t value; };
struct CombatPathTimerStorageLayout { float aiTimer; float timer; };
enum class CombatPathStateStorageLayout : std::uint32_t {};
enum class CombatPathSpeedStorageLayout : std::uint32_t {};
class CombatPathDataStorageLayout : public NiRefObjectStorageLayout {
public:
    ~CombatPathDataStorageLayout() override;
    CombatPathActorHandleStorageLayout actor;
    CombatPathStateStorageLayout state;
    CombatPathStateStorageLayout lastState;
    CombatPathSpeedStorageLayout speed;
    CombatPathTimerStorageLayout retryTimer;
    CombatPathTimerStorageLayout waitTimer;
    void* unk30;
};
class CombatPathRequestPointeeLayout;
class CombatPathRequestPointerStorageLayout : public CombatPathDataStorageLayout {
public:
    ~CombatPathRequestPointerStorageLayout() override;
    CombatPathRequestPointeeLayout* requestPointer;
};
static_assert(sizeof(CombatPathActorHandleStorageLayout)==4,"public handle storage");
static_assert(offsetof(CombatPathActorHandleStorageLayout,value)==0,"public handle word");
static_assert(sizeof(CombatPathTimerStorageLayout)==8,"public two-float timer");
static_assert(offsetof(CombatPathTimerStorageLayout,aiTimer)==0,"public timer field");
static_assert(offsetof(CombatPathTimerStorageLayout,timer)==4,"public timer field");
static_assert(sizeof(CombatPathStateStorageLayout)==4,"public enum width");
static_assert(sizeof(CombatPathSpeedStorageLayout)==4,"public enum width");
static_assert(sizeof(CombatPathDataStorageLayout)==56,"complete public path base storage");
static_assert(offsetof(CombatPathDataStorageLayout,actor)==16,"public actor handle offset");
static_assert(offsetof(CombatPathDataStorageLayout,state)==20,"public state offset");
static_assert(offsetof(CombatPathDataStorageLayout,lastState)==24,"public last state offset");
static_assert(offsetof(CombatPathDataStorageLayout,speed)==28,"public speed offset");
static_assert(offsetof(CombatPathDataStorageLayout,retryTimer)==32,"public timer offset");
static_assert(offsetof(CombatPathDataStorageLayout,waitTimer)==40,"public timer offset");
static_assert(offsetof(CombatPathDataStorageLayout,unk30)==48,"public unknown pointer offset");
static_assert(sizeof(CombatPathRequestPointerStorageLayout)==64,"represented initial pointer prefix only");
static_assert(offsetof(CombatPathRequestPointerStorageLayout,requestPointer)==56,"target request-base pointer offset");
}
