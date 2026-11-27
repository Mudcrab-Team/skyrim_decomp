// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkGenericConstraint: EXE_RTTI
// bhkGenericConstraint: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkFixedConstraint::Kill, BhkFixedConstraint::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkFixedConstraint: STANDIN EXE_RTTI; the RTTI name is bhkFixedConstraint, capitalised to fit the unit file-name pattern
#pragma once

class bhkGenericConstraint
{
public:
    bhkGenericConstraint();
    virtual ~bhkGenericConstraint();
};

class BhkFixedConstraint : public bhkGenericConstraint
{
public:
    BhkFixedConstraint();
    ~BhkFixedConstraint() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x18];
};
static_assert(sizeof(BhkFixedConstraint) == 0x20, "BhkFixedConstraint size from the deleting destructor");
