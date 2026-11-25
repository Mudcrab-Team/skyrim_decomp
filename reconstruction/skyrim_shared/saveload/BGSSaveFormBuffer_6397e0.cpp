// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: body adapted from the permitted sibling and checked against the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/SaveGame/Buffers/BGSSaveFormBuffer.cpp:55
// 0x6397e0 BGSSaveFormBuffer::SetHeader
// Adapted bodies: BGSSaveFormBuffer::SetHeader from the sibling source named above
#include "BGSSaveFormBuffer_6397e0.h"

void BGSSaveFormBuffer::SetHeader(std::uint32_t a_formID, BGSChangeFlags a_changeFlags, ENUM_FORM_ID a_formType, std::uint8_t a_version)
{
    header.formIDIndex.SetNumericID(a_formID);
    header.changeFlags = a_changeFlags.flags;
    header.formInfo.SetFormType(a_formType);
    header.version = a_version;
}
