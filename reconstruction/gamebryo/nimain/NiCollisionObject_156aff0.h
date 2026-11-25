// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; handwritten from local target observations.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, NiCollisionObject, NiAVObject, sceneObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiObject::NiObject: CRASHLOGGER_PDB(59818@2026.10.24)
// NiCollisionObject::NiCollisionObject: GUESS(high); base construction, own table and null scene link.
// unknown08: OBSERVED; unmodelled base-object storage.
#pragma once
#include <cstdint>

class NiAVObject;
class NiObject
{
public:
    NiObject();
    virtual ~NiObject();
private:
    std::uint64_t unknown08;
};
class NiCollisionObject : public NiObject
{
public:
    NiCollisionObject();
    ~NiCollisionObject() override;
    NiAVObject* sceneObject;
};
