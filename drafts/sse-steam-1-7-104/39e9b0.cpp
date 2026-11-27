// Near miss: 9.0 alignment distance | other
// Exposure detail: (community declarations and binary analysis).
// Source exposure: mixed
// Code origin: reconstruction from the pinned image listing, shaped after the sibling function.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: BGSRagdoll::~BGSRagdoll follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsragdoll.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/bgsragdoll.cpp:962
// 0x39e9b0 BGSRagdoll::~BGSRagdoll

#include "include/39e9b0/BGSRagdoll_39e9b0.h"

BGSRagdoll::BGSRagdoll() = default;

BGSRagdoll::~BGSRagdoll()
{
    ClearRagdollData();
}
