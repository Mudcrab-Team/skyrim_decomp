// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// Func00b5a590, Func00b5a590::~Func00b5a590: GUESS(low); placeholder name
#pragma once


struct S_EffectArray
{
    void SetSize(unsigned int size);
};

struct ImageSpaceEffect
{
    virtual ~ImageSpaceEffect();
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    S_EffectArray m_effectTextures;
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

    ImageSpaceEffect();
};

struct ImageSpaceTexture
{
    unsigned char m_00;
    unsigned char m_01;
    unsigned char m_02;
    int m_04;
    int m_08;
    int m_0c;

    ImageSpaceTexture()
    {
        m_00 = 0;
        m_01 = 0;
        m_02 = 0;
        m_04 = 0;
        m_08 = 0;
        m_0c = 0;
    }
    ~ImageSpaceTexture();
};

struct FourFloatVector
{
    float x, y, z, w;
    FourFloatVector()
    {}
    FourFloatVector(float _x, float _y, float _z, float _w) : x(_x), y(_y), z(_z), w(_w)
    {}
};

struct S_00b5a590_Matrix
{
    FourFloatVector m_00;
    FourFloatVector m_10;
    FourFloatVector m_20;
    FourFloatVector m_30;
    float m_40;
    int unk44;

    S_00b5a590_Matrix()
    {
        float zero = 0.0f;
        m_00.x = zero;
        m_00.y = zero;
        m_00.z = zero;
        m_00.w = zero;
        m_10.x = zero;
        m_10.y = zero;
        m_10.z = zero;
        m_10.w = zero;
        m_20.x = zero;
        m_20.y = zero;
        m_20.z = zero;
        m_20.w = zero;
        m_30.x = zero;
        m_30.y = zero;
        m_30.z = zero;
        m_30.w = zero;
    }
};

struct Func00b5a590 : ImageSpaceEffect
{
    int unk58;
    S_00b5a590_Matrix m_5c;
    ImageSpaceTexture m_texA4;
    ImageSpaceTexture m_texB4[2];

    Func00b5a590();
    ~Func00b5a590();
};
