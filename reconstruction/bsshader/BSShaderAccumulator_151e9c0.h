// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetRTTI, AsMultiIndexTriShape, GetRenderPasses, head, alphaFlags, unk20: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject, NiObject, NiObjectNET, NiProperty, NiShadeProperty, NiAVObject, NiAccumulator, NiBackToFrontAccumulator, NiAlphaAccumulator, BSShaderAccumulator, FinishAccumulatingAppendLocalMapPasses, BSGeometry, BSMultiIndexTriShape, BSShaderProperty, BSShaderPropertyLightData, BSRenderPass, RenderPassArray, BSBatchRenderer, NiAlphaProperty, NiBound, NiRTTI, modelBound, alphaProperty, flags, lightData, lastAccumulatedFrameCount, firstPerson, drawDecals, isShadowMapAccumulator, batchRenderer, renderMode, passEnum, accumulationHint, next, AppendPassToGeometryGroup: CRASHLOGGER_PDB(59818@2026.10.24)
// RegisterPassGeometryGroup, excludedPropertyRTTI, currentFrameCount, secondaryProperty: GUESS(low)
#pragma once

#include <cstdint>

class NiRTTI;
class BSGeometry;
class BSMultiIndexTriShape;
class BSShaderProperty;
class BSShaderAccumulator;
struct BSRenderPass;

struct NiBound
{
    float center[3];
    float radius;
};

class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    unsigned int refCount;
    unsigned int unrecovered0C;
};

class NiObject : public NiRefObject
{
public:
    virtual const NiRTTI* GetRTTI() const;
};

class NiObjectNET : public NiObject
{
public:
    unsigned char unrecovered010[0x20];
};

class NiProperty : public NiObjectNET
{
};

class NiAlphaProperty : public NiProperty
{
public:
    unsigned short alphaFlags;
};

class NiShadeProperty : public NiProperty
{
};

struct RenderPassArray
{
    BSRenderPass* head;
};

struct BSRenderPass
{
    unsigned char unrecovered000[0x18];
    unsigned int passEnum;
    unsigned char accumulationHint;
    unsigned char unrecovered01D[0xB];
    BSRenderPass* next;
};

struct BSShaderPropertyLightData
{
    unsigned char unrecovered000[0x20];
    unsigned char unk20;
};

class BSShaderProperty : public NiShadeProperty
{
public:
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual RenderPassArray* GetRenderPasses(BSGeometry* geometry, unsigned int renderMode, BSShaderAccumulator* accumulator);

    unsigned char unrecovered030[0x8];
    std::uint64_t flags;
    unsigned char unrecovered040[0x30];
    BSShaderPropertyLightData* lightData;
    unsigned char unrecovered078[0x8];
    unsigned int lastAccumulatedFrameCount;
};

class NiAVObject : public NiObjectNET
{
public:
    unsigned char unrecovered030[0xE0];
};

class BSGeometry : public NiAVObject
{
public:
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot1A();
    virtual void Slot1B();
    virtual void Slot1C();
    virtual void Slot1D();
    virtual void Slot1E();
    virtual void Slot1F();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26();
    virtual void Slot27();
    virtual void Slot28();
    virtual void Slot29();
    virtual void Slot2A();
    virtual void Slot2B();
    virtual void Slot2C();
    virtual void Slot2D();
    virtual void Slot2E();
    virtual void Slot2F();
    virtual void Slot30();
    virtual void Slot31();
    virtual void Slot32();
    virtual void Slot33();
    virtual void Slot34();
    virtual BSMultiIndexTriShape* AsMultiIndexTriShape();

    NiBound modelBound;
    NiAlphaProperty* alphaProperty;
};

class BSMultiIndexTriShape : public BSGeometry
{
public:
    unsigned char unrecovered128[0x88];
    BSShaderProperty* secondaryProperty;
};

class BSBatchRenderer
{
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void RegisterPassGeometryGroup(BSRenderPass* pass, unsigned int passEnum);
    void AppendPassToGeometryGroup(BSRenderPass* pass, unsigned int group, bool flag);
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
    bool FinishAccumulatingAppendLocalMapPasses(BSGeometry* geometry, BSShaderProperty* property);

    unsigned char unrecovered058[0xD0];
    bool firstPerson;
    unsigned char unrecovered129[0x3];
    bool drawDecals;
    bool isShadowMapAccumulator;
    unsigned char unrecovered12E[0x2];
    BSBatchRenderer* batchRenderer;
    unsigned char unrecovered138[0x18];
    unsigned int renderMode;
};

extern const NiRTTI excludedPropertyRTTI;
extern unsigned int currentFrameCount;
