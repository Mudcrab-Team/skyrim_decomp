// Source exposure: mixed (community declarations and binary analysis).
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x270f50 TESKey::~TESKey
// Adapted bodies: TESKey::~TESKey follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teskey.cpp
// Sibling source: fo4-private@1b765c70 src/Shared/TESForms/Objects/TESKey.cpp:18 (destructor similarity).
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teskey.cpp:13
#include "TESKey_270f50.h"

TESKey::TESKey() = default;

TESKey::~TESKey()
{
    TESForm::ClearData();
}
