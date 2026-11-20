// Source exposure: mixed (pinned image listings and CommonLibSSE-NG declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original bodies from the pinned listings and the cited declarations.
// Adapted bodies: none
// 0x795ea0 MovementControllerNPC::Function795ea0
// 0x7968b0 MovementControllerNPC::Function7968b0
// 0x7968e0 MovementControllerNPC::Function7968e0
// 0x796910 MovementControllerNPC::Function796910
// 0x797d00 MovementControllerNPC::Function797d00
// 0x798150 MovementControllerNPC::Function798150
// 0x7983c0 MovementControllerNPC::Function7983c0
// 0x7983e0 MovementControllerNPC::Function7983e0
// 0x798400 MovementControllerNPC::Function798400
// 0x7984d0 MovementControllerNPC::Function7984d0
// 0x7986b0 MovementControllerNPC::Function7986b0
// 0x7986e0 MovementControllerNPC::Function7986e0
// 0x798710 MovementControllerNPC::Function798710
// 0x798740 MovementControllerNPC::Function798740
// 0x7987f0 MovementControllerNPC::Function7987f0
// 0x798820 MovementControllerNPC::Function798820
// 0x798850 MovementControllerNPC::Function798850
// 0x798bf0 MovementControllerNPC::Function798bf0
// 0x79a628 MovementControllerNPC::~MovementControllerNPC
// 0x79a634 MovementControllerNPC::~MovementControllerNPC
// 0x79a640 MovementControllerNPC::~MovementControllerNPC
// 0x79a64c MovementControllerNPC::~MovementControllerNPC
// 0x79a658 MovementControllerNPC::~MovementControllerNPC
// 0x79a664 MovementControllerNPC::~MovementControllerNPC
#include "MovementControllerNPC_795ea0.h"

#include <utility>

// animationSet, value08, value10, motionGateKey: STANDIN GUESS(low)
struct MovementCallbackData
{
    void* animationSet;
    std::uint32_t value08;
    std::uint32_t padding0C;
    std::uint32_t value10;
};

extern const MovementKey motionGateKey;

// transition3, transition4, transition5, transition6, transition7: STANDIN GUESS(low)
// transition9, transition10, transition11: STANDIN GUESS(low)
extern const void* transition3;
extern const void* transition4;
extern const void* transition5;
extern const void* transition6;
extern const void* transition7;
extern const void* transition9;
extern const void* transition10;
extern const void* transition11;

// The constructor emits the vtables used by the compared destructor thunks.
MovementControllerNPC::MovementControllerNPC()
{
}

bool MovementControllerNPC::Function795ea0() const
{
    return unk078 != nullptr;
}

bool MovementControllerNPC::Function7968b0() const
{
    return state == 1 || state == 2 || state == 3 ||
           state == 7 || state == 8 || state == 10 ||
           state == 11 || state == 12 || state == 13 ||
           state == 14;
}

bool MovementControllerNPC::Function7968e0() const
{
    return state == 0 || state == 4 || state == 5 ||
           state == 9;
}

bool MovementControllerNPC::Function796910() const
{
    return ((state - 4u) & ~(1u | 4u)) == 0 && state != 8;
}

void MovementControllerNPC::Function797d00()
{
    if (!directControlChanged) {
        directControlChanged = true;
        Function798b40();
    }
}

void MovementControllerNPC::Function798150()
{
    if (!plannerControlChanged) {
        plannerControlChanged = true;
        Function798b40();
    }
}

void MovementControllerNPC::Function7983c0(bool value)
{
    if (unk1CA != value) {
        unk1CA = value;
        Function798b40();
    }
}

void MovementControllerNPC::Function7983e0(bool value)
{
    if (unk1CB != value) {
        unk1CB = value;
        Function798b40();
    }
}

void MovementControllerNPC::Function798400(bool disabled)
{
    if (transitionState != 14) {
        if (auto* control = FunctionSlot03(motionGateKey)) {
            control->FunctionSlot01(static_cast<std::uint32_t>(disabled) ^ 1u);
        }
    }
}

void MovementControllerNPC::Function7984d0()
{
    if (Function1214580(transition3)) {
        transitionState = 3;
    }
}

void MovementControllerNPC::Function7986b0()
{
    if (Function1214580(transition4)) {
        transitionState = 4;
    }
}

void MovementControllerNPC::Function7986e0()
{
    if (Function1214580(transition5)) {
        transitionState = 5;
    }
}

void MovementControllerNPC::Function798710()
{
    if (Function1214580(transition6)) {
        transitionState = 6;
    }
}

void MovementControllerNPC::Function798740()
{
    if (Function1214580(transition7)) {
        transitionState = 7;
    }
}

void MovementControllerNPC::Function7987f0()
{
    if (Function1214580(transition9)) {
        transitionState = 9;
    }
}

void MovementControllerNPC::Function798820()
{
    if (Function1214580(transition10)) {
        transitionState = 10;
    }
}

void MovementControllerNPC::Function798850()
{
    if (Function1214580(transition11)) {
        transitionState = 11;
    }
}

void MovementControllerNPC::Function798bf0(void* actor, MovementCallbackData& update)
{
    std::swap(update.value10, unk198);
    std::swap(update.value08, unk190);
    std::swap(update.animationSet, unk188);
    Function798c30();
}
