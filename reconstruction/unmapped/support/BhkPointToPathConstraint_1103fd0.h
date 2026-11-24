// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkConstraint: EXE_RTTI
// bhkConstraint: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkPointToPathConstraint::Kill, BhkPointToPathConstraint::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkPointToPathConstraint: STANDIN EXE_RTTI; the RTTI name is bhkPointToPathConstraint, capitalised to fit the unit file-name pattern
#pragma once

class bhkConstraint
{
public:
    bhkConstraint();
    virtual ~bhkConstraint();
};

class BhkPointToPathConstraint : public bhkConstraint
{
public:
    BhkPointToPathConstraint();
    ~BhkPointToPathConstraint() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x18];
};
static_assert(sizeof(BhkPointToPathConstraint) == 0x20, "BhkPointToPathConstraint size from the deleting destructor");
