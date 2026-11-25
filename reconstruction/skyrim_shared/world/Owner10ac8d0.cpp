// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only Stamped as a twin of matched 0x29e6b0 (skyrim_shared/world/BGSLocationRefType): source copied, names replaced by placeholders.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x10ac8d0 Owner10ac8d0::~Owner10ac8d0
// CI hash: 0x10ac8d0 ??_GOwner10ac8d0@@UEAAPEAXI@Z
#include "Owner10ac8d0.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
// CallClearData10ac8d0: GUESS(low) STANDIN
void CallClearData10ac8d0(TESForm* object);

Owner10ac8d0::Owner10ac8d0()
{
}

// Stores its own vftable, clears the TESForm data, then runs the BGSKeyword destructor.
Owner10ac8d0::~Owner10ac8d0()
{
    CallClearData10ac8d0(this);
}
