// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiObjectNET, NiNode, BSGeometry, NiTimeController: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiTimeController::StopAnimations: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::Unk_00, NiRefObject::Unk_01, NiRefObject::unk08, NiObject::Unk_02, NiObject::AsNode, NiObject::Unk_04, NiObject::Unk_05, NiObject::Unk_06, NiObject::AsGeometry, NiObjectNET::unk10, NiObjectNET::controllers, BSGeometry::unk20, BSGeometry::lightingProperty, BSGeometry::effectState, NiNode::unk20, NiNode::children, NiNode::unk120, NiNode::childCapacity, NiTimeController::Unk_08, NiTimeController::Unk_09, NiTimeController::Unk_0A, NiTimeController::Unk_0B, NiTimeController::Unk_0C, NiTimeController::Unk_0D, NiTimeController::Unk_0E, NiTimeController::Unk_0F, NiTimeController::Unk_10, NiTimeController::Unk_11, NiTimeController::Unk_12, NiTimeController::Unk_13, NiTimeController::Unk_14, NiTimeController::Unk_15, NiTimeController::Unk_16, NiTimeController::Unk_17, NiTimeController::Unk_18, NiTimeController::Unk_19, NiTimeController::Unk_1A, NiTimeController::Unk_1B, NiTimeController::Unk_1C, NiTimeController::Unk_1D, NiTimeController::Unk_1E, NiTimeController::Unk_1F, NiTimeController::Unk_20, NiTimeController::Unk_21, NiTimeController::Unk_22, NiTimeController::Unk_23, NiTimeController::Unk_24, NiTimeController::Unk_25, NiTimeController::Stop, NiTimeController::unk10, NiTimeController::next: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiNode;
class BSGeometry;
class NiTimeController;

class NiRefObject
{
public:
    virtual void Unk_00();
    virtual void Unk_01();

    std::uint64_t unk08;
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    virtual void Unk_02();
    virtual NiNode* AsNode();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual BSGeometry* AsGeometry();
};

class NiObjectNET : public NiObject
{
public:
    std::uint64_t unk10;
    NiTimeController* controllers;
};
static_assert(offsetof(NiObjectNET, controllers) == 0x18, "controllers offset");

class BSGeometry : public NiObjectNET
{
public:
    std::uint8_t unk20[0x100];
    NiObjectNET* lightingProperty;
    NiObjectNET* effectState;
};
static_assert(offsetof(BSGeometry, lightingProperty) == 0x120, "lightingProperty offset");
static_assert(offsetof(BSGeometry, effectState) == 0x128, "effectState offset");

class NiNode : public NiObjectNET
{
public:
    std::uint8_t unk20[0xF8];
    NiObjectNET** children;
    std::uint16_t unk120;
    std::uint16_t childCapacity;
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childCapacity) == 0x122, "childCapacity offset");

class NiTimeController : public NiObject
{
public:
    virtual void Unk_08();
    virtual void Unk_09();
    virtual void Unk_0A();
    virtual void Unk_0B();
    virtual void Unk_0C();
    virtual void Unk_0D();
    virtual void Unk_0E();
    virtual void Unk_0F();
    virtual void Unk_10();
    virtual void Unk_11();
    virtual void Unk_12();
    virtual void Unk_13();
    virtual void Unk_14();
    virtual void Unk_15();
    virtual void Unk_16();
    virtual void Unk_17();
    virtual void Unk_18();
    virtual void Unk_19();
    virtual void Unk_1A();
    virtual void Unk_1B();
    virtual void Unk_1C();
    virtual void Unk_1D();
    virtual void Unk_1E();
    virtual void Unk_1F();
    virtual void Unk_20();
    virtual void Unk_21();
    virtual void Unk_22();
    virtual void Unk_23();
    virtual void Unk_24();
    virtual void Unk_25();
    virtual void Stop();

    static void StopAnimations(NiObjectNET* a_object);

    std::uint8_t unk10[0x30];
    NiTimeController* next;
};
static_assert(offsetof(NiTimeController, next) == 0x40, "next offset");
