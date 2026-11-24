// Source exposure: mixed (community headers; compared functions from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiAVObject, SetSelectiveUpdateTransformsRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// NiNode, AsNode: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the slot and the child array used here
// flags, children: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; the flag word at 0xF4 and the raw child array pointer at 0x118
// childrenCount: GUESS(low); the 16-bit count at 0x122
// unk00, unk08, unk10, unk08Data, unkF8Data, unk120Data: GUESS(low); vtable slots and padding in front of the used members
#pragma once

#include <cstdint>
#include <cstddef>

class NiNode;

class NiAVObject
{
public:
    virtual void unk00();
    virtual void unk08();
    virtual void unk10();
    virtual NiNode* AsNode();

    static void SetSelectiveUpdateTransformsRecursive(NiAVObject* a_object);

    unsigned char unk08Data[0xEC];
    // volatile: the flag word is treated as shared state; every edit is one load and one store of the whole word
    volatile std::uint32_t flags;
};

class NiNode : public NiAVObject
{
public:
    unsigned char unkF8Data[0x20];
    NiAVObject** children;
    unsigned char unk120Data[0x2];
    std::uint16_t childrenCount;
};
static_assert(offsetof(NiAVObject, flags) == 0xF4, "flags offset");
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childrenCount) == 0x122, "childrenCount offset");
