// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
// 0x1525270 BSLightingShaderMaterialEye::Create
// 0x1525770 BSLightingShaderMaterialEye::SaveBinary
// 0x15257f0 BSLightingShaderMaterialEye::LoadBinary
// 0x1525640 BSLightingShaderMaterialEye::ReceiveValuesFromRootMaterial
// 0x15250e0 BSLightingShaderMaterialEye::Ctor
// 0x15255c0 BSLightingShaderMaterialEye::ClearTextures
// 0x15253e0 BSLightingShaderMaterialEye::ComputeCRC32
// Code origin: bodies written from local listings of the pinned image; names and declarations follow CommonLibSSE-NG; the reference-count release spelling follows cookbook rule 29.
#include "BSLightingShaderMaterialEye.h"

// componentSize: GUESS(low)
void BSLightingShaderMaterialEye::SaveBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::SaveBinary(a_stream);
    { std::uint32_t componentSize = 4;
    a_stream.oStr->binary_write(&unkB0, 4, &componentSize); }
    colorB4.SaveBinary2(a_stream);
    return colorC0.SaveBinary2(a_stream);
}
// componentSize: GUESS(low)
void BSLightingShaderMaterialEye::LoadBinary(NiStream& a_stream)
{
    BSLightingShaderMaterialBase::LoadBinary(a_stream);
    { std::uint32_t componentSize = 4;
    a_stream.iStr->binary_read(&unkB0, 4, &componentSize); }
    colorB4.LoadBinary2(a_stream);
    return colorC0.LoadBinary2(a_stream);
}


// Accepted leaf retained from the integrated version.
// GetFeature: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
BSShaderMaterial::Feature BSLightingShaderMaterialEye::GetFeature() const
{
    return static_cast<Feature>(0x10);
}

// Additional bodies drafted by gpt-6.1-sol from the assigned pack.
// envMask, cubemap: GUESS(low); candidate references to shared default textures.
void BSLightingShaderMaterialEye::ReceiveValuesFromRootMaterial(bool a_skinned, bool a_rimLighting, bool a_softLighting, bool a_backLighting, bool a_MSN, std::uintptr_t a_extra1, std::uintptr_t a_extra2)
{
    BSLightingShaderMaterialBase::ReceiveValuesFromRootMaterial(a_skinned, a_rimLighting, a_softLighting, a_backLighting, a_MSN, a_extra1, a_extra2);
    if (!eyeEnvMask._ptr) {
        NiSourceTexture* envMask = g_defaultEnvMask;
        if (envMask) { envMask->IncRefCount(); eyeEnvMask._ptr = envMask; }
    }
    if (!eyeCubemap._ptr) {
        NiSourceTexture* cubemap = g_defaultCubemap;
        if (cubemap) { cubemap->IncRefCount(); eyeCubemap._ptr = cubemap; }
    }
}

BSLightingShaderMaterialEye::BSLightingShaderMaterialEye() : eyeEnvMask{}, eyeCubemap{}, unkB0(1.0f), colorB4(), colorC0()
{
    colorB4.red = NiPoint3::Zero.x;
    colorB4.green = NiPoint3::Zero.y;
    colorB4.blue = NiPoint3::Zero.z;
    colorC0.red = NiPoint3::Zero.x;
    colorC0.green = NiPoint3::Zero.y;
    colorC0.blue = NiPoint3::Zero.z;
}


void* BSLightingShaderMaterialEye::operator new(std::size_t a_size) throw()
{
    if (g_memoryManagerGuard != 2) {
        InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
    }
    return g_memoryManager.Allocate(static_cast<std::uint32_t>(a_size), 0, false);
}

BSShaderMaterial* BSLightingShaderMaterialEye::Create()
{
    return new BSLightingShaderMaterialEye;
}

void BSLightingShaderMaterialEye::ClearTextures()
{
    BSLightingShaderMaterialBase::ClearTextures();
    eyeEnvMask = nullptr;
    eyeCubemap = nullptr;
}

// BSTextureSet: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk00, unk01, unk02, unk03, unk04, unk05, unk06, unk07, unk08, unk09, unk0A, unk0B, unk0C, unk0D, unk0E, unk0F, unk10, unk11, unk12, unk13, unk14, unk15, unk16, unk17, unk18, unk19, unk1A, unk1B, unk1C, unk1D, unk1E, unk1F, unk20, unk21, unk22, unk23, unk24: GUESS(low); placeholders before slot 0x25
// GetCRCSource: GUESS(low); slot 0x25, its result is hashed by SizeOf32
class BSTextureSet
{
public:
    virtual void unk00();
    virtual void unk01();
    virtual void unk02();
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual void unk07();
    virtual void unk08();
    virtual void unk09();
    virtual void unk0A();
    virtual void unk0B();
    virtual void unk0C();
    virtual void unk0D();
    virtual void unk0E();
    virtual void unk0F();
    virtual void unk10();
    virtual void unk11();
    virtual void unk12();
    virtual void unk13();
    virtual void unk14();
    virtual void unk15();
    virtual void unk16();
    virtual void unk17();
    virtual void unk18();
    virtual void unk19();
    virtual void unk1A();
    virtual void unk1B();
    virtual void unk1C();
    virtual void unk1D();
    virtual void unk1E();
    virtual void unk1F();
    virtual void unk20();
    virtual void unk21();
    virtual void unk22();
    virtual void unk23();
    virtual void unk24();
    virtual std::uint64_t GetCRCSource(std::uint32_t a_index);
};

// CRC32SizeOf32, CRC32SizeOfSize: GUESS(low); after CommonLibSSE-NG's CRC32Calculator::SizeOf32 and SizeOfSize
// EyeFlagHash: GUESS(low); the base helper that hashes the flag word
void CRC32SizeOf32(std::uint32_t* a_out, std::uint64_t a_value, std::uint32_t a_seed);  // 0xce2240
void CRC32SizeOfSize(std::uint32_t* a_out, const void* a_data, std::uint32_t a_size);  // 0xce2510
std::uint32_t EyeFlagHash(BSLightingShaderMaterialBase* a_self, std::uint32_t a_flags);  // 0x1523a30

// EyeCrcRecord: GUESS(low); the 0x28-byte record hashed by ComputeCRC32
struct EyeCrcRecord
{
    std::uint32_t ids[2];    // 00
    float         unkB0;     // 08
    NiColor       colorB4;   // 0C
    NiColor       colorC0;   // 18
    std::uint32_t flagHash;  // 24
};
static_assert(sizeof(EyeCrcRecord) == 0x28, "EyeCrcRecord size");

std::uint32_t BSLightingShaderMaterialEye::ComputeCRC32(std::uint32_t a_crcSeed)
{
    EyeCrcRecord record;
    if (textureSet._ptr) {
        CRC32SizeOf32(&record.ids[0], textureSet._ptr->GetCRCSource(4), 0);
        CRC32SizeOf32(&record.ids[1], textureSet._ptr->GetCRCSource(5), 0);
    }
    else {
        record.ids[0] = 0;
        record.ids[1] = 0;
    }
    record.unkB0 = unkB0;
    record.colorB4.red = colorB4.red;
    record.colorB4.green = colorB4.green;
    record.colorB4.blue = colorB4.blue;
    record.colorC0.red = colorC0.red;
    record.colorC0.green = colorC0.green;
    record.colorC0.blue = colorC0.blue;
    record.flagHash = EyeFlagHash(this, a_crcSeed);
    std::uint32_t out;
    CRC32SizeOfSize(&out, &record, sizeof(record));
    return out;
}
