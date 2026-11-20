// Source exposure: mixed (pinned image and public declarations).
// Code origin: original partial layouts for the stair agent's actor lookup.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MovementHandlerAgentStairsHelper: EXE_RTTI
// TESForm, FormType, FormType::ActorCharacter, TESForm::LookupByID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT)
// StairAgentOwner, StairAgentOwnerVTable, GetActorFormID, RefreshActor, owner, actor: GUESS(low)
#pragma once

#include <cstdint>

enum class FormType : std::uint8_t
{
    ActorCharacter = 0x3e
};

class TESForm
{
public:
    static TESForm* LookupByID(std::uint32_t formID);

    std::uint8_t unknown00[0x1a];
    FormType formType;
};

struct StairAgentOwner;

struct StairAgentOwnerVTable
{
    std::uint8_t unknown00[8];
    std::uint32_t (*GetActorFormID)(StairAgentOwner*);
};

struct StairAgentOwner
{
    const StairAgentOwnerVTable* vtable;
};

class MovementHandlerAgentStairsHelper
{
public:
    void RefreshActor();

private:
    std::uint8_t unknown00[0x10];
    StairAgentOwner* owner;
    std::uint8_t unknown18[8];
    TESForm* actor;
};
