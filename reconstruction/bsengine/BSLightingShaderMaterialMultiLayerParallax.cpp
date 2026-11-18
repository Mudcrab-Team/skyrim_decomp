// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1529070 BSLightingShaderMaterialMultiLayerParallax::~BSLightingShaderMaterialMultiLayerParallax
// 0x15281a0 BSLightingShaderMaterialMultiLayerParallax::Ctor
// 0x1528820 BSLightingShaderMaterialMultiLayerParallax::GetTextures
// 0x1528770 BSLightingShaderMaterialMultiLayerParallax::ReceiveValuesFromRootMaterial
// 0x15284c0 BSLightingShaderMaterialMultiLayerParallax::ComputeCRC32
// 0x15288d0 BSLightingShaderMaterialMultiLayerParallax::SaveBinary
// 0x1528a00 BSLightingShaderMaterialMultiLayerParallax::LoadBinary
#include <cstring>

#include "BSLightingShaderMaterialMultiLayerParallax.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared.
BSLightingShaderMaterialMultiLayerParallax::BSLightingShaderMaterialMultiLayerParallax()
{
}



// RVA 0x1528770, 163 bytes.
void BSLightingShaderMaterialMultiLayerParallax::ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, void* a_extra7, void* a_extra8)
{
	BaseReceiveValues(this, a_skinned, a_rimLighting, a_softLighting, a_backLighting, a_MSN, a_extra7, a_extra8);
	if (m_texA0 == nullptr) {
		NiSourceTexture* defaultTexture = g_defaultTexture._ptr;
		if (defaultTexture) {
			defaultTexture->IncRefCount();
			m_texA0 = defaultTexture;
		}
	}
	if (m_texA8 == nullptr) {
		NiSourceTexture* defaultMulti = g_defaultMultiLayerTexture._ptr;
		if (defaultMulti) {
			defaultMulti->IncRefCount();
			m_texA8 = defaultMulti;
		}
	}
	if (m_texB0 == nullptr) {
		NiSourceTexture* defaultTexture = g_defaultTexture._ptr;
		if (defaultTexture) {
			defaultTexture->IncRefCount();
			m_texB0 = defaultTexture;
		}
	}
}




// Retained generated leaf; its byte-match evidence is renewed with this unit.
// GetFeature: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
BSShaderMaterial::Feature BSLightingShaderMaterialMultiLayerParallax::GetFeature() const
{
    return static_cast<Feature>(0xb);
}
