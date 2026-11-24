// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkUnaryAction: EXE_RTTI
// bhkUnaryAction: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkMotorAction::Kill, BhkMotorAction::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkMotorAction: STANDIN EXE_RTTI; the RTTI name is bhkMotorAction, capitalised to fit the unit file-name pattern
#pragma once

class bhkUnaryAction
{
public:
    bhkUnaryAction();
    virtual ~bhkUnaryAction();
};

class BhkMotorAction : public bhkUnaryAction
{
public:
    BhkMotorAction();
    ~BhkMotorAction() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x18];
};
static_assert(sizeof(BhkMotorAction) == 0x20, "BhkMotorAction size from the deleting destructor");
