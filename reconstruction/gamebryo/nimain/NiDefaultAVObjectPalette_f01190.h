// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; the listing and community declarations only
// NiDefaultAVObjectPalette, SetAVObject: STANDIN EXE_RTTI
// ObjectMapBase, ObjectMapTable, RemoveEntry, InsertEntry, objectsBase, objectsTable: GUESS(low); two helpers the image calls on the palette's name map, at 0x10 and 0x18
#pragma once

#include <cstdint>

class NiAVObject;

class ObjectMapBase
{
public:
	void RemoveEntry(const char* a_name, NiAVObject* const& a_object);
};

class ObjectMapTable
{
public:
	void InsertEntry(const char* a_name, NiAVObject* const& a_object, bool& a_inserted);
};

class NiDefaultAVObjectPalette
{
public:
	void SetAVObject(const char* a_name, NiAVObject* a_object);

	std::uint8_t   unk00[0x10];  // 00
	ObjectMapBase  objectsBase;  // 10
	std::uint8_t   unk11[0x7];   // 11
	ObjectMapTable objectsTable; // 18
};
