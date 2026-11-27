// Source exposure: mixed (target observations; permitted sibling naming hints).
// Code origin: original; target selection and lookup observations
// SPDX-License-Identifier: CC0-1.0
// 0x28c2c0 TESObjectWEAP::GetFireNode
// Adapted bodies: none
#include "TESObjectWEAP_28c2c0.h"

NiAVObject* TESObjectWEAP::GetFireNode(NiAVObject* node) const
{
    const BSFixedString* name;
    if ((flags & 0x20) != 0 && fireNodeName.data != GetDefaultFireNodeName().data)
        name = &fireNodeName;
    else
        name = &primaryFireNodeName;
    NiAVObject* result = node->LookupBoneNodeByName(*name, true);
    if (result)
        return result;
    return node->LookupBoneNodeByName(fallbackFireNodeName, true);
}
