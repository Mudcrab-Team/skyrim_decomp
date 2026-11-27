// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x38d7f0 BGSEntryPointPerkEntry::MultiplyOnePlusActorValueMult
// Adapted bodies: none
#include "BGSEntryPointPerkEntry_38d7f0.h"

// Multiplies the output float argument by one plus an actor value times a perk factor.
void BGSEntryPointPerkEntry::MultiplyOnePlusActorValueMult(TESObjectREFR* a_refr, std::uint32_t a_functionType, std::uint8_t a_numArgs, void** a_args, BGSEntryPointFunctionData* a_data)
{
    if (a_functionType != 0) {
        return;
    }
    if (g_entryPointOneArgCount != a_numArgs) {
        return;
    }
    for (std::uint32_t i = 0; i < a_numArgs; ++i) {
        if (!a_args[i]) {
            return;
        }
    }
    if (a_data && a_data->GetType() != BGSEntryPointFunctionData::FunctionType::kTwoValue) {
        return;
    }
    float* value = static_cast<float*>(a_args[0]);
    Actor* actor = nullptr;
    if (a_refr && a_refr->formType == 0x3E) {
        actor = static_cast<Actor*>(a_refr);
    }
    auto* twoValue = static_cast<BGSEntryPointFunctionDataTwoValue*>(a_data);
    float mult = twoValue->data2;
    if (actor) {
        *value = (actor->GetActorValue(static_cast<std::uint32_t>(twoValue->data1)) * mult + 1.0f) * *value;
    }
}
