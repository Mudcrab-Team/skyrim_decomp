// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image and pinned community declarations.
// Source exposure: mixed (local binary analysis and pinned community declarations).
// Code origin: original reconstruction from the pinned image and community declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x796460 MovementControllerNPC::Function796460
// 0x796ac0 MovementControllerNPC::Unk_0F
#include "MovementControllerNPC.h"

void MovementControllerNPC::Function798450()
{
    if (!Function1214580(this, movementContext)) {
        return;
    }

    const bool selected = Function11D69F0(Unk_05());

    if (unknown1C0 != 0x0E) {
        MovementEventTarget* target = Unk_03(&movementEventFilter);
        if (target != nullptr) {
            target->SetFlag(!selected);
        }
    }

    unknown1C0 = 0x2;
}

void MovementControllerNPC::Function796460()
{
    if (unknown0A0 && unknown0A1) {
        return;
    }

    const MovementLinkTarget* link = unknown090;
    const void* eventType = (link->unknown1F8 != nullptr && Function673b40(const_cast<MovementLinkTarget*>(link))) ? movementEventTypeA : movementEventTypeB;

    if (Function1213890(static_cast<MovementOwner*>(this), eventType)) {
        unknown0A0 = true;
        unknown0A1 = true;
    }
}

std::uint8_t MovementControllerNPC::Unk_0F()
{
    return unknown1C5;
}
