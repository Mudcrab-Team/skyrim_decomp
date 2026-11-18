// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"meh321/AddressLibraryDatabase","revision":"0379cb6fdaa0d68e69ef9ad1a2d39caa6611ac91","source":"meh321"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSWaterShaderMaterial: EXE_RTTI
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// member, padding: GUESS(low); storage names invented for the measured member offset
#pragma once
#include <cstdint>
// GetType: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
class BSWaterShaderMaterial
{
public:
    // BSWaterShaderMaterial::BSWaterShaderMaterial: GUESS(low); defined so the vftable and the deleting destructor are emitted
    BSWaterShaderMaterial();
    // BSWaterShaderMaterial::~BSWaterShaderMaterial: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the listing calls the complete destructor, so this one is declared only
    virtual ~BSWaterShaderMaterial();
    // BSWaterShaderMaterial::GetDefault: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); returns the global default material, bound by address through bind-hints.json
    static BSWaterShaderMaterial* GetDefault();
    virtual std::uint32_t GetType() const;

    // unk08: GUESS(low); padding up to the 0x180-byte size the deleting destructor passes to operator delete
    std::uint8_t unk08[0x180 - 0x08];
};
static_assert(sizeof(BSWaterShaderMaterial) == 0x180, "BSWaterShaderMaterial size");

// g_BSWaterShaderMaterialDefault: GUESS(low); the global pointer at RVA 0x34868f0 that GetDefault reads
extern BSWaterShaderMaterial* g_BSWaterShaderMaterialDefault;
