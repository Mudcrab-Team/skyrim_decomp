// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkConstraint: EXE_RTTI
// bhkConstraint: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkGroupConstraint::Kill, BhkGroupConstraint::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkGroupConstraint: STANDIN EXE_RTTI; the RTTI name is bhkGroupConstraint, capitalised to fit the unit file-name pattern
#pragma once

class bhkConstraint
{
public:
    bhkConstraint();
    virtual ~bhkConstraint();
};

class BhkGroupConstraint : public bhkConstraint
{
public:
    BhkGroupConstraint();
    ~BhkGroupConstraint() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x20];
};
static_assert(sizeof(BhkGroupConstraint) == 0x28, "BhkGroupConstraint size from the deleting destructor");
