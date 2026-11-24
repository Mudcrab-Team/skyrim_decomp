// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// ISEntry, ISEntry::~ISEntry: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

struct B6FC90Color
{
    B6FC90Color(float fR, float fG, float fB, float fA) : r(fR), g(fG), b(fB), a(fA)
    {}

    float r;
    float g;
    float b;
    float a;
};

class B6FC90Property
{
  public:
    B6FC90Property();
    virtual ~B6FC90Property();

    int unk04;
    int unk08;
    int unk0C;
    int unk10;
    int unk14;
    int unk18;
    int m_iShaderIndex;
    unsigned int m_auiFlags[2];
    int unk28;
    int unk2C;
    int unk30;
    int unk34;
    int m_iLastRenderPass;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
    int unk50;
    int unk54;
    int m_iShaderType;
    int unk5C;

    void SetFlag(unsigned int uiBit)
    {
        unsigned int uiMask = 1u << (uiBit & 31);
        if (!(m_auiFlags[uiBit >> 5] & uiMask))
            m_iLastRenderPass = 0;
        m_auiFlags[uiBit >> 5] |= uiMask;
    }
};

struct B6FC90Range
{
    B6FC90Range() : m_usStart(0), m_usEnd(0)
    {}

    unsigned short m_usStart;
    unsigned short m_usEnd;
};

class ISEntry : public B6FC90Property
{
  public:
    ISEntry();
    virtual ~ISEntry();

    int m_iFirst;
    int m_iSecond;
    B6FC90Range m_kRange;
    int m_iMode;
    B6FC90Color m_kFogTint;
};
