// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x38b250 BGSBodyPartData::ClearData
// Adapted bodies: BGSBodyPartData::ClearData follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsbodypartdata.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsbodypartdata.cpp:50
#include "BGSBodyPartData_38b250.h"

void BGSBodyPartData::ClearData()
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
