// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkConvexShape: EXE_RTTI
// bhkConvexShape: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkCapsuleShape::Kill, BhkCapsuleShape::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkCapsuleShape: STANDIN EXE_RTTI; the RTTI name is bhkCapsuleShape, capitalised to fit the unit file-name pattern
#pragma once

class bhkConvexShape
{
public:
    bhkConvexShape();
    virtual ~bhkConvexShape();
};

class BhkCapsuleShape : public bhkConvexShape
{
public:
    BhkCapsuleShape();
    ~BhkCapsuleShape() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkCapsuleShape) == 0x28, "BhkCapsuleShape size from the deleting destructor");
