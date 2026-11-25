// Code origin: names and declarations from CharmedBaryon/CommonLibSSE-NG b93280e (MIT); bodies written from the listing of the pinned image Stamped as a twin of matched 0x26da90 (skyrim_shared/world/TESFlora): source copied, names replaced by placeholders.
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x14eed00 Owner14eed00::Activate
#include "Owner14eed00.h"

// guess: same compiled code as matched 0x26da90 apart from relocated fields; its role here is not established.
bool Owner14eed00::Activate(TESObjectREFR* a_targetRef, TESObjectREFR* a_activatorRef, std::uint8_t a_arg3, TESBoundObject* a_object, std::int32_t a_targetCount)
{
    return produceForm.Activate(a_targetRef, a_activatorRef);
}
