// Source exposure: mixed (pinned image and cited declarations).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: NavMeshInfoMap::~NavMeshInfoMap follows momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/navmeshinfomap.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/navmeshinfomap.cpp:539
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/pathfinding/navmeshinfomap.cpp:425
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/NavMeshInfo/NavMeshInfoMap.cpp:35
// NavMeshInfoMap, ::updateAll, ::infoMap, ::ckNavMeshInfoMap, ::mapLock, ::init: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NavMeshInfoMap::~NavMeshInfoMap: CRASHLOGGER_PDB(59818@2026.10.24)
// ClearNavMeshInfoMaps: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// BSNavmeshInfoMap, BSNavmeshInfoMap::~BSNavmeshInfoMap, PrecomputedNavmeshInfoPathMap: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NavMeshInfoTail, CKNavMeshInfoTail, NavMeshInfoOwnership, ownership, unknown08, unknown00, unknownE9: GUESS(low); partial storage views for the called cleanup routines.
#pragma once

#include "skyrim_shared/forms/TESForm.h"

class BSNavmeshInfoMap
{
public:
    virtual ~BSNavmeshInfoMap();

    std::uint64_t unknown08;
};

class PrecomputedNavmeshInfoPathMap
{
public:
    ~PrecomputedNavmeshInfoPathMap();

    std::uint64_t unknown00[9];
};

class NavMeshInfoTail
{
public:
    ~NavMeshInfoTail();
    std::uint64_t unknown00[5];
};

class CKNavMeshInfoTail
{
public:
    ~CKNavMeshInfoTail();
    std::uint64_t unknown00[5];
};

template <class Tail>
struct NavMeshInfoOwnership
{
    std::uint64_t unknown00;
    Tail ownership;
};

class NavMeshInfoMap : public TESForm, public BSNavmeshInfoMap, public PrecomputedNavmeshInfoPathMap
{
public:
    ~NavMeshInfoMap() override;
    void ClearNavMeshInfoMaps();

    bool updateAll;
    NavMeshInfoOwnership<NavMeshInfoTail> infoMap;
    NavMeshInfoOwnership<CKNavMeshInfoTail> ckNavMeshInfoMap;
    std::uint64_t mapLock;
    bool init;
    std::uint8_t unknownE9[7];
};
static_assert(sizeof(NavMeshInfoMap) == 0xF0, "NavMeshInfoMap size");
