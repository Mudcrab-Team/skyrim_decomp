// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkConstraint: EXE_RTTI
// bhkConstraint: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkWheelConstraint::Kill, BhkWheelConstraint::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkWheelConstraint: STANDIN EXE_RTTI; the RTTI name is bhkWheelConstraint, capitalised to fit the unit file-name pattern
#pragma once

class bhkConstraint
{
public:
    bhkConstraint();
    virtual ~bhkConstraint();
};

class BhkWheelConstraint : public bhkConstraint
{
public:
    BhkWheelConstraint();
    ~BhkWheelConstraint() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x18];
};
static_assert(sizeof(BhkWheelConstraint) == 0x20, "BhkWheelConstraint size from the deleting destructor");
