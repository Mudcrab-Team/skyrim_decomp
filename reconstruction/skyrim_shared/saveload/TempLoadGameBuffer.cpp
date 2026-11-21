// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: synthesized from the pinned image's instruction listing and the community class names; no body adapted.
// 0x5ea780 TempLoadGameBuffer::Function5ea780
// Adapted bodies: none.
// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// TempLoadGameBuffer: EXE_RTTI
// GetVersion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x419da0 TempLoadGameBuffer::GetVersion
#include "TempLoadGameBuffer.h"
// BGSLoadGameBuffer::GetVersion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
std::uint8_t TempLoadGameBuffer::GetVersion() const
{
    return 0xff;
}

// 0x5ea780 TempLoadGameBuffer::Function5ea780
// Function5ea780, a_out, formID, ok: GUESS(low); reads a form id, resolves it and writes the reference
bool TempLoadGameBuffer::Function5ea780(TESObjectREFR** a_out)
{
    std::uint32_t formID = 0;
    const bool ok = ReadFormID(formID);
    *a_out = dynamic_cast<TESObjectREFR*>(LookupByID(formID));
    return ok;
}
