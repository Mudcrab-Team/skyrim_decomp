// Source exposure: mixed
// Origin: original reconstruction from independently decoded target and anonymous sibling.
// Declarations: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); adapted from include/RE/S/ShaderReferenceEffect.h, RE/R/ReferenceEffect.h, RE/B/BSTempEffect.h, BSTArray.h, BSSoundHandle.h, and RE/N/NiRefObject.h.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// names: GUESS(low); names and method signatures require independent review.
#pragma once
class NiAVObject; class NiSourceTexture; class TESBoundObject; class TESEffectShader; class BSEffectShaderData; class TESObjectCELL; class ReferenceEffectController;
template<class T> struct ArrayAllocator { T* data; unsigned capacity; };
struct ArrayBase { unsigned size; };
template<class T> struct Array : ArrayAllocator<T>, ArrayBase {};
class NiRefObject { public: virtual ~NiRefObject(); unsigned refCount; };
class BSTempEffect : public NiRefObject { public: float lifetime; TESObjectCELL* cell; float age; bool initialized; unsigned effectID; };
class ReferenceEffect : public BSTempEffect { public: ReferenceEffectController* controller; unsigned target, aimAtTarget; bool finished, ownController; };
struct BSSoundHandle { unsigned soundID; bool assumeSuccess; unsigned state; };
class ShaderReferenceEffect : public ReferenceEffect {
public:
 struct TextureRequest { unsigned long long unknown; NiSourceTexture* texture; };
 struct ParticleShader { void* property; void* emitter; };
 Array<TextureRequest> textureRequests; Array<NiAVObject*> addonModels; Array<void*> unknownArray; Array<ParticleShader> particleShaders; Array<void*> shaderObjects;
 BSSoundHandle soundHandle; NiSourceTexture* particleShaderTexture; NiSourceTexture* particlePaletteTexture; NiSourceTexture* fillTexture; NiSourceTexture* holesTexture; NiSourceTexture* paletteTexture; NiAVObject* lastRootNode;
 TESBoundObject* wornObject; TESEffectShader* effectData; BSEffectShaderData* effectShaderData; NiAVObject* targetRoot; float alphaTimer, addonAlpha, addonScale, effectShaderAge; unsigned flags, pushCount;
 NiAVObject* Get3D(); void Push();
};
