// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x2a5e70 TESClimate::~TESClimate
// Adapted bodies: TESClimate::~TESClimate follows momusdigital/fnv_decomp@91e1b6e8 src/tesclimate.cpp
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/World/TESClimate.cpp:20 (destructor similarity).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/tesclimate.cpp:182
#include "TESClimate_2a5e70.h"

TESClimate::TESClimate() = default;

TESClimate::~TESClimate()
{
    TESForm::ClearData();
}
