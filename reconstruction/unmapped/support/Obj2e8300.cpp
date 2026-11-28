// Source exposure: binary-analysis
// Code origin: original; pinned-image listing only
// SPDX-License-Identifier: CC0-1.0
// 0x2e8300 Obj2e8300::ForwardItem
// Adapted bodies: none
#include "Obj2e8300.h"

namespace
{
ContainerComp2e8300* GetContainer(BaseForm2e8300* a_base)
{
    if (!a_base)
    {
        return nullptr;
    }
    switch (a_base->m_formType)
    {
    case 0x1C:
        return static_cast<ContainerComp2e8300*>(static_cast<ContainerForm2e8300*>(a_base));
    case 0x2B:
        return &static_cast<NpcForm2e8300*>(a_base)->m_container;
    default:
        return nullptr;
    }
}
}

// Guess: if the base form exposes a container component and changes exist, forward the item call.
bool Obj2e8300::ForwardItem(void* a_item, std::uint32_t a_count, void* a_extra)
{
    if (GetContainer(m_base))
    {
        void* changes = GetChanges();
        if (changes)
        {
            OnForward(changes, a_item, a_count, a_extra);
        }
    }
    return true;
}
