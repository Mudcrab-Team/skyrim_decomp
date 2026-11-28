// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// 0x129e60 Function129e60
// Adapted bodies: none
#include "FreeFunction_129e60.h"

// Invokes every consecutive callback node matching the given id.
void Function129e60(CallbackNode129e60* a_node, std::uint32_t a_id, const Payload129e60& a_payload, std::uint32_t a_param)
{
    if (a_id == a_node->id)
    {
        do
        {
            if (a_node->cb)
            {
                a_node->cb(a_id, a_payload, a_param);
            }
            a_node = a_node->next;
        } while (a_node != nullptr && a_id == a_node->id);
    }
}
