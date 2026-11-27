// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkSphereRepShape: EXE_RTTI
// bhkSphereRepShape: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkMultiSphereShape::Kill, BhkMultiSphereShape::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkMultiSphereShape: STANDIN EXE_RTTI; the RTTI name is bhkMultiSphereShape, capitalised to fit the unit file-name pattern
#pragma once

class bhkSphereRepShape
{
public:
    bhkSphereRepShape();
    virtual ~bhkSphereRepShape();
};

class BhkMultiSphereShape : public bhkSphereRepShape
{
public:
    BhkMultiSphereShape();
    ~BhkMultiSphereShape() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkMultiSphereShape) == 0x28, "BhkMultiSphereShape size from the deleting destructor");
