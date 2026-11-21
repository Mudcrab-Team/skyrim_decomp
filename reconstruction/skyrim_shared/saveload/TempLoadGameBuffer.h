// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the pinned image listing.
// Code origin: synthesized from the pinned image's instruction listing and the community class names; no body adapted.
// TempLoadGameBuffer: EXE_RTTI
// BGSLoadGameBuffer::GetVersion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
#include "BGSLoadGameBuffer.h"

// TESForm: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI; polymorphic only, so the cast names the image's type descriptor
class TESForm
{
public:
    virtual ~TESForm();
};

// TESObjectREFR: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
class TESObjectREFR : public TESForm
{
};

// TempLoadGameBuffer: EXE_RTTI; derives from the load buffer whose ReadFormID it calls
class TempLoadGameBuffer : public BGSLoadGameBuffer
{
public:
    // BGSLoadGameBuffer::GetVersion: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
    virtual std::uint8_t GetVersion() const;

    // Function5ea780, a_out, formID, ok: GUESS(low); reads a form id, resolves it and writes the reference
    bool Function5ea780(TESObjectREFR** a_out);

    // TESForm::LookupByID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG declares it on TESForm, redeclared here because TESForm.h is outside this unit's include set
    static TESForm* LookupByID(std::uint32_t a_formID);
};
