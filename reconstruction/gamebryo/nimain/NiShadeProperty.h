// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// NiShadeProperty: EXE_RTTI
// SetupGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>

class BSGeometry;
// SetupGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiShadeProperty
{
public:
    virtual std::uint8_t SetupGeometry() const;
    // FinishSetupGeometry, GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); signatures from the sheets, not checked against the community header
    virtual bool FinishSetupGeometry(BSGeometry* a_geometry);
    // Unk_29: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); slot 29
    virtual void Unk_29();
    // Type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); a 32-bit enumeration, the return width is all the compared code reads
    enum class Type : std::uint32_t {};
    virtual Type GetType() const;
};
