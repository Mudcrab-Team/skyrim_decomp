// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x7559f0 PlayerCharacter::SetAIDriven
// Adapted bodies: none
#include "PlayerCharacter_7559f0.h"

void PlayerCharacter::SetAIDriven(bool aiDriven)
{
    ControlHolder* holder = *GetControlHolder();
    if (aiDriven) {
        holder->Enable();
    } else {
        holder->Disable();
        TESPackage* package = unkF8->GetPackageThatIsRunning();
        if (package && package->unk24 == 0x25) {
            ResetPlayerCamera(gPlayerCamera);
        }
    }
    unkBE8.aiControlledPackage = aiDriven;
}
