// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkUnaryAction: EXE_RTTI
// bhkUnaryAction: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkOrientHingedBodyAction::Kill, BhkOrientHingedBodyAction::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkOrientHingedBodyAction: STANDIN EXE_RTTI; the RTTI name is bhkOrientHingedBodyAction, capitalised to fit the unit file-name pattern
#pragma once

class bhkUnaryAction
{
public:
    bhkUnaryAction();
    virtual ~bhkUnaryAction();
};

class BhkOrientHingedBodyAction : public bhkUnaryAction
{
public:
    BhkOrientHingedBodyAction();
    ~BhkOrientHingedBodyAction() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x18];
};
static_assert(sizeof(BhkOrientHingedBodyAction) == 0x20, "BhkOrientHingedBodyAction size from the deleting destructor");
