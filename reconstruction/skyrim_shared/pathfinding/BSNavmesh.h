// Code origin: original; the listing and community declarations only
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSNavmesh: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSNavmesh::~BSNavmesh: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown08, unknownD0: GUESS(low)
// BSNavmesh::meshGrid: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstdint>

// BSNavmeshGrid: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); reduced to its 0x30-byte size
// BSNavmeshGrid::Unk11dd370: GUESS(low); the callee at RVA 0x11dd370, declared, not defined here
class BSNavmeshGrid
{
public:
    void Unk11dd370();

    std::uint8_t unk00[0x30];  // 00
};

class BSNavmesh
{
public:
    BSNavmesh();
    virtual ~BSNavmesh();  // compared: 0x11e99f0 (scalar deleting destructor)

    // TODO members: replace part of the padding with the members the bodies read,
    // keeping every offset and the size check true.
    // ForwardMeshGrid: GUESS(low)
    void ForwardMeshGrid();

    std::uint8_t unknown08[0x98];  // 08
    BSNavmeshGrid meshGrid;  // A0
    std::uint8_t unknownD0[0x48];  // D0
};
static_assert(sizeof(BSNavmesh) == 0x118, "BSNavmesh size");
