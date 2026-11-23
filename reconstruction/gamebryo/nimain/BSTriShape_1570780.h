// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// BSTriShape, BSTriShape::Function1570780: GUESS(low)
// SceneObject, unk02, parent, rtti, s_rtti: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct RttiInfo
{
    int unk00;
};

class SceneObject
{
public:
    virtual ~SceneObject();
    virtual void unk01();
    virtual const RttiInfo* unk02();

    unsigned char pad08[0x28];
    SceneObject* parent;
};

class BSTriShape
{
public:
    static SceneObject* Function1570780(SceneObject* a_object);

    static const RttiInfo s_rtti;
};
