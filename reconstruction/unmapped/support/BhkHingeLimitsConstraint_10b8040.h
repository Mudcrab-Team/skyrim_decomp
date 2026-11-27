// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkConstraint: EXE_RTTI
// bhkConstraint: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkHingeLimitsConstraint::Kill, BhkHingeLimitsConstraint::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkHingeLimitsConstraint: STANDIN EXE_RTTI; the RTTI name is bhkHingeLimitsConstraint, capitalised to fit the unit file-name pattern
#pragma once

class bhkConstraint
{
public:
    bhkConstraint();
    virtual ~bhkConstraint();
};

class BhkHingeLimitsConstraint : public bhkConstraint
{
public:
    BhkHingeLimitsConstraint();
    ~BhkHingeLimitsConstraint() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x18];
};
static_assert(sizeof(BhkHingeLimitsConstraint) == 0x20, "BhkHingeLimitsConstraint size from the deleting destructor");
