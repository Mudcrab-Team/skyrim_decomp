// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with the class layout from the header beside this file.
// 0x4b4ad0 BSLightingShaderMaterialBase::GetType
// 0x1523d10 BSLightingShaderMaterialBase::GetDefault
// 0x1523f00 BSLightingShaderMaterialBase::ReceiveValuesFromRootMaterial
// 0x1524030 BSLightingShaderMaterialBase::SaveBinary
// 0x15241d0 BSLightingShaderMaterialBase::LoadBinary
#include "BSLightingShaderMaterialBase.h"

BSLightingShaderMaterialBase::Type BSLightingShaderMaterialBase::GetType() const
{
	return Type::kLighting;
}

BSShaderMaterial* BSLightingShaderMaterialBase::GetDefault()
{
	return g_defaultLightingMaterial;
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

// constructor: GUESS(low)
BSLightingShaderMaterialBase::BSLightingShaderMaterialBase() {}

// GetFeature: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
BSLightingShaderMaterialBase::Feature BSLightingShaderMaterialBase::GetFeature() const
{
	return Feature::kDefault;
}
