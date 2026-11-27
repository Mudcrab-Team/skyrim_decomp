// Source exposure: mixed (pinned-image listing and community declarations).
// Code origin: original reconstruction from the local listing.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSGeometry virtuals, BSShader virtuals, BSDynamicTriShape and dataSize: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// RenderPassImmediately_Standard, BSRenderPass, BSShader, Partition, numBones, NiSkinPartition_DrawContext, SetBoneMatrices, BSGraphics::Renderer, MapDynamicBuffer, world, skinInstance, GetNiProperty, material, BSShaderProperty, shaderProperty, lodMode: CRASHLOGGER_PDB(59818@2026.10.24)
// PrepareDraw, PrepareGeometry, LockGeometry, UnlockGeometry, CopyGeometryData, DrawPass, UnmapDynamicBuffer, Draw, flags, renderer, DrawStandardGeometry, DrawCustomGeometry, ApplyAlphaState and SetAlphaTestRef owner: GUESS(low)
#pragma once
#include "BSRenderPass_1560c80.h"

#include "gamebryo/nimain/NiAVObject.h"
#include <cstddef>

class NiAlphaProperty;
struct BSShaderProperty;
class BSMultiIndexTriShape;
class BSSkinnedDecalTriShape;
struct NiSkinInstance;

class BSGeometry : public NiAVObject
{
public:
    virtual BSMultiIndexTriShape* AsMultiIndexTriShape();
    virtual BSSkinnedDecalTriShape* AsSkinnedDecalTriShape();

    NiBound modelBound;
    NiAlphaProperty* alphaProperty;
    BSShaderProperty* shaderProperty;
    NiSkinInstance* skinInstance;
    unsigned char unrecovered138[0x20];
};

class BSDynamicTriShape : public BSGeometry
{
public:
    void* LockGeometry();
    void UnlockGeometry();

    unsigned char unrecovered158[0x18];
    unsigned int dataSize;
};

static_assert(offsetof(BSGeometry, skinInstance) == 0x130, "skin instance offset");
static_assert(offsetof(BSDynamicTriShape, dataSize) == 0x170, "dynamic data size offset");

struct BSRenderPass;
struct BSShaderMaterial;
struct NiSkinPartition_DrawContext;
struct NiSkinInstance : NiObject
{
    virtual void Draw(NiSkinPartition_DrawContext& context);
};

struct Partition
{
    Partition();
    ~Partition();
    unsigned char unrecovered000[0x3C];
    unsigned short numBones;
    unsigned char unrecovered03E[0x12];
};

class NiBoneMatrixSetterI
{
public:
    virtual ~NiBoneMatrixSetterI();
    virtual void SetBoneMatrices(NiSkinInstance*, Partition&, const NiTransform* worldTransform);
};

class BSShader : public NiRefObject, public NiBoneMatrixSetterI
{
public:
    virtual bool SetupTechnique(unsigned int technique);
    virtual void RestoreTechnique(unsigned int technique);
    virtual void SetupMaterial(const BSShaderMaterial*);
    virtual void RestoreMaterial(const BSShaderMaterial*);
    virtual void SetupGeometry(BSRenderPass*, unsigned int flags);
    virtual void RestoreGeometry(BSRenderPass*, unsigned int flags);
    void ApplyAlphaState(NiAlphaProperty* alpha, BSShaderProperty* property, bool custom);
    void SetAlphaTestRef(NiAlphaProperty* alpha, BSShaderProperty* property);
};

struct BSShaderProperty
{
    unsigned char unrecovered000[0x78];
    BSShaderMaterial* material;
};



struct NiSkinPartition_DrawContext
{
    NiBoneMatrixSetterI* setter;
    BSGeometry* geometry;
    unsigned long long unk10;
    unsigned int singleLevel;
    unsigned int lodIndex;
    float unk20;
    unsigned int dynamicBufferOffset;
};

namespace BSGraphics
{
    struct Renderer
    {
        void* MapDynamicBuffer(unsigned int size, unsigned int* offset);
        void UnmapDynamicBuffer(void* mapped);
    };
}
extern BSGraphics::Renderer renderer;
void PrepareDraw();
void PrepareGeometry(BSRenderPass* pass, BSShader* shader, bool alpha, unsigned int flags);

int CopyGeometryData(void* destination, unsigned long long capacity, const void* source, unsigned long long size);

inline void BSRenderPass::DrawCustomGeometry(unsigned int flags)
{
    BSShader* passShader = shader;
    passShader->SetupGeometry(this, flags);
    passShader->ApplyAlphaState(GetNiProperty(), shaderProperty, true);
    if (GetNiProperty()) {
        passShader->SetAlphaTestRef(GetNiProperty(), shaderProperty);
    }
    DrawPass();
    passShader->RestoreGeometry(this, flags);
}

inline void BSRenderPass::DrawStandardGeometry(bool alpha, unsigned int flags)
{
    BSGeometry* passGeometry = geometry;
    BSShader* passShader = shader;
    NiSkinInstance* skin = passGeometry->skinInstance;
    PrepareDraw();
    if (!passGeometry->AsSkinnedDecalTriShape()) {
        PrepareGeometry(this, passShader, alpha, flags);
        const unsigned int lod = lodMode;
        BSDynamicTriShape* dynamic = passGeometry->AsDynamicTriShape();
        NiBoneMatrixSetterI* setter = passShader;
        NiSkinPartition_DrawContext context;
        context.setter = setter;
        context.geometry = passGeometry;
        context.unk10 = 0;
        context.singleLevel = lod >> 7;
        context.lodIndex = lod & ~0x80u;
        context.unk20 = 0.0f;
        context.dynamicBufferOffset = ~0u;
        if (dynamic) {
            void* mapped = renderer.MapDynamicBuffer(dynamic->dataSize, &context.dynamicBufferOffset);
            const unsigned int size = dynamic->dataSize;
            CopyGeometryData(mapped, size, dynamic->LockGeometry(), size);
            renderer.UnmapDynamicBuffer(mapped);
            dynamic->UnlockGeometry();
        }
        skin->Draw(context);
    } else {
        PrepareGeometry(this, passShader, alpha, flags);
        Partition partition;
        partition.numBones = 1;
        passShader->SetBoneMatrices(passGeometry->skinInstance, partition, &passGeometry->world);
        DrawPass();
    }
    passShader->RestoreGeometry(this, flags);
}

void RenderPassImmediately_Standard(BSRenderPass* pass, bool alpha, unsigned int flags);
