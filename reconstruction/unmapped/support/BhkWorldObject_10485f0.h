// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// bhkSerializable: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// bhkSerializable: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkWorldObject::Kill, BhkWorldObject::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkWorldObject: STANDIN EXE_RTTI; the RTTI name is bhkWorldObject, capitalised to fit the unit file-name pattern
#pragma once

class bhkSerializable
{
public:
    bhkSerializable();
    virtual ~bhkSerializable();
};

class BhkWorldObject : public bhkSerializable
{
public:
    BhkWorldObject();
    ~BhkWorldObject() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkWorldObject) == 0x28, "BhkWorldObject size from the deleting destructor");
