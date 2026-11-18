// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); bodies written from the listing of the pinned image
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x26da90 TESFlora::Activate
// 0x26da40 TESFlora::InitItemImpl
#include "TESFlora.h"

bool TESFlora::Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount)
{
    return produceForm.Activate(a_targetRef, a_activatorRef);
}

void TESFlora::InitItemImpl()
{
    if (!IsInitialized()) {
        TESObjectACTI::InitItemImpl();
        produceForm.CopyFromForm(this);
        SetFormFlag(true);
    }
}
