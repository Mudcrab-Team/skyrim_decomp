// Source exposure: mixed (pinned image, community declarations and published reconstruction references).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: declarations adapted from pinned CommonLibSSE-NG and existing material units; allocation and ownership bodies reconstructed from the pinned image; independently written helpers overlap the sibling bodies listed below.
// Adapted bodies: NiColor default constructor, CommonLibSSE-NG include/RE/N/NiColor.h at b93280e.
// BSShaderMaterial, BSLightingShaderMaterialBase, NiPoint2, NiColor, NiRefObject, NiPointer, Create, CopyMembers, DoIsCopy, ComputeCRC32, GetDefault, GetFeature, GetType, OnLoadTextureSet, ClearTextures, ReceiveValuesFromRootMaterial, GetTextures, SaveBinary, LoadBinary, IncRefCount, DecRefCount, DeleteThis, _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ShaderMemoryManager, shaderMemoryManager, Initialize, Allocate, state, SnowParameters, snowDefaults, hairTintDefaults, fields: GUESS(low) STANDIN
// CRC seed argument, accessed member offsets and allocation-state field: OBSERVED
// NiObject, BSTextureSet, Texture, kDiffuse, GetTexturePath, SetTexture, SetTexturePath: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/bshavok/bhkrigidbody_h_unit.cpp -- MemoryContextGuard destructor; independently reconstructed overlap, CC0-1.0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bshavok/bhkrigidbody_h_unit.cpp -- MemoryContextGuard destructor; independently reconstructed overlap, CC0-1.0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/imagespaceshadermenuunpack.cpp -- NiRefObject::IncRefCount; independently reconstructed overlap, CC0-1.0.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/staging/blk_00a40000_o2.cpp -- NiPointer destructor; independently reconstructed overlap, CC0-1.0.
// Sibling source: momusdigital/f3_decomp@f5bac1b5 include/layout_support.h -- NiPointer destructor; independently reconstructed overlap, CC0-1.0.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/niconsolerenderer/nid3dshaderconstantmap.cpp -- NiPointer::operator=; independently reconstructed overlap, CC0-1.0.
/*
MIT License

Copyright (c) 2018 Ryan-rsm-McKenzie

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#pragma once
#include <cstddef>
#include <cstdint>
#include <intrin.h>
#include "BSShaderMaterial_15757c0.h"

class NiStream;
class BSTextureSet;
class NiColor
{
public:
    constexpr NiColor() noexcept : red(0.0F), green(0.0F), blue(0.0F) {}
    float red;
    float green;
    float blue;
};
struct SnowParameters { float first; float second; float third; float fourth; };
extern SnowParameters snowDefaults;
extern NiColor hairTintDefaults;

class ShaderMemoryManager
{
public:
    void Initialize(unsigned int* state);
    void* Allocate(std::size_t size, int alignment, bool aligned);
    unsigned char unrecovered000[0x488];
    unsigned int state;
};
extern ShaderMemoryManager shaderMemoryManager;

extern __declspec(thread) unsigned int g_memoryContext;
class MemoryContextGuard
{
public:
    explicit MemoryContextGuard(unsigned int context) : previous(g_memoryContext)
    {
        g_memoryContext = context;
    }
    ~MemoryContextGuard() { g_memoryContext = previous; }
private:
    unsigned int previous;
};


class NiRefObject
{
public:
    virtual ~NiRefObject();
    virtual void DeleteThis();
    void IncRefCount()
    {
        // Intrusive ownership uses the observed atomic reference-count update.
        _InterlockedIncrement(&refCount);
    }
    void DecRefCount()
    {
        // The atomic decrement returns the previous reference count.
        if (_InterlockedExchangeAdd(&refCount, -1) == 1) {
            DeleteThis();
        }
    }
    // volatile: the pinned image uses interlocked reference-count operations.
    volatile long refCount;
};
template<class T> class NiPointer
{
public:
    NiPointer() : texture(nullptr) {}
    ~NiPointer()
    {
        if (texture) texture->DecRefCount();
    }
    NiPointer& operator=(T* next)
    {
        T* previous = texture;
        if (previous != next) {
            if (next) next->IncRefCount();
            texture = next;
            if (previous) previous->DecRefCount();
        }
        return *this;
    }
    T* texture;
};

inline void* BSShaderMaterial::operator new(std::size_t size)
{
    if (shaderMemoryManager.state != 2) {
        shaderMemoryManager.Initialize(&shaderMemoryManager.state);
    }
    return shaderMemoryManager.Allocate(size, 0, false);
}

class BSDynamicTriShape;
class BSFadeNode;
class BSGeometry;
class bhkAttachmentCollisionObject;
class bhkBlendCollisionObject;
class bhkLimitedHingeConstraint;
class bhkNiCollisionObject;
class bhkRigidBody;
class BSLines;
class BSMultiBoundNode;
class BSSegmentedTriShape;
class BSSubIndexTriShape;
class BSTriShape;
class NiCloningProcess;
class NiControllerManager;
class NiGeometry;
class NiNode;
class NiObjectGroup;
class NiParticles;
class NiRTTI;
class NiStream;
class NiSwitchNode;
class NiTriBasedGeom;
class NiTriShape;
class NiTriStrips;
class NiSourceTexture;
class NiObject : public NiRefObject
{
public:
    ~NiObject() override;
    virtual const NiRTTI*   GetRTTI() const;
    virtual NiNode*                       AsNode();
    virtual NiSwitchNode*                 AsSwitchNode();
    virtual BSFadeNode*                   AsFadeNode();
    virtual BSMultiBoundNode*             AsMultiBoundNode();
    virtual BSGeometry*                   AsGeometry();
    virtual NiTriStrips*                  AsTriStrips();
    virtual BSTriShape*                   AsTriShape();
    virtual BSSegmentedTriShape*          AsSegmentedTriShape();
    virtual BSSubIndexTriShape*           AsSubIndexTriShape();
    virtual BSDynamicTriShape*            AsDynamicTriShape();
    virtual NiGeometry*                   AsNiGeometry();
    virtual NiTriBasedGeom*               AsNiTriBasedGeom();
    virtual NiTriShape*                   AsNiTriShape();
    virtual NiParticles*                  AsParticlesGeom();
    virtual BSLines*                      AsLinesGeom();
    virtual bhkNiCollisionObject*         AsBhkNiCollisionObject();
    virtual bhkBlendCollisionObject*      AsBhkBlendCollisionObject();
    virtual bhkAttachmentCollisionObject* AsBhkAttachmentCollisionObject();
    virtual bhkRigidBody*                 AsBhkRigidBody();
    virtual bhkLimitedHingeConstraint*    AsBhkLimitedHingeConstraint();
    virtual NiObject*                     CreateClone(NiCloningProcess& a_cloning);
    virtual void                          LoadBinary(NiStream& a_stream);
    virtual void                          LinkObject(NiStream& a_stream);
    virtual bool                          RegisterStreamables(NiStream& a_stream);
    virtual void                          SaveBinary(NiStream& a_stream);
    virtual bool                          IsEqual(NiObject* a_object);
    virtual void                          ProcessClone(NiCloningProcess& a_cloning);
    virtual void                          PostLinkObject(NiStream& a_stream);
    virtual bool                          StreamCanSkip();
    virtual const NiRTTI*   GetStreamableRTTI() const;
    virtual std::uint32_t   GetBlockAllocationSize() const;
    virtual NiObjectGroup*  GetGroup() const;
    virtual void                          SetGroup(NiObjectGroup* a_group);
    virtual NiControllerManager*          AsNiControllerManager();
};
class BSTextureSet : public NiObject
{
public:
    enum Texture : unsigned int { kDiffuse = 0 };
    ~BSTextureSet() override;
    const NiRTTI* GetRTTI() const override;
    void LoadBinary(NiStream&) override;
    void LinkObject(NiStream&) override;
    bool RegisterStreamables(NiStream&) override;
    void SaveBinary(NiStream&) override;
    bool IsEqual(NiObject*) override;
    virtual const char* GetTexturePath(Texture texture) = 0;
    virtual void SetTexture(Texture texture, NiSourceTexture* source) = 0;
    virtual void SetTexturePath(Texture texture, const char* path) = 0;
};

class BSLightingShaderMaterialBase : public BSShaderMaterial
{
public:
    BSLightingShaderMaterialBase();
    ~BSLightingShaderMaterialBase() override;
    BSShaderMaterial* Create() override;
    void CopyMembers(BSShaderMaterial*) override;
    bool DoIsCopy(BSShaderMaterial*) override;
    unsigned int ComputeCRC32(unsigned int seed) override;
    BSShaderMaterial* GetDefault() override;
    Feature GetFeature() const override;
    Type GetType() const override;
    virtual void OnLoadTextureSet(std::uint64_t, BSTextureSet*);
    virtual void ClearTextures();
    virtual void ReceiveValuesFromRootMaterial(bool, bool, bool, bool, bool);
    virtual unsigned int GetTextures(NiRefObject** textures)
    {
        unsigned int count = 0;
        if (texture48.texture) textures[count++] = texture48.texture;
        if (texture58.texture) textures[count++] = texture58.texture;
        if (texture60.texture) textures[count++] = texture60.texture;
        if (texture68.texture) textures[count++] = texture68.texture;
        return count;
    }
    virtual void SaveBinary(NiStream&);
    virtual void LoadBinary(NiStream&);
    unsigned char unrecovered38[0x10];
    NiPointer<NiRefObject> texture48;
    std::uint64_t unrecovered50;
    NiPointer<NiRefObject> texture58;
    NiPointer<NiRefObject> texture60;
    NiPointer<NiRefObject> texture68;
    unsigned char unrecovered70[8];
    NiPointer<BSTextureSet> textureSet;
    unsigned char unrecovered80[0x20];
};
static_assert(sizeof(BSLightingShaderMaterialBase) == 0xA0, "lighting material layout");



extern "C" __declspec(dllimport) int __cdecl _stricmp(const char*, const char*);
