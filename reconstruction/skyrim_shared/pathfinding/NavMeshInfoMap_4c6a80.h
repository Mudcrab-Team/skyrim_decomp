// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NavMeshInfoMap, MapVisitor, VisitTarget, target, visitor: GUESS(low)
// NavMeshInfoMap::Visit: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); name only, the body is not taken from there
#pragma once

#include <cstdint>
#include <cstddef>

class MapVisitor
{
public:
    virtual void unk00();
    ~MapVisitor() {}
};

class VisitTarget
{
public:
    virtual ~VisitTarget();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void Accept(MapVisitor* a_visitor);  // slot 5
};

class NavMeshInfoMap
{
public:
    uint8_t unk00[0x20];
    VisitTarget target;

    void Visit();  // compared: 0x4c6a80
};
