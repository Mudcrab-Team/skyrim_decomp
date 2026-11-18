// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/fallout_shared/tempeffects/bstempeffect.cpp:70
// BSTempEffect::Initialize: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence)
// Bodies adapted from community sources are listed above; tools/check_origin.py reports none
// 0x4a9fd0 BSTempEffect::Initialize
// 0x4a9fc0 BSTempEffect::GetType
// 0x4a9910 BSTempEffect::Update
// 0x4a9f20 BSTempEffect::~BSTempEffect
// 0x4a99e0 BSTempEffect::LoadGame
// 0x4a9860 BSTempEffect::ctor
// 0x4a9940 BSTempEffect::SaveGame
#include "BSTempEffect.h"

volatile long NiRefObject::ms_totalObjects;
std::uint32_t BSTempEffect::ms_nextEffectID;

BSTempEffect::BSTempEffect(TESObjectCELL* a_cell, float a_lifetime)
{
	lifetime = a_lifetime;
	cell = a_cell;
	age = 0.0f;
	initialized = false;
	effectID = ms_nextEffectID;
	if (++ms_nextEffectID == 0xFFFFFFFF) {
		ms_nextEffectID = 1;
	}
}

BSTempEffect::~BSTempEffect()
{
	cell = nullptr;
	lifetime = 0.0f;
	age = 0.0f;
	initialized = false;
}

void BSTempEffect::Initialize()
{
	initialized = true;
}

TEMP_EFFECT_TYPE BSTempEffect::GetType() const
{
	return TEMP_EFFECT_TYPE::kDefault;
}

bool BSTempEffect::Update(float a_arg1)
{
	age += a_arg1;
	return !(age > lifetime);
}

void BSTempEffect::SaveGame(BGSSaveGameBuffer* a_buf)
{
	a_buf->SaveDataEndian(&lifetime, sizeof(lifetime), 4, 0);
	a_buf->SaveDataEndian(&age, sizeof(age), 4, 0);
	a_buf->SaveDataEndian(&initialized, sizeof(initialized), 1, 0);
	a_buf->SaveDataEndian(&effectID, sizeof(effectID), 4, 0);
}

void BSTempEffect::LoadGame(BGSLoadGameBuffer* a_buf)
{
	a_buf->LoadDataEndian(&lifetime, 4, 4);
	a_buf->LoadDataEndian(&age, 4, 4);
	a_buf->LoadDataEndian(&initialized, 1, 1);
	a_buf->LoadDataEndian(&effectID, 4, 4);
}

// FinishLoadGame, IsInterfaceEffect: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void BSTempEffect::FinishLoadGame(BGSLoadGameBuffer* a_buf)
{
}

bool BSTempEffect::IsInterfaceEffect() const
{
	return false;
}

// Get3D: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
NiAVObject* BSTempEffect::Get3D() const
{
	return nullptr;
}
