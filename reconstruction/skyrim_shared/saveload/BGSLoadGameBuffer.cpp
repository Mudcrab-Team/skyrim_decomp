// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image and the class layout in the header beside this file. A byte match shows that this source and recipe produce the checked code; it does not verify the community names.
// 0x637a90 BGSLoadGameBuffer::GetVersion
// 0x637ab0 BGSLoadGameBuffer::ReadFormID
#include "BGSLoadGameBuffer.h"

#include <cstring>
#include <cstdint>

std::uint8_t BGSLoadGameBuffer::GetVersion()
{
	return gBGSSaveLoadGame->QueryState();
}

bool BGSLoadGameBuffer::ReadFormID(std::uint32_t& a_formID)
{
	BGSNumericIDIndex index;
	const std::uint32_t position = bufferPosition;
	const std::uint8_t* src = static_cast<const std::uint8_t*>(buffer) + position;
	// the index is read as a 16-bit pair then a byte, which is how the target copies its 3 bytes
	std::memcpy(&index, src, 2);
	std::memcpy(&index.data3, src + 2, 1);
	bufferPosition = position + 3;
	a_formID = index.GetNumericID();
	const bool empty = index.data1 == 0 && index.data2 == 0 && index.data3 == 0;
	return !empty && a_formID == 0;
}
