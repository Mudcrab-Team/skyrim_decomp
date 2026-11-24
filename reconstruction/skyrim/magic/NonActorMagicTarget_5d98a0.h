// Source exposure: mixed (community declarations; the listing of the pinned image).
// Code origin: names and slot order from CharmedBaryon/CommonLibSSE-NG (MIT); only the compared virtual is modelled
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NonActorMagicTarget, NonActorMagicTarget::AddTarget, MagicTarget::AddTarget: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// MagicTarget, MagicTarget::AddTargetData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the slots before 01 are not modelled beyond the destructor
// MagicTarget::UpdateTarget: GUESS(medium); the name is the one the sibling body calls, its declaration is not in a permitted folder
// The BSExtraData base is not modelled: the compared function runs on the MagicTarget view of the object.
#pragma once

class MagicTarget
{
public:
    struct AddTargetData;

    virtual ~MagicTarget();
    virtual bool AddTarget(AddTargetData& a_targetData);  // 01
    void UpdateTarget(float a_delta);
};

class NonActorMagicTarget : public MagicTarget
{
public:
    bool AddTarget(AddTargetData& a_targetData) override;  // 01, compared: 0x5d98a0
};
