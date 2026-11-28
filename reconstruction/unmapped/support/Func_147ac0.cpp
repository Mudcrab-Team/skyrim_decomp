// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Func_147ac0::SetKeyValue, treated as adapted: shaped like NiTStringTemplateMap::SetValue in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:4482
// SPDX-License-Identifier: CC0-1.0
// 0x147ac0 Func_147ac0::SetKeyValue
#include "Func_147ac0.h"

#include <cstring>

extern char* AllocString147ac0(std::size_t size);
extern "C" __declspec(dllimport) int __cdecl strcpy_s(char* dest, std::size_t destSize, const char* src);

// Stores key (duplicating it when copyKeys is set) and value into node.
void Func_147ac0::SetKeyValue(Node147ac0* node, const char* key, std::uint64_t value)
{
    if (copyKeys)
    {
        std::size_t len = std::strlen(key) + 1;
        char* copy = AllocString147ac0(len);
        node->key = copy;
        strcpy_s(copy, len, key);
    }
    else
    {
        node->key = key;
    }
    node->value = value;
}
