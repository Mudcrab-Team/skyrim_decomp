// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xf999c0 NiParticleSystem::InitializeModifiers
// Adapted bodies: none
#include "NiParticleSystem_f999c0.h"

namespace
{
    // Item: GUESS(low); shorthand for the modifier list node
    using Item = NiTListItem<NiPointer<NiPSysModifier>>;
}

void NiParticleSystem::InitializeModifiers(std::uint16_t a_arg1, NiPoint3* a_arg2)
{
    NiParticlesData* data = particleData;
    Item* pos = modifierList.head;
    while (pos) {
        // take the element, advance, then call: the modifier may unlink itself
        const NiPointer<NiPSysModifier>& modifier = pos->element;
        pos = pos->next;
        modifier->Initialize(data, a_arg1, a_arg2);
    }
}
