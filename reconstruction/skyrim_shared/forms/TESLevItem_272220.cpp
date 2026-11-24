// Source exposure: mixed (local binary analysis, community declarations and the cited sibling).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x272220 TESLevItem::~TESLevItem
// Adapted bodies: TESLevItem::~TESLevItem follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevitem.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/teslevitem.cpp:93
#include "TESLevItem_272220.h"

// The constructor emits this class's vftables and deleting destructor.
TESLevItem::TESLevItem() = default;

TESLevItem::~TESLevItem() = default;
