// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// bhkShapePhantom: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// bhkShapePhantom: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkCachingShapePhantom::Kill, BhkCachingShapePhantom::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkCachingShapePhantom: STANDIN EXE_RTTI; the RTTI name is bhkCachingShapePhantom, capitalised to fit the unit file-name pattern
#pragma once

class bhkShapePhantom
{
public:
    bhkShapePhantom();
    virtual ~bhkShapePhantom();
};

class BhkCachingShapePhantom : public bhkShapePhantom
{
public:
    BhkCachingShapePhantom();
    ~BhkCachingShapePhantom() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x28];
};
static_assert(sizeof(BhkCachingShapePhantom) == 0x30, "BhkCachingShapePhantom size from the deleting destructor");
