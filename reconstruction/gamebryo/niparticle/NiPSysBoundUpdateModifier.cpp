// Source exposure: mixed (the pinned image listing and local layout guesses).
// Code origin: original reconstruction from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// 0xfa8520 NiPSysBoundUpdateModifier::Functionfa8520
// Adapted bodies: none
#include "NiPSysBoundUpdateModifier.h"

// Functionfa11c0: GUESS(low); declared only, the target setter the body tail-calls
void Functionfa11c0(NiPSysBoundUpdateModifier* a_this, std::uint8_t* a_target);

void NiPSysBoundUpdateModifier::Functionfa8520(std::uint8_t* a_target)
{
    BoundTargetLayout* previous = m_boundTarget;
    if (previous) {
        previous->flag = 0;
    }
    if (a_target) {
        reinterpret_cast<BoundTargetLayout*>(a_target)->flag = 1;
    }
    Functionfa11c0(this, a_target);
}
