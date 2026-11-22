// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and the community declarations only
// 0x26164c TESImageSpaceModifiableForm::~TESImageSpaceModifiableForm
// Adapted bodies: none
// TESImageSpaceModifiableForm::~TESImageSpaceModifiableForm: GUESS(low); the this-adjusting deleting-destructor thunk
// Prefix88, ThunkHost: GUESS(low); stand-ins that place the secondary base at the thunk's offset
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned image).
// CI hash: 0x26164c ??_EThunkHost@@WII@EAAPEAXI@Z
#include "TESImageSpaceModifiableForm.h"

class Prefix88
{
public:
    virtual ~Prefix88() {}
    std::uint8_t pad[0x80];
};
static_assert(sizeof(Prefix88) == 0x88, "layout");

// The secondary base sits at 0x88; its vftable carries the compared adjustor thunk.
class ThunkHost : public Prefix88, public TESImageSpaceModifiableForm
{
public:
    ThunkHost();
    ~ThunkHost() override;
};

// Not compared: defined so the compiler emits the vftable and, beside it, the deleting destructor
// and its adjustor thunk (cookbook rules 14 and 25).
ThunkHost::ThunkHost()
{
}

ThunkHost::~ThunkHost()
{
}

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
TESImageSpaceModifiableForm::TESImageSpaceModifiableForm()
{
}

// ClearDataComponent: the target has no work to do.
void TESImageSpaceModifiableForm::ClearDataComponent()
{
}

// InitializeDataComponent: the target clears the pointer at +0x8.
void TESImageSpaceModifiableForm::InitializeDataComponent()
{
    data08 = nullptr;
}
