// Code origin: declarations extended by hand from the local listings; names follow the community headers.
// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// BSLightingShaderMaterialSnow: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSLightingShaderMaterialSnow::GetFeature, BSLightingShaderMaterialSnow::CopyMembers, BSLightingShaderMaterialSnow::Ctor, BSLightingShaderMaterialSnow::ComputeCRC32: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unknownA0: GUESS(low)
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSLightingShaderMaterialSnow::SaveBinary, BSLightingShaderMaterialSnow::LoadBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e832f263dbef44e44cbe2936622a02f91a, MIT); names only, the bodies are written from the target listing
// SnowData::SaveStream, SnowData::LoadStream: GUESS(low); addresses 0xef32b0 and 0xef31c0, called on the member at offset 0xA0 with the stream
#pragma once

#include <cstdint>
// NiStream, BSTextureSet: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declarations only
class NiStream;
class BSTextureSet;

// BSShaderMaterial: STANDIN EXE_RTTI; class name and base from the image RTTI, 8 primary vftable slots
// BSShaderMaterial::Feature, BSShaderMaterial::Type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// sizeof BSShaderMaterial 0x38: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
// _refCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); member of NG's base BSIntrusiveRefCounted, declared here directly
// unk0C: GUESS(low); members not recovered yet, sized so the static_assert holds
// kDefault, kBase, kEffect, kLighting, kWater: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); Feature lists only its first enumerator here
// Create, CopyMembers, DoIsCopy, ComputeCRC32, GetDefault, GetFeature, GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); BSShaderMaterial virtuals, slots 01 to 07
class BSShaderMaterial
{
public:
	enum class Feature
	{
		kDefault = 0,
	};

	enum class Type
	{
		kBase = 0,
		kEffect = 1,
		kLighting = 2,
		kWater = 3
	};

	virtual ~BSShaderMaterial();  // 00
	virtual BSShaderMaterial* Create();  // 01
	virtual void CopyMembers(BSShaderMaterial* a_other);  // 02
	virtual bool DoIsCopy(BSShaderMaterial* a_other);  // 03
	virtual std::uint32_t ComputeCRC32();  // 04
	virtual BSShaderMaterial* GetDefault();  // 05
	virtual Feature GetFeature() const;  // 06
	virtual Type GetType() const;  // 07

	volatile std::uint32_t _refCount;  // 08
	std::uint8_t           unk0C[0x2C];  // 0C
};
static_assert(sizeof(BSShaderMaterial) == 0x38, "layout");

// BSLightingShaderMaterialBase: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI; class name and base from the image RTTI, 14 primary vftable slots
// sizeof BSLightingShaderMaterialBase 0xA0: OBSERVED; size argument of operator delete in the deleting destructor (slot 0)
// Create, CopyMembers, DoIsCopy, ComputeCRC32, GetDefault, GetFeature, GetType, OnLoadTextureSet, ClearTextures, ReceiveValuesFromRootMaterial, GetTextures, SaveBinary, LoadBinary: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slots 01 to 0D
class BSLightingShaderMaterialBase : public BSShaderMaterial
{
public:
	// BSLightingShaderMaterialBase::BSLightingShaderMaterialBase: OBSERVED; called by Snow at 0x15235f0
	BSLightingShaderMaterialBase();
	~BSLightingShaderMaterialBase() override;  // 00
	BSShaderMaterial* Create() override;  // 01
	void CopyMembers(BSShaderMaterial* a_other) override;  // 02
	bool DoIsCopy(BSShaderMaterial* a_other) override;  // 03
	std::uint32_t ComputeCRC32() override;  // 04
	BSShaderMaterial* GetDefault() override;  // 05
	Feature GetFeature() const override;  // 06
	Type GetType() const override;  // 07
	virtual void OnLoadTextureSet(std::uint64_t a_arg1, BSTextureSet* a_textureSet);  // 08
	virtual void ClearTextures();  // 09
	virtual void ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN);  // 0A
	virtual void GetTextures();  // 0B
	virtual void SaveBinary(NiStream& a_stream);  // 0C
	virtual void LoadBinary(NiStream& a_stream);  // 0D

	// unk38: GUESS(low); opaque base storage, no compared Snow function accesses it directly
	std::uint8_t unk38[0x68];  // 38
};
static_assert(sizeof(BSLightingShaderMaterialBase) == 0xA0, "layout");


class BSLightingShaderMaterialSnow : public BSLightingShaderMaterialBase
{
public:
    BSLightingShaderMaterialSnow();
    virtual ~BSLightingShaderMaterialSnow();  // compared: 0x1529210 (scalar deleting destructor)
    virtual Feature GetFeature() const;  // compared: 0x1528110
    virtual void CopyMembers(BSShaderMaterial* a_src);  // compared: 0x1528090
    BSLightingShaderMaterialSnow* Ctor();  // compared: 0x1527fc0
    virtual std::uint32_t ComputeCRC32();  // compared: 0x15280d0

    struct SnowData {
        void SaveStream(NiStream& a_stream);  // 0xef32b0 (declared only)
        void LoadStream(NiStream& a_stream);  // 0xef31c0 (declared only)
        std::uint64_t first;
        std::uint64_t second;
    };
    void SaveBinary(NiStream& a_stream) override;  // compared: 0x1528120
    void LoadBinary(NiStream& a_stream) override;  // compared: 0x1528160
    SnowData unknownA0;  // A0
};
static_assert(sizeof(BSLightingShaderMaterialSnow) == 0xB0, "BSLightingShaderMaterialSnow size");
