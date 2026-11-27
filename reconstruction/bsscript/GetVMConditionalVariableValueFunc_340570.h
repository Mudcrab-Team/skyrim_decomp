// Source exposure: binary-analysis (class names from the image's RTTI; sizes and the inlined destructor body from the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// GetVMConditionalVariableValueFunc: EXE_RTTI; an anonymous-namespace type in the image
// ConditionalVariableBase, ConditionalVariableMember: GUESS(low); the base type and the member type at 0x18, only their out-of-line destructors are modelled
#pragma once

struct ConditionalVariableBase
{
    ConditionalVariableBase();
    virtual ~ConditionalVariableBase();

    unsigned char unk08[0x10];  // 08
};

struct ConditionalVariableMember
{
    ~ConditionalVariableMember();

    unsigned char unk00[0x10];  // 00
};

struct GetVMConditionalVariableValueFunc : public ConditionalVariableBase
{
    GetVMConditionalVariableValueFunc();

    ConditionalVariableMember unk18;  // 18
};
static_assert(sizeof(GetVMConditionalVariableValueFunc) == 0x28, "size from the deleting destructor");
