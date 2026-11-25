// Near miss: 0.0% | other
// BSLightingShaderMaterialBase member functions, build sse-steam-1-7-104.
//
// RVA 0x4b4ad0, 6 bytes (GetType); RVA 0x1523d10, 8 bytes (GetDefault);
// RVA 0x1523e50, 163 bytes (ClearTextures); RVA 0x1523f00, 191 bytes (ReceiveValuesFromRootMaterial);
// RVA 0x1523d20, 286 bytes (OnLoadTextureSet); RVA 0x15237e0, 384 bytes (CopyMembers);
// Source exposure: mixed
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x1523d20 BSLightingShaderMaterialBase::OnLoadTextureSet

#include "include/1523d20/BSLightingShaderMaterialBase.h"

BSLightingShaderMaterialBase::Type BSLightingShaderMaterialBase::GetType() const
{
	return Type::kLighting;
}

BSShaderMaterial* BSLightingShaderMaterialBase::GetDefault()
{
	return g_defaultLightingMaterial;
}

void BSLightingShaderMaterialBase::ClearTextures()
{
	diffuseTexture.reset();
	normalTexture.reset();
	rimSoftLightingTexture.reset();
	specularBackLightingTexture.reset();
}

void BSLightingShaderMaterialBase::ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN)
{
	if (!diffuseTexture) {
		diffuseTexture = g_defaultTexture;
	}
	if (!normalTexture) {
		normalTexture = g_defaultTexture;
	}
	if (a_rimLighting && !rimSoftLightingTexture) {
		rimSoftLightingTexture = g_defaultTexture;
	}
	if (a_softLighting && !rimSoftLightingTexture) {
		rimSoftLightingTexture = g_defaultTexture;
	}
	if (a_backLighting && !specularBackLightingTexture) {
		specularBackLightingTexture = g_defaultTexture;
	}
	if (a_skinned && a_MSN && !specularBackLightingTexture) {
		specularBackLightingTexture = g_defaultBackLightingTexture;
	}
}

// Scoped spin lock: the destructor makes OnLoadTextureSet an exception-handling function
class BSLightingShaderMaterialLockGuard
{
public:
	explicit BSLightingShaderMaterialLockGuard(BSNonReentrantSpinLock& a_lock) :
		_lock(&a_lock)
	{
		_lock->Lock();
	}

	~BSLightingShaderMaterialLockGuard()
	{
		if (_lock) {
			_lock->Unlock();
		}
	}

private:
	BSNonReentrantSpinLock* _lock;
};

void BSLightingShaderMaterialBase::OnLoadTextureSet(std::uint64_t, BSTextureSet* a_textureSet)
{
	BSLightingShaderMaterialLockGuard guard(lock98);

	if (diffuseTexture.get() == g_defaultTexture.get() || !diffuseTexture) {
		if (a_textureSet && textureSet.get() != a_textureSet) {
			textureSet.reset(a_textureSet);
		}
		BSTextureSet* set = textureSet.get();
		if (set) {
			set->SetTexture(BSTextureSet::kDiffuse, diffuseTexture);
			set->SetTexture(BSTextureSet::kNormal, normalTexture);
			set->SetTexture(BSTextureSet::kEnvironmentMask, rimSoftLightingTexture);
			set->SetTexture(BSTextureSet::kBacklightMask, specularBackLightingTexture);
		}
	}
}

void BSLightingShaderMaterialBase::CopyMembers(BSShaderMaterial* a_other)
{
	BSShaderMaterial::CopyMembers(a_other);
	auto* other = static_cast<BSLightingShaderMaterialBase*>(a_other);
	diffuseTexture = other->diffuseTexture;
	normalTexture = other->normalTexture;
	rimSoftLightingTexture = other->rimSoftLightingTexture;
	specularBackLightingTexture = other->specularBackLightingTexture;
	textureClampMode = other->textureClampMode;
	textureSet = other->textureSet;
	materialAlpha = other->materialAlpha;
	specularPower = other->specularPower;
	specularColor = other->specularColor;
	specularColorScale = other->specularColorScale;
	refractionPower = other->refractionPower;
	subSurfaceLightRolloff = other->subSurfaceLightRolloff;
	rimLightPower = other->rimLightPower;
}

void BSLightingShaderMaterialBase::SaveBinary(NiStream& a_stream)
{
	a_stream.oStr->write(&textureClampMode, 1);
	a_stream.oStr->write(&materialAlpha, 1);
	a_stream.oStr->write(&refractionPower, 1);
	a_stream.oStr->write(&specularPower, 1);
	specularColor.SaveBinary2(a_stream);
	a_stream.oStr->write(&specularColorScale, 1);
	a_stream.oStr->write(&subSurfaceLightRolloff, 1);
	a_stream.oStr->write(&rimLightPower, 1);
}

void BSLightingShaderMaterialBase::LoadBinary(NiStream& a_stream)
{
	a_stream.iStr->read(&textureClampMode, 1);
	a_stream.iStr->read(&materialAlpha, 1);
	a_stream.iStr->read(&refractionPower, 1);
	a_stream.iStr->read(&specularPower, 1);
	specularColor.LoadBinary2(a_stream);
	a_stream.iStr->read(&specularColorScale, 1);
	a_stream.iStr->read(&subSurfaceLightRolloff, 1);
	a_stream.iStr->read(&rimLightPower, 1);
}
