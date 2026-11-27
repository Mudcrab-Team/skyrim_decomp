// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original reconstruction from the pinned-image listing and CrashLogger PDB layout
// NiAVObject, NiNode, BSGeometry, BSShaderProperty, NiRTTI, GetRTTI, SetBloodSplatterAlphaSourceRecursive: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRTTI_BSBloodSplatterShaderProperty, AsNode, AsGeometry, shaderProperty, alphaSource, children, childrenCapacity, childrenSize, Unk_01, Unk_02, Unk_04..Unk_06, unknown008: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct NiRTTI;
extern NiRTTI NiRTTI_BSBloodSplatterShaderProperty;

class NiNode;
class BSGeometry;

class BSShaderProperty
{
public:
    virtual ~BSShaderProperty();      // 00
    virtual void    Unk_01();         // 01
    virtual NiRTTI* GetRTTI() const;  // 02

    std::uint8_t unknown008[0xA0];  // 008
    void*        alphaSource;       // 0A8
};
static_assert(offsetof(BSShaderProperty, alphaSource) == 0xA8, "alphaSource offset");

class NiAVObject
{
public:
    virtual ~NiAVObject();             // 00
    virtual void        Unk_01();      // 01
    virtual void        Unk_02();      // 02
    virtual NiNode*     AsNode();      // 03
    virtual void        Unk_04();      // 04
    virtual void        Unk_05();      // 05
    virtual void        Unk_06();      // 06
    virtual BSGeometry* AsGeometry();  // 07

    static void SetBloodSplatterAlphaSourceRecursive(NiAVObject* object, void* alphaSource);
};

class BSGeometry : public NiAVObject
{
public:
    std::uint8_t      unknown008[0x120];  // 008
    BSShaderProperty* shaderProperty;     // 128
};
static_assert(offsetof(BSGeometry, shaderProperty) == 0x128, "shaderProperty offset");

class NiNode : public NiAVObject
{
public:
    std::uint8_t  unknown008[0x110];  // 008
    NiAVObject**  children;           // 118
    std::uint16_t childrenCapacity;   // 120
    std::uint16_t childrenSize;       // 122
};
static_assert(offsetof(NiNode, children) == 0x118, "children offset");
static_assert(offsetof(NiNode, childrenSize) == 0x122, "childrenSize offset");
