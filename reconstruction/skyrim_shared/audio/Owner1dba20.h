// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: original declarations from the pinned image and labelled community layouts. Stamped as a twin of matched 0x1db800 (skyrim_shared/audio/BGSPickupPutdownSounds): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESForm: STANDIN EXE_RTTI
// Function1dba20, Owner1dba20: GUESS(low) STANDIN
// BaseFormComponent: GUESS(low) STANDIN
#pragma once
#include "BGSPickupPutdownSounds.h"

class Owner1dba20 : public BaseFormComponent
{
public:
    Owner1dba20();
    virtual void ClearDataComponent();
    virtual void InitializeDataComponent();
    virtual ~Owner1dba20();

    static BGSSoundDescriptorForm* Function1dba20(TESForm* a_form);
    static BGSSoundDescriptorForm* GetPutdownSound(TESForm* a_form);

    BGSSoundDescriptorForm* field08;  // 08
    BGSSoundDescriptorForm* field10;  // 10
};
static_assert(sizeof(Owner1dba20) == 0x18, "Owner1dba20 size");
