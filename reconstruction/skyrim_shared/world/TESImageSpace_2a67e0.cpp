// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a67e0 TESImageSpace::~TESImageSpace
// Adapted bodies: TESImageSpace::~TESImageSpace follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesimagespace.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tesimagespace.cpp:67
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESImageSpace.cpp:37
#include "TESImageSpace_2a67e0.h"

// The constructor emits this class's vftable and deleting destructor.
TESImageSpace::TESImageSpace() = default;

TESImageSpace::~TESImageSpace()
{
    TESForm::ClearData();
}
