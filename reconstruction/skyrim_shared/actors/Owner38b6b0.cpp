// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function. Stamped as a twin of matched 0x38b250 (skyrim_shared/actors/BGSBodyPartData_38b250): source copied, names replaced by placeholders.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsbodypartdata.cpp:50
// 0x38b6b0 Owner38b6b0::ClearData
#include "Owner38b6b0.h"

// guess: same compiled code as matched 0x38b250 apart from relocated fields; its role here is not established.
void Owner38b6b0::ClearData()
{
    auto* part = parts;
    std::size_t remaining = sizeof(parts) / sizeof(parts[0]);
    do
    {
        delete *part;
        *part = nullptr;
        ++part;
    }
    while (--remaining != 0);
}
