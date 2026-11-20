// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// 0xf01190 NiDefaultAVObjectPalette::SetAVObject
#include "NiDefaultAVObjectPalette_f01190.h"

void NiDefaultAVObjectPalette::SetAVObject(const char* a_name, NiAVObject* a_object)
{
	if (!a_object) {
		objectsBase.RemoveEntry(a_name, a_object);
		return;
	}
	bool inserted;
	objectsTable.InsertEntry(a_name, a_object, inserted);
}
