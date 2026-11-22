// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// NiBlendTransformInterpolator: EXE_RTTI
// IsTransformValueSupported: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
// InterpolatorIsCorrectType: SIBLING(momusdigital/fnv_decomp@91e1b6e8, no-licence); FNV names the other blend interpolators' functions NiBlend*Interpolator_InterpolatorIsCorrectType
#pragma once
#include <cstdint>
// IsTransformValueSupported: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// NiInterpolator::IsTransformValueSupported: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG slot 30
// NiInterpolator: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Slot00 to Slot2F: GUESS(low); placeholders so IsTransformValueSupported lands on slot 0x30
class NiInterpolator
{
public:
    virtual void Slot00(); virtual void Slot01(); virtual void Slot02(); virtual void Slot03(); virtual void Slot04(); virtual void Slot05(); virtual void Slot06(); virtual void Slot07();
    virtual void Slot08(); virtual void Slot09(); virtual void Slot0A(); virtual void Slot0B(); virtual void Slot0C(); virtual void Slot0D(); virtual void Slot0E(); virtual void Slot0F();
    virtual void Slot10(); virtual void Slot11(); virtual void Slot12(); virtual void Slot13(); virtual void Slot14(); virtual void Slot15(); virtual void Slot16(); virtual void Slot17();
    virtual void Slot18(); virtual void Slot19(); virtual void Slot1A(); virtual void Slot1B(); virtual void Slot1C(); virtual void Slot1D(); virtual void Slot1E(); virtual void Slot1F();
    virtual void Slot20(); virtual void Slot21(); virtual void Slot22(); virtual void Slot23(); virtual void Slot24(); virtual void Slot25(); virtual void Slot26(); virtual void Slot27();
    virtual void Slot28(); virtual void Slot29(); virtual void Slot2A(); virtual void Slot2B(); virtual void Slot2C(); virtual void Slot2D(); virtual void Slot2E(); virtual void Slot2F();
    virtual bool IsTransformValueSupported() const;  // 30
};

class NiBlendTransformInterpolator
{
public:
    virtual std::uint8_t IsTransformValueSupported() const;
    bool InterpolatorIsCorrectType(NiInterpolator* a_interpolator) const;
};
