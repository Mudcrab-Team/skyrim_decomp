// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// MovementPlannerAgentWarp, MovementPlannerAgentWarp::~MovementPlannerAgentWarp, object: GUESS(low); the compared code is a reference-counted pointer release
// NiRefObject, NiRefObject::_refCount: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; offset 08 and a volatile long count
#pragma once

#include <cstdint>
#include <cstddef>

class NiRefObject
{
public:
    virtual ~NiRefObject();

    volatile long _refCount;  // 08
};

class MovementPlannerAgentWarp
{
public:
    ~MovementPlannerAgentWarp();  // compared: 0x7aa7e0

    NiRefObject* object;  // 000
};
