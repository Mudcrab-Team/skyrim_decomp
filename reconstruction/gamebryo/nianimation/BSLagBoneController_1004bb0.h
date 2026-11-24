// Source exposure: mixed (names and declarations from the sibling decompilation; the pinned image listing).
// Code origin: adapted from the sibling decompilation named in the .cpp; stand-in declarations come from it too.
// SPDX-License-Identifier: CC0-1.0
// BSLagBoneController, BSLagBoneController::~BSLagBoneController: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

struct NiColor;

extern NiColor Data011f4998;


class NiColor
{
  public:
    float r, g, b;
    NiColor() : r(0), g(0), b(0)
    {}
};

class NiProperty
{
  public:
    NiProperty();
    virtual ~NiProperty();
    unsigned char data[20];
};

class NiFogProperty : public NiProperty
{
  public:
    virtual ~NiFogProperty();
    unsigned short m_uiObjectFlags;
    float m_fFogDepth;
    NiColor m_kFogTint;
    NiFogProperty()
    {
        m_uiObjectFlags = 0;
        m_fFogDepth = 1.0f;
        m_kFogTint = Data011f4998;
    }
};

class NiPlane
{
  public:
    NiPlane();
    float x, y, z, c;
};

class BSLagBoneController : public NiFogProperty
{
  public:
    BSLagBoneController();
    virtual ~BSLagBoneController();
    float m_fFogStartDistance, m_fFogEndDistance, m_fFogParameterA, m_fFogParameterB;
    NiPlane m_kFogPlane;
    float fFalloff, m_fGlyphExtent;
    NiColor m_kFogColor;
    float m_fAlpha;
};
