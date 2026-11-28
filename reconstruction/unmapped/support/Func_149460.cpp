// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Base149460::~Base149460, Mid149460::~Mid149460 and Func_149460::~Func_149460, treated as adapted: shaped like NiTMapBase::~NiTMapBase and NiTPointerMap::~NiTPointerMap and NiTStringTemplateMap::~NiTStringTemplateMap in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:582
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:589
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/staging/blk_00a60000_o2.cpp:596
// SPDX-License-Identifier: CC0-1.0
// 0x149460 Func_149460::~Func_149460
#include "Func_149460.h"

// Frees owned bucket keys when copyKeys is enabled, then destroys base map state.
Func_149460::~Func_149460()
{
    if (copyKeys)
    {
        for (std::uint32_t i = 0; i < bucketCount; ++i)
        {
            Node149460* node = buckets[i];
            while (node)
            {
                void* key = node->key;
                node = node->next;
                FreeMem149460(key);
            }
        }
    }
}
