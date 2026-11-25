// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiTriStrips, NiTriStrips::~NiTriStrips: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); declaration taken from the sibling decompilation, identity with this function unproven
#pragma once

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* apValue);
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* apValue);

struct NiD3DPass;
struct NiRefObject;

class NiMemObject
{
  public:
    static void* operator new(size_t size);
};

class NiRefObject : public NiMemObject
{
  public:
    unsigned int m_uiRefCount;
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        InterlockedIncrement(reinterpret_cast<volatile long*>(&m_uiRefCount));
    }
    void DecRefCount()
    {
        if (InterlockedDecrement(reinterpret_cast<volatile long*>(&m_uiRefCount)) == 0)
            DeleteThis();
    }
};

template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer() : m_pObject(0)
    {}
    NiPointer& operator=(T* object)
    {
        if (m_pObject != object)
        {
            if (m_pObject)
                m_pObject->DecRefCount();
            m_pObject = object;
            if (m_pObject)
                m_pObject->IncRefCount();
        }
        return *this;
    }
    operator T*() const
    {
        return m_pObject;
    }
    T* operator->() const
    {
        return m_pObject;
    }
};

struct BaseShader_00be2200
{
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    NiPointer<NiRefObject> m_spDeclaration;
    int unk2c;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;

    BaseShader_00be2200();
    virtual ~BaseShader_00be2200();
};

struct FourFloatVector
{
    float x, y, z, w;
    FourFloatVector() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
    {}
};

struct NiD3DPass
{
    static void CreateD3DPass(NiD3DPass*& pass);
};

struct PassPointer
{
    NiD3DPass* m_pObject;
    PassPointer();
    ~PassPointer();
};

struct ShaderPointer
{
    NiRefObject* m_pObject;
    ShaderPointer();
    ~ShaderPointer();
};

struct NiTriStrips : BaseShader_00be2200
{
    int m_field68;
    PassPointer table6c[1];
    float m_field70;
    int m_field74;
    char m_field78;
    char unk79;
    char unk7a;
    char unk7b;
    ShaderPointer maps7c[4];
    ShaderPointer maps8c[2];
    void* m_uiInstanceData;
    unsigned int m_count98;
    unsigned short m_usInstanceDataCount;
    char unk9e;
    char unk9f;
    FourFloatVector m_afAmbientColor;
    FourFloatVector m_diffuseDirection;
    FourFloatVector m_afDiffuseColor;
    FourFloatVector m_alphaTestRef;
    FourFloatVector m_eyeVector;
    FourFloatVector m_eyeRightVector;

    NiTriStrips();
    virtual ~NiTriStrips();
};
