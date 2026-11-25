// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// NavMeshSearchSLPoint, BSNavmeshSearch: EXE_RTTI
// BSNavmeshSearch: STANDIN EXE_RTTI; only its out-of-line destructor is declared
#pragma once

class BSNavmeshSearch
{
public:
    BSNavmeshSearch();
    virtual ~BSNavmeshSearch();
};

class NavMeshSearchSLPoint : public BSNavmeshSearch
{
public:
    NavMeshSearchSLPoint();
    ~NavMeshSearchSLPoint() override {}

    char unk08[0x1F0];
};
static_assert(sizeof(NavMeshSearchSLPoint) == 0x1F8, "NavMeshSearchSLPoint size from the deleting destructor");
