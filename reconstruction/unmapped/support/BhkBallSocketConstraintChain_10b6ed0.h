// Build sse-steam-1-7-104. Source exposure: binary-analysis (class names and bases from the image's
// RTTI; the object size and the inlined destructor body from the pinned image listing).
// Labels: v2
// SPDX-License-Identifier: CC0-1.0
// bhkConstraintChain: EXE_RTTI
// bhkConstraintChain: STANDIN EXE_RTTI; only the members and destructors the function needs
// BhkBallSocketConstraintChain::Kill, BhkBallSocketConstraintChain::sInstanceCount: GUESS(low); the sibling names the helper bhkSerializable_Kill
// BhkBallSocketConstraintChain: STANDIN EXE_RTTI; the RTTI name is bhkBallSocketConstraintChain, capitalised to fit the unit file-name pattern
#pragma once

class bhkConstraintChain
{
public:
    bhkConstraintChain();
    virtual ~bhkConstraintChain();
};

class BhkBallSocketConstraintChain : public bhkConstraintChain
{
public:
    BhkBallSocketConstraintChain();
    ~BhkBallSocketConstraintChain() override
    {
        Kill();
        --sInstanceCount;
    }
    void Kill();
    static int sInstanceCount;

    char unk08[0x18];
};
static_assert(sizeof(BhkBallSocketConstraintChain) == 0x20, "BhkBallSocketConstraintChain size from the deleting destructor");
