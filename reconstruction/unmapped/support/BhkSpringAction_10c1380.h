// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkBinaryAction: EXE_RTTI
// bhkBinaryAction: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkSpringAction::Kill, BhkSpringAction::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkSpringAction: STANDIN EXE_RTTI; the RTTI name is bhkSpringAction, capitalised to fit the unit file-name pattern
#pragma once

class bhkBinaryAction
{
public:
    bhkBinaryAction();
    virtual ~bhkBinaryAction();
};

class BhkSpringAction : public bhkBinaryAction
{
public:
    BhkSpringAction();
    ~BhkSpringAction() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x18];
};
static_assert(sizeof(BhkSpringAction) == 0x20, "BhkSpringAction size from the deleting destructor");
