// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkConvexShape: EXE_RTTI
// bhkConvexShape: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkConvexTransformShape::Kill, BhkConvexTransformShape::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkConvexTransformShape: STANDIN EXE_RTTI; the RTTI name is bhkConvexTransformShape, capitalised to fit the unit file-name pattern
#pragma once

class bhkConvexShape
{
public:
    bhkConvexShape();
    virtual ~bhkConvexShape();
};

class BhkConvexTransformShape : public bhkConvexShape
{
public:
    BhkConvexTransformShape();
    ~BhkConvexTransformShape() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkConvexTransformShape) == 0x28, "BhkConvexTransformShape size from the deleting destructor");
