// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkHeightFieldShape: EXE_RTTI
// bhkHeightFieldShape: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkPlaneShape::Kill, BhkPlaneShape::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkPlaneShape: STANDIN EXE_RTTI; the RTTI name is bhkPlaneShape, capitalised to fit the unit file-name pattern
#pragma once

class bhkHeightFieldShape
{
public:
    bhkHeightFieldShape();
    virtual ~bhkHeightFieldShape();
};

class BhkPlaneShape : public bhkHeightFieldShape
{
public:
    BhkPlaneShape();
    ~BhkPlaneShape() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkPlaneShape) == 0x28, "BhkPlaneShape size from the deleting destructor");
