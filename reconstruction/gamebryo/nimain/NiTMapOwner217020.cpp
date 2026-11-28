// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: NiTMap217020::GetFirstPos and GetNext, treated as adapted: shaped like NiTMapBase::GetFirstPos and NiTMapBase::GetNext in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nitmapbase.inl:130
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/gamebryo2.2/corelibs/nimain/nipersistentsrctexturerendererdata.cpp:745
// SPDX-License-Identifier: CC0-1.0
// 0x217020 NiTMapOwner217020::SumEntrySizes
#include "NiTMapOwner217020.h"

// Sum the size field across every non-null entry in the map.
std::uint32_t NiTMapOwner217020::SumEntrySizes() const
{
    std::uint32_t total = 0;
    NiTMapItem217020* pos = map.GetFirstPos();
    while (pos)
    {
        void* key = nullptr;
        NiTMapEntry217020* val = nullptr;
        map.GetNext(pos, key, val);
        if (val)
        {
            total += val->size;
        }
    }
    return total;
}
