// Source exposure: mixed (local target observations; community declarations).
// Code origin: original reconstruction.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWorldSpace::AttachPortalGraph: CRASHLOGGER_PDB(59818@2026.10.24)
// TESWorldSpace, TESWorldSpace::multiBoundNode, TESWorldSpace::portalSharedNode: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiNode, NiNode::SetAt2: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknown00-unknown3b, unknownPrefix, portalRoot: GUESS(low) STANDIN; unused virtual slots and opaque storage.
#pragma once
#include <cstdint>
#include <cstddef>
class NiNode
{
public:
    virtual void unknown00();
    virtual void unknown01();
    virtual void unknown02();
    virtual void unknown03();
    virtual void unknown04();
    virtual void unknown05();
    virtual void unknown06();
    virtual void unknown07();
    virtual void unknown08();
    virtual void unknown09();
    virtual void unknown0a();
    virtual void unknown0b();
    virtual void unknown0c();
    virtual void unknown0d();
    virtual void unknown0e();
    virtual void unknown0f();
    virtual void unknown10();
    virtual void unknown11();
    virtual void unknown12();
    virtual void unknown13();
    virtual void unknown14();
    virtual void unknown15();
    virtual void unknown16();
    virtual void unknown17();
    virtual void unknown18();
    virtual void unknown19();
    virtual void unknown1a();
    virtual void unknown1b();
    virtual void unknown1c();
    virtual void unknown1d();
    virtual void unknown1e();
    virtual void unknown1f();
    virtual void unknown20();
    virtual void unknown21();
    virtual void unknown22();
    virtual void unknown23();
    virtual void unknown24();
    virtual void unknown25();
    virtual void unknown26();
    virtual void unknown27();
    virtual void unknown28();
    virtual void unknown29();
    virtual void unknown2a();
    virtual void unknown2b();
    virtual void unknown2c();
    virtual void unknown2d();
    virtual void unknown2e();
    virtual void unknown2f();
    virtual void unknown30();
    virtual void unknown31();
    virtual void unknown32();
    virtual void unknown33();
    virtual void unknown34();
    virtual void unknown35();
    virtual void unknown36();
    virtual void unknown37();
    virtual void unknown38();
    virtual void unknown39();
    virtual void unknown3a();
    virtual void unknown3b();
    virtual void SetAt2(std::uint32_t index, NiNode* child);
};
extern NiNode* portalRoot;
class TESWorldSpace
{
public:
    void AttachPortalGraph();
    std::uint8_t unknownPrefix[0x148];
    NiNode* multiBoundNode;
    NiNode* portalSharedNode;
};
static_assert(offsetof(TESWorldSpace, multiBoundNode) == 0x148, "multibound node offset");
static_assert(offsetof(TESWorldSpace, portalSharedNode) == 0x150, "portal node offset");
