// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: none
// TESBoundObject, TESBoundObject::sub_140196DD0: CRASHLOGGER_PDB(59818@2026.10.24)
// BoundObjectCastTarget: GUESS(low) STANDIN
#pragma once

class BoundObjectCastTarget
{
public:
    virtual ~BoundObjectCastTarget();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void ClearObject();
};

class TESBoundObject
{
public:
    virtual ~TESBoundObject();

    void sub_140196DD0();
};
