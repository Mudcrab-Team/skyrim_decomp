// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x127e90 Function127e90
// Adapted bodies: none
#include "FreeFunction_127e90.h"

namespace
{
    void* FindByKind(std::uint32_t a_kind)
    {
        for (ListNode127e90* node = gListHead127e90; node != nullptr; node = node->next)
        {
            if (node->kind == a_kind)
            {
                return node->value;
            }
        }
        return nullptr;
    }
}

// Finds the list entry with kind 24, stores its value, and assigns a sequence id if found.
void Function127e90(Target127e90* a_target)
{
    void* found = FindByKind(24);
    a_target->value = found;
    a_target->ready = 1;
    if (found != nullptr)
    {
        const std::uint64_t nextId = gNextId127e90;
        a_target->seqId = nextId;
        gNextId127e90 = nextId + 1;
        a_target->state = 2;
    }
}
