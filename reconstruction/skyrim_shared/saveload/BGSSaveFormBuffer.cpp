// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none.
// 0x639860 BGSSaveFormBuffer::GetActor
#include "BGSSaveFormBuffer.h"

// BGSSaveFormBuffer::GetActor: RVA 0x639860, 38 bytes. The actor check reads the reference's form
// type after the null test, so the type byte is only loaded for a non-null reference.
Actor* BGSSaveFormBuffer::GetActor()
{
    TESObjectREFR* ref = GetReference();
    if (ref) {
        return ref->formType == FormType::ActorCharacter ? static_cast<Actor*>(ref) : nullptr;
    }
    return nullptr;
}

// Accepted leaf retained from the integrated version.
// GetForm: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void* BGSSaveFormBuffer::GetForm() const
{
    return member;
}
