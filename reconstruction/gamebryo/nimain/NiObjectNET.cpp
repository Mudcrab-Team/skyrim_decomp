// Source exposure: mixed. Drafted by claude-sonnet-5-5 from local instruction listings of the
// pinned image, with names and types from the header beside this file.
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/niobjectnet.cpp:54
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/niobjectnet.cpp:85
// LoadFixedString, LoadStep1, LoadStep2, SaveFixedString below: GUESS(low); the image gives these
// stream helpers no community name.
// 0xeeb940 NiObjectNET::ctor
// 0xeea6c0 NiObjectNET::LoadBinary
// 0xeeb8c0 NiObjectNET::ProcessClone
// 0xeea7b0 NiObjectNET::RegisterStreamables
// 0xeea880 NiObjectNET::SaveBinary
#include "NiObjectNET.h"

// Stream helpers without community names; free functions taking the stream first.
// LoadFixedString: GUESS(low)
void LoadFixedString(NiStream& a_stream, BSFixedString& a_out);
// LoadStep1, LoadStep2: GUESS(low)
void LoadStep1(NiStream& a_stream);
void LoadStep2(NiStream& a_stream);
// SaveFixedString: GUESS(low)
void SaveFixedString(NiStream& a_stream, const BSFixedString& a_in);

NiObjectNET::NiObjectNET()
{
	name = {};
	controllers.pointer = nullptr;
	extra = nullptr;
	extraDataSize = 0;
	maxSize = 0;
}

void NiObjectNET::LoadBinary(NiStream& a_stream)
{
	NiObject::LoadBinary(a_stream);
	LoadFixedString(a_stream, name);
	LoadStep1(a_stream);
	LoadStep2(a_stream);
}

void NiObjectNET::ProcessClone(NiCloningProcess& a_cloning)
{
	NiObject::ProcessClone(a_cloning);

	for (std::uint16_t i = 0; i < extraDataSize; ++i) {
		NiExtraData* data = extra[i];
		if (data) {
			data->ProcessClone(a_cloning);
		}
	}

	NiTimeController* controller = controllers.pointer;
	if (controller) {
		controller->ProcessClone(a_cloning);
	}
}

bool NiObjectNET::RegisterStreamables(NiStream& a_stream)
{
	if (!NiObject::RegisterStreamables(a_stream)) {
		return false;
	}
	if (!a_stream.RegisterFixedString(name)) {
		return false;
	}

	for (std::uint16_t i = 0; i < extraDataSize; ++i) {
		NiExtraData* data = extra[i];
		if (data && data->IsStreamable()) {
			data->RegisterStreamables(a_stream);
		}
	}

	NiTimeController* controller = controllers.pointer;
	if (controller) {
		controller->RegisterStreamables(a_stream);
	}
	return true;
}

void NiObjectNET::SaveBinary(NiStream& a_stream)
{
	NiObject::SaveBinary(a_stream);
	SaveFixedString(a_stream, name);

	std::uint32_t streamable = 0;
	for (std::uint16_t i = 0; i < extraDataSize; ++i) {
		if (extra[i]->IsStreamable()) {
			++streamable;
		}
	}
	std::uint32_t size = 4;
	a_stream.oStr->WriteBytes(&streamable, 4, &size, 1);

	for (std::uint16_t i = 0; i < extraDataSize; ++i) {
		NiExtraData* data = extra[i];
		if (data->IsStreamable()) {
			a_stream.SaveLinkID(data);
		}
	}

	NiTimeController* controller = controllers.pointer;
	while (controller && !controller->IsStreamable()) {
		controller = controller->next.pointer;
	}
	a_stream.SaveLinkID(controller);
}
