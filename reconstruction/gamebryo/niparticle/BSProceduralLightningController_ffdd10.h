// 0xffdd10 BSProceduralLightningController::GetPropertyHolder
// Source exposure: mixed
// Code origin: original minimal declarations and layout views using the labelled sources.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetPropertyHolder: CRASHLOGGER_PDB(59818@2026.10.24) SYMBOLS(fo4-pdb)
// BSProceduralLightningController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject, NiNode, BSGeometry, AsNode, AsGeometry, NiTimeController::target, children, NiTArray::_data, NiTArray::_freeIdx: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiChildArray: STANDIN GUESS(low); minimal child-array view
#pragma once
#include <cstddef>
#include <cstdint>

class NiNode;
class BSGeometry;
class NiObject {
public:
    virtual ~NiObject();
    virtual void DeleteThis();
    virtual const void* GetRTTI() const;
    virtual NiNode* AsNode();
    virtual void* AsSwitchNode();
    virtual void* AsFadeNode();
    virtual void* AsMultiBoundNode();
    virtual BSGeometry* AsGeometry();
};

struct NiChildArray {
    void* vtable;
    NiObject** _data;
    std::uint16_t _capacity;
    std::uint16_t _freeIdx;
    std::uint16_t _size;
    std::uint16_t _growthSize;
};
class NiNode : public NiObject {
public:
    unsigned char prefix[0x108];
    NiChildArray children;
};
class BSProceduralLightningController {
public:
    BSGeometry* GetPropertyHolder() const;
    unsigned char prefix[0x38];
    NiObject* target;
};
static_assert(offsetof(BSProceduralLightningController, target) == 0x38, "target offset");
static_assert(offsetof(NiNode, children) == 0x110, "children offset");
static_assert(offsetof(NiChildArray, _freeIdx) == 0x12, "child upper bound offset");
