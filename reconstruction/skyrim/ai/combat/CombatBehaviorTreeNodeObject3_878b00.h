// Source exposure: binary-analysis (class names from the image's RTTI; sizes and the inlined destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// CombatBehaviorTreeNodeObject3: EXE_RTTI; the image's template instance is modelled as a plain class
// CombatBehaviorTreeNodeObjectBase, CombatBehaviorTreeNodeMember: GUESS(low); the base type and the member type at 0x28, only their out-of-line destructors are modelled
#pragma once

class CombatBehaviorTreeNodeObjectBase
{
public:
    CombatBehaviorTreeNodeObjectBase();
    virtual ~CombatBehaviorTreeNodeObjectBase();

    unsigned char unk08[0x20];  // 08
};

class CombatBehaviorTreeNodeMember
{
public:
    ~CombatBehaviorTreeNodeMember();

    unsigned char unk00[0x10];  // 00
};

class CombatBehaviorTreeNodeObject3 : public CombatBehaviorTreeNodeObjectBase
{
public:
    CombatBehaviorTreeNodeObject3();

    CombatBehaviorTreeNodeMember unk28;  // 28
};
static_assert(sizeof(CombatBehaviorTreeNodeObject3) == 0x38, "size from the deleting destructor");
