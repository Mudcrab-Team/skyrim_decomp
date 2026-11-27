// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: BSShaderAccumulator::AccumulateObject follows the project unit BSShaderAccumulator_151e2f0.cpp.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GetRTTI, AsGeometry, AsParticlesGeom, skinInstance, rendererData, type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// AccumulateNodeChildren, AccumulateSceneGraphContext, BSShaderAccumulator, AccumulateObject, NiRefObject, NiObject, NiObjectNET, NiAVObject, NiNode, BSGeometry, BSShaderProperty, BSShaderPropertyLightData, BSDismemberSkinInstance, NiRTTI, accumulator, filterByShaderProperty, children, flags, shaderProperty, lightData, activeLightMask, unk98, renderMode, flagOverrideMode, flagOverrideMask: CRASHLOGGER_PDB(59818@2026.10.24)
// NiChildArray, CanCastShadow, dismemberType, dispatchTable, data, capacity, freeSlot, size, growBy, particleShaderDynamicTriShape: GUESS(low)
#pragma once

#include <cstdint>

class NiRTTI;
class NiNode;
class BSGeometry;
class BSShaderAccumulator;

struct BSShaderPropertyLightData
{
    unsigned char unrecovered000[0x1C];
    unsigned int activeLightMask;
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
    virtual NiNode* AsNode();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual BSGeometry* AsGeometry();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void Slot0E();
    virtual void Slot0F();
    virtual void* AsParticlesGeom();
};

class NiObjectNET : public NiObject
{
public:
    unsigned char unrecovered010[0x20];
};

class NiProperty : public NiObjectNET
{
};

class NiShadeProperty : public NiProperty
{
};

class BSShaderProperty : public NiShadeProperty
{
public:
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
    virtual void Slot35();
    virtual void Slot36();
    virtual void Slot37();
    virtual void Slot38();
    virtual void Slot39();
    virtual void Slot3A();
    virtual void Slot3B();
    virtual bool CanCastShadow() const;

    unsigned char unrecovered030[0x8];
    std::uint64_t flags;
    unsigned char unrecovered040[0x30];
    BSShaderPropertyLightData* lightData;
};

class BSDismemberSkinInstance : public NiObject
{
public:
    unsigned char unrecovered010[0x88];
    bool unk98;
};

class NiAVObject : public NiObjectNET
{
public:
    unsigned char unrecovered030[0xC4];
    unsigned int flags;
    unsigned char unrecovered0F8[0x18];
};

class BSGeometry : public NiAVObject
{
public:
    unsigned char unrecovered110[0x18];
    BSShaderProperty* shaderProperty;
    NiObject* skinInstance;
    void* rendererData;
    unsigned char unrecovered140[0x10];
    unsigned char type;
};

struct NiChildArray
{
    virtual ~NiChildArray();
    NiAVObject** data;
    unsigned short capacity;
    unsigned short freeSlot;
    unsigned short size;
    unsigned short growBy;
};

class NiNode : public NiAVObject
{
public:
    NiChildArray children;
};

class NiAccumulator : public NiObject
{
public:
    unsigned char unrecovered010[0x8];
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
    bool AccumulateObject(BSGeometry* geometry, unsigned long long argument);

    unsigned char unrecovered058[0xF8];
    int renderMode;
    unsigned char unrecovered154[0xC];
    unsigned int flagOverrideMode;
    unsigned int flagOverrideMask;
};

struct AccumulateSceneGraphContext
{
    BSShaderAccumulator* accumulator;
    bool filterByShaderProperty;
};

extern const NiRTTI dismemberType;
using Dispatch = bool (*)(BSShaderAccumulator*, BSGeometry*, BSShaderProperty*, unsigned long long);
extern Dispatch dispatchTable[];

unsigned int AccumulateNodeChildren(AccumulateSceneGraphContext* context, NiNode* node);
