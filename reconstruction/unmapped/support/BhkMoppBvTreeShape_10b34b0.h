// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkBvTreeShape: EXE_RTTI
// bhkBvTreeShape: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkMoppBvTreeShape::Kill, BhkMoppBvTreeShape::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkMoppBvTreeShape: STANDIN EXE_RTTI; the RTTI name is bhkMoppBvTreeShape, capitalised to fit the unit file-name pattern
#pragma once

class bhkBvTreeShape
{
public:
    bhkBvTreeShape();
    virtual ~bhkBvTreeShape();
};

class BhkMoppBvTreeShape : public bhkBvTreeShape
{
public:
    BhkMoppBvTreeShape();
    ~BhkMoppBvTreeShape() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkMoppBvTreeShape) == 0x28, "BhkMoppBvTreeShape size from the deleting destructor");
