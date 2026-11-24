// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOrderedNode, NiNode, NiBound, NiPoint3, NiCloningProcess, orderedBound, useStaticBound, center, radius, x, y, z: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CopyMembers: SYMBOLS(fo4-pdb) CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include <cstddef>

class NiCloningProcess;

// NiPoint3: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiPoint3
{
public:
    float x;  // 0
    float y;  // 4
    float z;  // 8
};

// NiBound: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiBound
{
public:
    NiPoint3 center;  // 00
    float    radius;  // 0C
};

// NiNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only its size and the copy routine the image calls first
class NiNode
{
public:
    void CopyMembers(NiNode* a_dest, NiCloningProcess& a_cloning);

    std::uint8_t pad000[0x128];  // 000
};

class BSOrderedNode : public NiNode
{
public:
    void CopyMembers(BSOrderedNode* a_dest, NiCloningProcess& a_cloning);  // compared: 0x1570240

    NiBound       orderedBound;    // 128
    bool          useStaticBound;  // 138
};
static_assert(offsetof(BSOrderedNode, useStaticBound) == 0x138, "useStaticBound offset");
