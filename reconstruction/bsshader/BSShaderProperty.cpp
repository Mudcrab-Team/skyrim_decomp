// Code origin: original; the listing and community declarations only
// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Function14e77f0, Function14e7a80, SetNextPass: GUESS(low); bodies written from the local listing
// 0x14e77f0 BSShaderProperty::Function14e77f0
// 0x14e7a80 BSShaderProperty::Function14e7a80
// 0x14e85f0 BSShaderProperty::ForEachTexture
// 0x14e8680 BSShaderProperty::QMaterialAlpha
// 0x14e7fb0 BSShaderProperty::DoClearRenderPasses
// 0x14e7ef0 BSShaderProperty::SetFlags
// 0x14e7450 BSShaderProperty::SaveBinary
// 0x14e7390 BSShaderProperty::LoadBinary
#include "BSShaderProperty.h"

#include <climits>

float BSShaderProperty::QMaterialAlpha()
{
	return 1.0f;
}

std::int32_t BSShaderProperty::ForEachTexture(ForEachVisitor&)
{
	return 1;
}

void BSShaderProperty::DoClearRenderPasses()
{
	for (BSRenderPass* pass = renderPassList.head; pass;) {
		BSRenderPass* next = pass->next;
		pass->ClearRenderPass();
		pass = next;
	}
	lastRenderPassState = INT_MAX;
	renderPassList.head = nullptr;
}

void BSShaderProperty::SetFlags(EShaderPropertyFlag8 a_flag, bool a_set)
{
	const std::uint64_t bit = std::uint64_t(1) << static_cast<std::uint32_t>(a_flag);
	if (a_set) {
		if (!(flags & bit)) {
			lastRenderPassState = INT_MAX;
		}
		flags |= bit;
	} else {
		if (flags & bit) {
			lastRenderPassState = INT_MAX;
		}
		flags &= ~bit;
	}
}

void BSShaderProperty::LoadBinary(NiStream& a_stream)
{
	BSShaderMaterial* mat = material;
	NiShadeProperty::LoadBinary(a_stream);
	NiBinaryStream* in = a_stream.iStr;
	std::uint32_t componentSize = 8;
	in->binary_read(&flags, 8, &componentSize, 1);
	mat->texCoordOffset[0].LoadBinary(a_stream);
	mat->texCoordScale[0].LoadBinary(a_stream);
	mat->texCoordOffset[1] = mat->texCoordOffset[0];
	mat->texCoordScale[1] = mat->texCoordScale[0];
}

void BSShaderProperty::SaveBinary(NiStream& a_stream)
{
	NiShadeProperty::SaveBinary(a_stream);
	{
		NiBinaryStream* out = a_stream.oStr;
		std::uint32_t componentSize = 8;
		out->binary_write(&flags, 8, &componentSize, 1);
	}
	material->texCoordOffset[0].SaveBinary(&a_stream);
	material->texCoordScale[0].SaveBinary(&a_stream);
}

void BSShaderProperty::Function14e77f0(RenderPassArray* a_array)
{
	for (BSRenderPass* pass = a_array->head; pass;) {
		BSRenderPass* next = pass->next;
		pass->ClearRenderPass();
		pass = next;
	}
	a_array->head = nullptr;
}

BSRenderPass* BSShaderProperty::Function14e7a80(RenderPassArray* a_array, BSRenderPass** a_other)
{
	BSRenderPass* pass = a_array->head;
	a_array->head = pass->next;
	pass->SetNextPass(*a_other);
	*a_other = pass;
	return pass;
}
