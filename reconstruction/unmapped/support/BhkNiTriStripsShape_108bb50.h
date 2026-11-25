// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// bhkShapeCollection: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// bhkShapeCollection: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkNiTriStripsShape::Kill, BhkNiTriStripsShape::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkNiTriStripsShape: STANDIN EXE_RTTI; the RTTI name is bhkNiTriStripsShape, capitalised to fit the unit file-name pattern
#pragma once

class bhkShapeCollection
{
public:
    bhkShapeCollection();
    virtual ~bhkShapeCollection();
};

class BhkNiTriStripsShape : public bhkShapeCollection
{
public:
    BhkNiTriStripsShape();
    ~BhkNiTriStripsShape() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkNiTriStripsShape) == 0x28, "BhkNiTriStripsShape size from the deleting destructor");
