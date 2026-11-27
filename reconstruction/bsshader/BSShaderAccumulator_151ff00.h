// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, BSShaderAccumulator, RenderDecalPassesAlt, RenderBatches, BSBatchRenderer, GeometryGroup, RendererShadowState, drawDecals, isShadowMapAccumulator, batchRenderer, geometryGroups, flags: CRASHLOGGER_PDB(59818@2026.10.24)
// RenderSettings, GetRenderSettings, shadowState, RenderGroup, RenderGeometryGroup, SetDepthMode, SetFillMode, SetDepthBiasMode, SetAlphaBlendMode, SetAlphaBlendWriteMode, updateFlags, depthMode, depthModePrevious, fillMode, depthBiasMode, blendMode, blendWriteMode, useAltDepthBias: GUESS(low)
#pragma once

struct GeometryGroup
{
    unsigned char unrecovered000[0x26];
    unsigned char flags;

    void RenderGroup(unsigned int renderFlags);
};

class BSBatchRenderer
{
public:
    virtual ~BSBatchRenderer();

    unsigned char unrecovered008[0x68];
    GeometryGroup* geometryGroups[16];
};

struct RenderSettings
{
    unsigned char unrecovered000[0x51];
    bool useAltDepthBias;
};

struct RendererShadowState
{
    unsigned int updateFlags;
    unsigned char unrecovered004[0x84];
    unsigned int depthMode;
    unsigned int depthModePrevious;
    unsigned char unrecovered090[0x8];
    unsigned int fillMode;
    unsigned char unrecovered09C[0x4];
    unsigned int depthBiasMode;
    unsigned char unrecovered0A4[0x4];
    unsigned int blendMode;
    unsigned char unrecovered0AC[0x8];
    unsigned char blendWriteMode;

    void SetDepthMode(unsigned int mode)
    {
        if (depthMode != mode) {
            depthMode = mode;
            if (depthModePrevious != mode) {
                updateFlags |= 0x4u;
            } else {
                updateFlags &= ~0x4u;
            }
        }
    }

    void SetFillMode(unsigned int mode)
    {
        if (fillMode != mode) {
            fillMode = mode;
            updateFlags |= 0x10u;
        }
    }

    void SetDepthBiasMode(unsigned int mode)
    {
        if (depthBiasMode != mode) {
            depthBiasMode = mode;
            updateFlags |= 0x40u;
        }
    }

    void SetAlphaBlendMode(unsigned int mode)
    {
        if (blendMode != mode) {
            blendMode = mode;
            updateFlags |= 0x80u;
        }
    }

    void SetAlphaBlendWriteMode(unsigned char mode)
    {
        if (blendWriteMode != mode) {
            blendWriteMode = mode;
            updateFlags |= 0x100u;
        }
    }
};

class NiRefObject
{
public:
    virtual ~NiRefObject();
    unsigned int refCount;
    unsigned int unrecovered0C;
};

class NiObject : public NiRefObject
{
};

class NiAccumulator : public NiObject
{
public:
    void* unrecovered010;
};

class NiBackToFrontAccumulator : public NiAccumulator
{
public:
    unsigned char unrecovered018[0x38];
};

class NiAlphaAccumulator : public NiBackToFrontAccumulator
{
public:
    unsigned char unrecovered050[0x8];
};

class BSShaderAccumulator : public NiAlphaAccumulator
{
public:
    void RenderDecalPassesAlt(unsigned int renderFlags);
    void RenderBatches(unsigned int firstPass, unsigned int lastPass, unsigned int renderFlags, int group);

private:
    void RenderGeometryGroup(int index, unsigned int renderFlags);

    unsigned char unrecovered058[0xD4];
    bool drawDecals;
    bool isShadowMapAccumulator;
    unsigned char unrecovered12E[0x2];
    BSBatchRenderer* batchRenderer;
};

RenderSettings* GetRenderSettings();
extern RendererShadowState shadowState;
