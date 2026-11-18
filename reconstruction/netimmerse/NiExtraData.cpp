// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// NiExtraData::NiExtraData: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); name only, not compared
// 0xef9880 NiExtraData::LoadBinary
// 0xef9960 NiExtraData::IsEqual
// 0xef98d0 NiExtraData::RegisterStreamables
// 0xef9c50 NiExtraData::~NiExtraData
#include "NiExtraData.h"

NiExtraData::NiExtraData()
{
}

NiExtraData::~NiExtraData()
{
}

void NiExtraData::LoadBinary(NiStream& a_stream)
{
	NiObject::LoadBinary(a_stream);
	a_stream.LoadFixedString(name);
}

bool NiExtraData::RegisterStreamables(NiStream& a_stream)
{
	if (NiObject::RegisterStreamables(a_stream) && a_stream.RegisterFixedString(name)) {
		return true;
	}
	return false;
}

// LinkObject, IsStreamable, IsCloneable: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
void NiExtraData::LinkObject(NiStream& a_stream)
{
}

bool NiExtraData::IsStreamable() const
{
	return true;
}

bool NiExtraData::IsCloneable() const
{
	return true;
}

bool NiExtraData::IsEqual(NiObject* a_object)
{
	if (NiObject::IsEqual(a_object) && name._data == static_cast<NiExtraData*>(a_object)->name._data) {
		return true;
	}
	return false;
}
