// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkConvexShape: EXE_RTTI
// bhkConvexShape: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkCylinderShape::Kill, BhkCylinderShape::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkCylinderShape: STANDIN EXE_RTTI; the RTTI name is bhkCylinderShape, capitalised to fit the unit file-name pattern
#pragma once

class bhkConvexShape
{
public:
    bhkConvexShape();
    virtual ~bhkConvexShape();
};

class BhkCylinderShape : public bhkConvexShape
{
public:
    BhkCylinderShape();
    ~BhkCylinderShape() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkCylinderShape) == 0x28, "BhkCylinderShape size from the deleting destructor");
