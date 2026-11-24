// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// NiAmbientLight, NiAmbientLight::~NiAmbientLight: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPointer: SIBLING(momusdigital/f3_decomp@f5bac1b5, CC0-1.0); declaration taken from the sibling decompilation, identity with this function unproven
#pragma once

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long*);


struct Func00b71720
{
    Func00b71720();
    virtual ~Func00b71720();
    unsigned int field04;
    unsigned int field08;
    unsigned int field0c;
    unsigned int field10;
    unsigned int field14;
    unsigned int field18;
    unsigned int field1c;
    unsigned int field20;
    unsigned int field24;
    unsigned int field28;
    unsigned int field2c;
    unsigned int field30;
    unsigned int field34;
    unsigned int field38;
    unsigned int field3c;
    unsigned int field40;
    unsigned int field44;
    unsigned int field48;
    unsigned int field4c;
    unsigned int field50;
    unsigned int field54;
    unsigned int field58;
    unsigned int field5c;
    unsigned int field60;
    unsigned int field64;
    unsigned int field68;
    unsigned int field6c;
    unsigned int field70;
    unsigned int field74;
    unsigned int field78;
    unsigned int field7c;
    unsigned int field80;
    void SetFlag(unsigned int flag)
    {
        if (!(field20 & flag))
            field38 = 0;
        *(volatile unsigned int*)&field20 |= flag;
    }
};

class NiTexture
{
  public:
    virtual ~NiTexture();
    virtual void DeleteThis();
    long m_uiRefCount;
    void DecRefCount()
    {
        if (InterlockedDecrement(&m_uiRefCount) == 0)
        {
            DeleteThis();
        }
    }
};

struct ShaderVector8
{
    float x1, y1, z1, w1;
    float x2, y2, z2, w2;
    ShaderVector8() : x1(0.0f), y1(0.0f), z1(0.0f), w1(0.0f), x2(0.0f), y2(0.0f), z2(0.0f), w2(0.0f)
    {}
};

template <class T> class NiPointer
{
  public:
    T* object;
    NiPointer()
    {
        *(T* volatile*)&object = 0;
    }
    ~NiPointer()
    {
        if (object)
            object->DecRefCount();
    }
    NiPointer& operator=(T* value)
    {
        if (object != value)
        {
            if (object)
                object->DecRefCount();
            object = value;
        }
        return *this;
    }
    static void* operator new[](size_t size)
    {
        return _g_memoryManager.Allocate(size);
    }
    static void operator delete[](void* p)
    {}
};

struct NiAmbientLight : Func00b71720
{
    ShaderVector8 vectors;
    NiPointer<NiTexture> referencea4;
    unsigned short count;
    NiPointer<NiTexture>* textures[6];
    unsigned char* channels;
    unsigned int fieldc8;
    unsigned char* enabled;
    NiPointer<NiTexture> referenced0;
    unsigned int fieldd4, fieldd8;
    NiPointer<NiTexture> referencedc;
    float valuee0;
    unsigned int fielde4;
    float valuee8, valueec;
    unsigned int fieldf0, fieldf4, fieldf8, fieldfc;
    void* field100;
    NiAmbientLight();
    virtual ~NiAmbientLight();
};
