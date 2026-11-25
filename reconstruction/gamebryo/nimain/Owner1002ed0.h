// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below Stamped as a twin of matched 0x1002480 (gamebryo/nimain/BSMultiBoundAABB_1002480): source copied, names replaced by placeholders.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPoint3, NiCloningProcess: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NiPoint3 is plain data here, the process is opaque
// Function1002ed0, Owner1002ed0: GUESS(low) STANDIN
// BSMultiBoundShape, PointA, PointB, Radius: GUESS(low) STANDIN
#pragma once
#include "BSMultiBoundAABB_1002480.h"

class Owner1002ed0 : public BSMultiBoundShape
{
public:
    void Function1002ed0(Owner1002ed0* a_dest, NiCloningProcess& a_process);

    unsigned char padTwin18[24];
    NiPoint3 PointA;  // 18
    NiPoint3 PointB;  // 24
    float Radius;     // 30
};
