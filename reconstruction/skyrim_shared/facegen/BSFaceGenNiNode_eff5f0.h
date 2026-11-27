// Source exposure: mixed (names from the community PDB table; the pinned image listing).
// Code origin: original; written from the listing and community PDB names.
// BSFaceGenNiNode, BSFaceGenNiNode::sub_140C74130, NiAVObject, NiNode: CRASHLOGGER_PDB(59818@2026.10.24)
// Unk_00, Unk_01, Unk_02, AsNode, name, unk18, children, unk120, childCount, RegisterNamedChild: GUESS
#pragma once

#include <cstddef>
#include <cstdint>

class NiNode;

class NiAVObject
{
public:
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual NiNode* AsNode();

    std::uint8_t unk08[0x8];
    const char* name;
};

class NiNode : public NiAVObject
{
public:
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Unk_06();
    virtual void Unk_07();
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
    virtual void RegisterNamedChild(const char** a_name, NiAVObject* a_object);

    std::uint8_t unk18[0x100];
    NiAVObject** children;
    std::uint16_t unk120;
    std::uint16_t childCount;
};

class BSFaceGenNiNode
{
public:
    static void sub_140C74130(NiAVObject* a_object, NiNode* a_target);
};

static_assert(offsetof(NiAVObject, name) == 0x10, "name offset");
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childCount) == 0x122, "childCount offset");
