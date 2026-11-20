// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// BSLightingShaderMaterialEnvmap, BSLightingShaderMaterialBase, BSShaderMaterial: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiPointer, NiSourceTexture: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include <cstddef>
#include <cstdint>

class NiSourceTexture;

// NiPointer: _ptr keeps NG's default member initializer, so a default-constructed pointer is
// set by its own constructor rather than value-initialised
template <class T>
class NiPointer
{
public:
	T* _ptr{ nullptr };  // 00
};

// MemoryManager, g_memoryManager, g_memoryManagerGuard, InitMemoryManager, Allocate: GUESS(low); the allocator object and its once-init guard
class MemoryManager
{
public:
	void* Allocate(std::uint32_t a_size, std::int32_t a_alignment, bool a_alignmentRequired);
};
extern MemoryManager g_memoryManager;
extern std::int32_t  g_memoryManagerGuard;
void InitMemoryManager(MemoryManager* a_manager, std::int32_t* a_guard);

// sizeof BSShaderMaterial 0x38, sizeof BSLightingShaderMaterialBase 0xA0: OBSERVED; members not used here are padding
class BSShaderMaterial
{
public:
	virtual ~BSShaderMaterial();  // 00
	virtual BSShaderMaterial* Create();  // 01

	std::uint8_t unk08[0x30];  // 08
};
static_assert(sizeof(BSShaderMaterial) == 0x38, "layout");

class BSLightingShaderMaterialBase : public BSShaderMaterial
{
public:
	BSLightingShaderMaterialBase();
	~BSLightingShaderMaterialBase() override;

	std::uint8_t unk38[0x68];  // 38
};
static_assert(sizeof(BSLightingShaderMaterialBase) == 0xA0, "layout");

// envTexture, envMaskTexture, envMapScale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG's members at the same offsets
// operator new: GUESS(low); the class allocates from the engine heap, and a failed construction frees through the global sized delete
class BSLightingShaderMaterialEnvmap : public BSLightingShaderMaterialBase
{
public:
	static void* operator new(std::size_t a_size)
	{
		if (g_memoryManagerGuard != 2) {
			InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
		}
		return g_memoryManager.Allocate(static_cast<std::uint32_t>(a_size), 0, false);
	}

	BSLightingShaderMaterialEnvmap();
	~BSLightingShaderMaterialEnvmap() override;
	BSShaderMaterial* Create() override;  // 01

	NiPointer<NiSourceTexture> envTexture;      // A0
	NiPointer<NiSourceTexture> envMaskTexture;  // A8
	float                      envMapScale;     // B0
	std::uint32_t              padB4;           // B4
};
static_assert(sizeof(BSLightingShaderMaterialEnvmap) == 0xB8, "layout");
