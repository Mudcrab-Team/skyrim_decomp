// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// bhkShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// bhkShape: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkTransformShape::Kill, BhkTransformShape::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkTransformShape: STANDIN EXE_RTTI; the RTTI name is bhkTransformShape, capitalised to fit the unit file-name pattern
#pragma once

class bhkShape
{
public:
    bhkShape();
    virtual ~bhkShape();
};

class BhkTransformShape : public bhkShape
{
public:
    BhkTransformShape();
    ~BhkTransformShape() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkTransformShape) == 0x28, "BhkTransformShape size from the deleting destructor");
